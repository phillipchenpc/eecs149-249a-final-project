"""
Main intersection logic containing: 1) Camera connection, 2) Bluetooth commands
BIG ASSUMPTIONS: for simpler logic 
* Camera will be aligned with intersection such that the vehicles travel perpendicular and parallel to the x- and y axes
* Pololus will come from the left side and bottom of the frame

Dec. 2025
"""
#############
## Imports ##
#############

# For bluetooth
import asyncio
from bleak import BleakScanner, BleakClient

# For Camera and Aruco Tags
import cv2 as cv
import numpy as np
import time
import math


############################
## Find Bluetooth Devices ##
############################
async def ble_scan():
    # print("Scanning for BLE devices...")
    # devices = await BleakScanner.discover()

    # if not devices:
    #     print("No BLE devices found.")
    #     return

    # print("\nFound BLE devices:")
    # # Construct a dictionary of device name to address
    # device_dict = {}
    # for d in devices:
    #     device_dict[d.name] = d.address
    #     # print(f"- Name: {d.name}, Address: {d.address}")

    #############################
    ## Select Bluetooth Device ##
    #############################
    train_addr, ev_addr = "E128559E-6F91-E6B3-FD39-BE28507ED666", "77F101C0-5D65-0C2D-23CC-728BCD3C06F4"
    train_name, ev_name = "149_G14_Train", "149_G14_EV"
    # while train_name not in device_dict.keys():
    #     train_name = input("Type the exact name of the device to use for the light-rail train: ")
    # while ev_name not in device_dict.keys():
    #     ev_name = input("Type the exact name of the device to use for the Emergency Vehicle: ")
    # Match the names to the addresses
    # train_addr = device_dict[train_name]
    # ev_addr = device_dict[ev_name]

    return train_addr, ev_addr

###############
## Constants ##
###############
UUID = "0000ffe1-0000-1000-8000-00805f9b34fb" # Specific HM-10 Bluetooth firmware
# Vehicle Dynamics
TRAIN_SPEED = 5.8333 # in cm/s
TRAIN_ACCEL = 0.65 # in cm / s**2
TRAIN_DECEL = 0.8 # in cm / s**2
TRAIN_STOP_DIST = 21.2674 # in cm
TRAIN_LENGTH = 40.95 # cm
TRAIN_INTERSECT_TIME = 8.56285 # in seconds. TIme it takes for train to cross intersection

EV_SPEED = 6.6667 # in cm/s
EV_ACCEL = 0.3194 # in cm / s**2
EV_DECEL = 0.7882 # in cm / s**2
EV_STOP_DIST = 28.194 # in cm
EV_LENGTH = 9 # Actual size is less, but Pololu itself is 9 cm
EV_INTERSECT_TIME = 2.7 # in seconds. Time it takes for EV to cross intersection

SAFETY_TIME = 1 # in seconds, the amount of clearance time you need between vehicles crossing

# Intersection
INTERSECTION_SIZE = 9 # in cm. A square box around the intersection

# Velocity measurements
VELOCITY_UPDATE_FREQ = 2 # The number of times to update velocity. Affects window used to measure velocity

# Camera selection
CAM_ID = 0 # Usually the camera id for phone
SCENE_CALIBRATION_TIME = 10 # number of seconds to calibrate program to find intersection and distances

# Aruco Tags
VERT_TOLERANCE = 10 # The tolerance for the point at which two points are are on the same line
DIST_TO_FRONT = 4 # in cm. The distance from the front of the Aruco Tag to the front of the Pololu
TRAIN_ID = 0
EV_ID = 1
INTERSECTION_IDS = (2, 3) # The Aruco Tag IDs for the 
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

######################
## Helper Functions ##
######################

def action_generator(train_time, train_time_brake, train_state,
                     ev_time, ev_time_brake, ev_state, 
                     alg="naive"):
    """
    Given the time it takes for the train and ev to reach the intersection and the current states, decide what action to take

    Params:
        train_time, train_time_brake, ev_time, ev_time_brake (float) : Time it takes for vehicle to reach the intersection at full speed or at full brakes
        train_state, ev_state, state (int) : state variables of the system
        alg (str) : Which approach to use
    Ret:
        command (List): If empty, do nothing. 
            Else, command[0] = "train" or "ev" (which vehicle to stop or start), command[1] = "s\n" or "d\n" (stop, start)
    """
    # Edge cases
    # Do nothing if 1) One of the vehicles has already passed the intersection, and 2) The other vehicle has started to move
    if train_state == 2 and ev_state == 2:
        # Experiment ended
        return []
    elif train_state == 2 and ev_state != 2:
        # Check if EV is moving or slowing or in intersection
        if (ev_state in [1, 4, 5]):
            # EV is not moving or is slowing, tell it to move
            return ["ev", "d\n"]
        # Do nothing since EV is moving and train has passed
        return []
    elif ev_state == 2 and train_state != 2:
         # Check if Train is moving or not
        if train_state in [1, 4, 5]:
            # Train is not moving or is slowing, tell it to move
            return ["train", "d\n"]
        # Do nothing since Train is moving and train has passed
        return []
    elif (train_state == 1 and ev_state == 4) or \
        (ev_state == 1 and train_state == 4):
        # If one vehicle is currently crossing and the other has stopped
        return []
    elif train_state == 3 or ev_state == 3:
        # If we haven't seen either, start both instantly
        return ["train", "i\n", "ev", "i\n"]
    elif train_state == 4 and ev_state == 4:
        # If both are stopped, EV should have priority
        return ["ev", "d\n"]
    
    # Main logic if both haven't crossed
    train_finish_time = train_time + TRAIN_INTERSECT_TIME
    ev_finish_time = ev_time + EV_INTERSECT_TIME

    # Naive Algorithm
    if alg == "naive":
        # Stop the EV if train is within 20 seconds of the intersection
        if train_time < 20:
            # Stop the EV if possible
            if ev_time_brake == -1:
                return ["ev", "s\n", "train", "d\n"]
            elif train_state != 1 and ev_finish_time < train_time_brake:
                # Let the EV cross, stop the train if the train can stop in time
                return ["train", "s\n", "ev", "d\n"]
        else:
            # Stop the train otherwise
            return ["train", "s\n", "ev", "d\n"]

    # First check if the train can cross before the EV without blocking it
    if train_finish_time + SAFETY_TIME < ev_time:
        # Train can make it through without blocking EV
        return ["ev", "s\n"]
    else:
        # Check if train can stop for the EV or if EV can cross before train if the train brakes
        if train_time_brake == -1 or ev_finish_time < train_time_brake:
            if ev_finish_time + SAFETY_TIME < train_time:
                # EV Can cross before the train gets there, so do nothing
                # Ensure EV is crossing
                return ["ev", "d\n"]
            # Stop the train, ensure EV is crossing
            return ["train", "s\n", "ev", "d\n"]
        else:
            # Train can't stop, have to slow the EV (since we know it will arrive at the intersection too close to when the train is there)
            return ["train", "d\n", "ev", "s\n"]

def time_to_intersection(position, velocity, intersection, orientation, veh_state, type):
    """
    Returns the time it takes for vehicle to reach the intersection given position and intersection

    Params:
        position (List) : current (x, y) position of vehicle in cm
        velocity (float) : speed of vehicle
        intersection (List) : position of the intersection (x1, x2, y1, y2) where x1 < x2, y1 < y2
        orientation (int): which direction the vehicle is heading in 
        veh_state (int) : state variable: 0 = haven't seen, 1 = haven't crossed, 2 = fully crossed
        type (str) : "train" or "ev"
    Ret:
        veh_arrival_t (float) : Time it takes for vehicle to reach intersection at full speed
        veh_arrival_t_brake (float) : Time it takes for vehicle to reach intersection by braking. -1 if it can stop before reaching
        veh_moving_state (int) : 
            Returns 0 if nothing of note
            Returns 1 if the vehicle is currently in the intersection
            Returns 2 if the vehicle has passed the intersection
            Returns 3 if vehicle not seen and hasn't been before
            Returns 4 if the vehicle is not moving
    """
    # Edge case - don't see the vehicle
    if position == -1:
        if veh_state == 2 or veh_state == 1:
            # Vehicle has already previously passed or going through the intersection and is no longer vivisble
            return 0, 0, 2
        else:
            # Vehicle has not been seen or passed yet
            return 0, 0, 3
    
    # Find distance from intersection
    decel = TRAIN_DECEL if type == "train" else EV_DECEL
    veh_length = TRAIN_LENGTH if type == "train" else EV_LENGTH
    if orientation == 1:
        # Check bottom edge of intersection to current y-position of vehicle
        dist_to_intersect = -(intersection[2] - position[1]) # Origin of camera pixel is top left
    else:
        # Check left edge of intersection to current x-position of vehicle
        dist_to_intersect = intersection[0] - position[0]
    print(f"{type} Distance: {dist_to_intersect}, Length: {veh_length}")
    if dist_to_intersect < 0:
        # Check if the vehicle is past the intersection
        if abs(dist_to_intersect) > INTERSECTION_SIZE + veh_length:
            return 0, 0, 2 # Now past the intersection
        else:
            # Return the time the vehicle has already spent crossing the intersection
            # Assuming constant speed for entire crossing
            return -abs(dist_to_intersect) / velocity, 0, 1 # Still crossing the intersection
    # Find time to intersection
    if velocity <= 0.05:
        # Vehicle is stopped
        return 0, 0, 4
    veh_arrival_t = dist_to_intersect / velocity
    veh_arrival_t_brake = min((-velocity + np.sqrt(velocity**2 - 2*decel*dist_to_intersect)) / (-decel), 
                                    (-velocity - np.sqrt(velocity**2 - 2*decel*dist_to_intersect)) / (-decel))
    if np.isnan(veh_arrival_t_brake):
        veh_arrival_t_brake = -1
    
    return veh_arrival_t, veh_arrival_t_brake, 0

def calibrate_intersection(tag_positions):
    """
    Returns the coordinates of the intersection and the scale cm / px

    Params:
        tag_positions (Dict) : list of positions of the tags in pixel coordinates
    Ret:
        intersection_position (List[int]) : (x1, x2, y1, y2) boundaries of the intersection in cm
        cm_per_px (float) : the number of centimeters per pixel based on constant
    """
    # MAJOR ASSUMPTION - CAMERA IS PERPENDICULAR + PARALLEL TO THE INTERSECTION
    # Tags are on the bottom, with 2 on the left, 3 on the right
    # Grab the top-left corner of tag 2 and top-right corner of tag 3
    x1 = tag_positions[INTERSECTION_IDS[0]][0][0]
    x2 = tag_positions[INTERSECTION_IDS[1]][1][0]
    y1 = (tag_positions[INTERSECTION_IDS[0]][0][1] + tag_positions[INTERSECTION_IDS[1]][1][1]) / 2

    # Find scale, then update all values
    cm_per_pixel = INTERSECTION_SIZE / (x2 - x1) # The two tags are intersection size apart
    x1 *= cm_per_pixel
    x2 *= cm_per_pixel
    y1 *= cm_per_pixel
    y2 = y1 - INTERSECTION_SIZE

    return [x1, x2, y1, y2], cm_per_pixel

###############
## Main Loop ##
###############
async def main():
    # Find the bluetooth devices first
    train_addr, ev_addr = await ble_scan()
    # Connect to the devices
    print("Connecting...")
    train = BleakClient(train_addr)
    ev = BleakClient(ev_addr)
    await asyncio.gather(
        train.connect(),
        ev.connect()
    )
    print("Connected to Train and EV")

    ###############################
    ## Open Camera and Calibrate ##
    ###############################
    """
    This will print out the times at which the vehicles cross the intersection
    """
    print("Opening Camera...", end = '\r')
    start = time.time()
    cam = cv.VideoCapture(CAM_ID) # Change to whichever camera you use
    # Adjusting resolution to maximum
    cam.set(cv.CAP_PROP_FRAME_WIDTH, 10000)
    cam.set(cv.CAP_PROP_FRAME_HEIGHT, 10000)
    end = time.time()
    print(f"Camera opened in {end - start} s")
    
    print("Calibrating")
    # Get number of frames needed to update velocity
    framerate = cam.get(cv.CAP_PROP_FPS)
    VELOCITY_WINDOW = framerate // VELOCITY_UPDATE_FREQ
    # Finding position of the intersection
    start = time.time()
    end = time.time()
    # Stores the average coordinates for the two corners of the tag facing the other tag (the top-left and top-right)
    intersection_tag_positions = {i: [[0, 0], [0, 0]] for i in INTERSECTION_IDS}
    n = [0, 0]
    while (end - start) < SCENE_CALIBRATION_TIME:
        ret, frame = cam.read()
        if not ret:
            print("Failed to read frame")
            continue
        
        # Gray out the frame for tag detection
        frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        corners, ids, rejected = detector.detectMarkers(frame_gray)
        if ids is None:
            continue
        # Assuming the intersection tags will be visible
        for i, id in enumerate(ids):
            tag_id = int(id[0])
            if tag_id in INTERSECTION_IDS:
                # Compute a moving average
                idx = INTERSECTION_IDS.index(tag_id)
                n[idx] += 1
                # Top left corner
                intersection_tag_positions[tag_id][0][0] += (corners[i][0, 0, 0] - intersection_tag_positions[tag_id][0][0]) / n[idx]
                intersection_tag_positions[tag_id][0][1] += (corners[i][0, 0, 1] - intersection_tag_positions[tag_id][0][1]) / n[idx]
                # Top right corner
                intersection_tag_positions[tag_id][1][0] += (corners[i][0, 1, 0] - intersection_tag_positions[tag_id][1][0]) / n[idx]
                intersection_tag_positions[tag_id][1][1] += (corners[i][0, 1, 1] - intersection_tag_positions[tag_id][1][1]) / n[idx]

            else:
                # If the detected tag isn't the intersection tags, skip
                continue
            
        # Draw window
        if ids is not None:
            cv.aruco.drawDetectedMarkers(frame, corners, ids)
        cv.imshow("Intersection Birds-Eye-View (type \"quit\" in the terminal to close)", frame)
        if cv.waitKey(1) & 0xFF == ord('q'):
            break
        
        end = time.time()
    del n # Clean up variable
    # Find the conversion and position of the intersection
    intersection_pos, cm_per_px = calibrate_intersection(intersection_tag_positions)
    print(f"Intersection {intersection_pos}, CM Conversion {cm_per_px}")
    print("Finished Calibration. DO NOT MOVE THE CAMERA")

    #######################
    ## Accept User Input ##
    #######################
    """
    Only three options here: start both vehicles (start experiment), stop both vehicles (end experiment), and quit
    """
    print("Type \"start\" to start the experiment, \"end\" to end the experiment, and \"quit\" to quite the program.")
    
    # Defining vehicle commands
    start_veh = "d\n"
    stop_veh = "s\n"
    inst_start_veh = "i\n"

    # Main Loop
    try:
        while True:
            # Read input
            select_option = input("Input Option (start, end, quit): ").lower()
            while select_option not in ["start", "end", "quit"]:
                print("Didn't recognize input.")
                select_option = input("Input Option (start, end, quit): ").lower()
            if select_option == "quit":
                break
            elif select_option == "end":
                print("Stopping vehicles")
                # Sending stop commands
                await asyncio.gather(
                    train.write_gatt_char(UUID, stop_veh.encode(), response=False),
                    ev.write_gatt_char(UUID, stop_veh.encode(), response=False)
                )
                continue # Skip everything else and wait for input
            
            ##############################
            ## Main Intersection Logict ##
            ##############################
            # Select naive or advanced algorithm
            alg_select = input("Select an algorithm to use (naive or smart): ").lower()
            while alg_select not in ["naive", "smart"]:
                print("Input not recognized")
                alg_select = input("Select an algorithm to use (naive or smart): ").lower()
            
            ############
            ## States ##
            ############
            """
            0 if nothing of note
            1 if the vehicle is currently in the intersection
            2 if the vehicle has passed the intersection
            3 if vehicle not seen and hasn't been before
            4 if the vehicle is not moving
            5 if the vehicle is slowing down
            """
            train_state = 3
            ev_state = 3 # Same as above

            # Start the vehicles
            await asyncio.gather(
                    train.write_gatt_char(UUID, inst_start_veh.encode(), response=False),
                    ev.write_gatt_char(UUID, inst_start_veh.encode(), response=False)
                )
            # Start recording the time it takes for both vehicles to cross the intersection
            metric_start_time = time.time()
            
            # Inner loop to start video detection
            # Each element is a tuple ((pos_x, pos_y), time)
            train_pos_history, ev_pos_history = [], []
            # Position is the frontmost point of the EV
            train_orient, ev_orient = -1, -1 # 0: Horizontal, 1: Vertical, -1: not set
            while True:
                ret, frame = cam.read()
                if not ret:
                    continue

                frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
                corners, ids, rejected = detector.detectMarkers(frame_gray)
                # Find the position of the train and EV in cm
                seen_train, seen_ev = False, False
                if ids is None:
                    continue
                for i, id in enumerate(ids): 
                    id = int(id[0])
                    if id == TRAIN_ID:
                        seen_train = True
                        mid_point = [(corners[i][0, 0, 0] + corners[i][0, 1, 0]) / 2, (corners[i][0, 0, 1] + corners[i][0, 1, 1]) / 2]
                        # Find direction train is pointing (if it hasn't been dicovered already)
                        if train_orient == -1:
                            if abs(corners[i][0, 0, 0] - corners[i][0, 1, 0]) < VERT_TOLERANCE:
                                train_orient = 0
                            else:
                                train_orient = 1
                        # Translate to cm
                        mid_point[0] *= cm_per_px
                        mid_point[1] *= cm_per_px
                        # Find the position
                        mid_point[train_orient] += DIST_TO_FRONT
                        train_pos_history.append((mid_point, time.time()))
                    elif id == EV_ID:
                        seen_ev = True
                        mid_point = [(corners[i][0, 0, 0] + corners[i][0, 1, 0]) / 2, (corners[i][0, 0, 1] + corners[i][0, 1, 1]) / 2]
                        # Find direction train is pointing (if it hasn't been dicovered already)
                        if ev_orient == -1:
                            if abs(corners[i][0, 0, 0] - corners[i][0, 1, 0]) < VERT_TOLERANCE:
                                ev_orient = 0
                            else:
                                ev_orient = 1
                        # Translate to cm
                        mid_point[0] *= cm_per_px
                        mid_point[1] *= cm_per_px
                        # Find the position
                        mid_point[ev_orient] += DIST_TO_FRONT
                        ev_pos_history.append((mid_point, time.time()))

                # Update speed and calculate needed action based on state
                # Assumes velocity hasn't changed in this window
                train_vel, ev_vel = 0, 0
                if len(train_pos_history) >= VELOCITY_WINDOW or len(ev_pos_history) >= VELOCITY_WINDOW:
                    for i in range(len(train_pos_history) - 1):
                        n = i + 1
                        pos_prev, t_prev = train_pos_history[i]
                        pos_curr, t_curr = train_pos_history[i + 1]
                        if train_orient == 0:
                            distance = abs((pos_prev[0] - pos_curr[0]))
                        else: 
                            distance = abs(pos_prev[1] - pos_curr[1])
                        distance = 0 if distance < 0.05 else distance # Clip small variations
                        dt = t_curr - t_prev
                        v = distance / dt

                        train_vel += (v - train_vel) / n
                    for i in range(len(ev_pos_history) - 1):
                        # Only get distance in the direction of movement
                        n = i + 1
                        pos_prev, t_prev = ev_pos_history[i]
                        pos_curr, t_curr = ev_pos_history[i + 1]
                        if ev_orient == 0:
                            distance = abs((pos_prev[0] - pos_curr[0]))
                        else: 
                            distance = abs(pos_prev[1] - pos_curr[1])
                        distance = 0 if distance < 0.05 else distance
                        dt = t_curr - t_prev
                        v = distance / dt

                        ev_vel += (v - ev_vel) / n
                    # Find last seen position
                    if seen_train:
                        train_pos = train_pos_history[-1][0]
                    else:
                        train_pos = -1
                    if seen_ev:
                        ev_pos = ev_pos_history[-1][0]
                    else:
                        ev_pos = -1
                    # Empty positions
                    train_pos_history = []
                    ev_pos_history = []
                    # Find time to intersection
                    print("#" * 50)
                    print(f"Train Pos: {train_pos}, Train Vel: {train_vel}, Orient: {train_orient}")
                    print(f"EV Pos: {ev_pos}, EV Vel: {ev_vel}, Orient: {ev_orient}")
                    train_arrival_t, train_arrival_t_brake, train_state = time_to_intersection(train_pos, train_vel, intersection_pos, train_orient, train_state, "train")
                    ev_arrival_t, ev_arrival_t_brake, ev_state = time_to_intersection(ev_pos, ev_vel, intersection_pos, ev_orient, ev_state, "ev")

                    # Debugging 
                    print(f"Train arrival: {train_arrival_t}, Brake: {train_arrival_t_brake}, State: {train_state}")
                    print(f"EV arrival: {ev_arrival_t}, Brake: {ev_arrival_t_brake}, State: {ev_state}")

                    # Generate action decision
                    action= action_generator(train_arrival_t, train_arrival_t_brake, train_state,
                                            ev_arrival_t, ev_arrival_t_brake, ev_state,
                                            alg_select)
                    print(f"Action: {action}")
                    print("#" * 50 + "\n\n")
                    # Extra edge case: if the vehicles are traveling in parallel, do nothing.
                    if len(action) != 0 and (train_orient != ev_orient):
                        for i in range(0, len(action), 2):
                            # Do an action
                            if action[i] == "train":
                                if action[i + 1] == "s\n":
                                    train_state = 5 # Let system know train is slowing
                                # Send command to train
                                await train.write_gatt_char(UUID, action[i + 1].encode(), response=False)
                            else:
                                if action[i + 1] == "s\n":
                                    ev_state = 5
                                # Send command to EV
                                await ev.write_gatt_char(UUID, action[i + 1].encode(), response=False)
                    if train_state == 2 and ev_state == 2:
                        # Experiment has finished: stop vehicles and exit
                        await asyncio.gather(
                            train.write_gatt_char(UUID, stop_veh.encode(), response=False),
                            ev.write_gatt_char(UUID, stop_veh.encode(), response=False)
                        )
                        break

                # Draw the Tags onto the frame
                cv.aruco.drawDetectedMarkers(frame, corners, ids)
                # Show the image
                cv.imshow("", frame)
                if cv.waitKey(1) & 0xFF == ord('q'):
                    break
        

            # End time recording and report the time it took for the vehicles to pass the intersection
            # Reset the state
            train_state, ev_state = 3, 3
            metric_end_time = time.time()
            print(f"The {alg_select} algorithm took {round(metric_end_time - metric_start_time, 3)}s to complete.")
    except Exception as e:
        print("Error: ", e)

    # Closing everything
    print("== Cleaning up ==")
    print("Stopping vehicles")
    await asyncio.gather(
                train.write_gatt_char(UUID, stop_veh.encode(), response=False),
                ev.write_gatt_char(UUID, stop_veh.encode(), response=False)
            )
    print("Releasing Camera...")
    cam.release()
    print("Destorying OpenCV windows...")
    cv.destroyAllWindows()
    print("Disconnecting bluetooth devices...")
    await asyncio.gather(
        train.disconnect(),
        ev.disconnect()
    )

if __name__ == "__main__":
    asyncio.run(main())
    print("Program Ended.")

