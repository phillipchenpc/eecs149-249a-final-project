"""
Main intersection logic containing: 1) Camera connection, 2) Bluetooth commands

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
    print("Scanning for BLE devices...")
    devices = await BleakScanner.discover()

    if not devices:
        print("No BLE devices found.")
        return

    print("\nFound BLE devices:")
    # Construct a dictionary of device name to address
    device_dict = {}
    for d in devices:
        device_dict[d.name] = d.address
        print(f"- Name: {d.name}, Address: {d.address}")

    #############################
    ## Select Bluetooth Device ##
    #############################
    train_addr, ev_addr = "", ""
    train_name, ev_name = "", ""
    while train_name not in device_dict.keys():
        train_name = input("Type the exact name of the device to use for the light-rail train.")
    while ev_name not in device_dict.keys():
        ev_name = input("Type the exact name of the device to use for the Emergency Vehicle.")
    # Match the names to the addresses
    train_addr = device_dict[train_name]
    ev_addr = device_dict[ev_name]

    return train_addr, ev_addr

######################
## Helper Functions ##
######################

def action_generator(train_time, ev_time):
    """
    Given the time it takes for the train and ev to reach the intersection, 
    """

def time_to_intersection(position, velocity, intersection):
    """
    Returns the time it takes for vehicle to reach the intersection given position and intersection
    Returns -1 if the vehicle is currently in the 
    """
    pass

def find_px_to_cm(ref_pt_1, ref_pt_2):
    """
    Finds the total cm per pixel given pixel locations of reference points around intersection

    Params:
        ref_pt_1 (int, int): the x, y pixel locations of the first marker
        ref_pt_2 (int, int): the x, y pixel locations of the second marker
    """
    pass

def calibrate_intersection(tag_positions):
    """
    Returns the coordinates of the corners of the intersection and the scale cm / px

    Params:
        tag_positions (Dict) - list of positions of the tags 
    Ret:
    """
    pass

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

EV_SPEED = 6.6667 # in cm/s
EV_ACCEL = 0.3194 # in cm / s**2
EV_DECEL = 0.7882 # in cm / s**2
EV_STOP_DIST = 28.194 # in cm
EV_LENGTH = 9 # Actual size is less, but Pololu itself is 9 cm

# Intersection
INTERSECTION_SIZE = 9 # in cm. A square box around the intersection

# Velocity measurements
VELOCITY_UPDATE_FREQ = 5 # The number of times to update velocity. Affects window used to measure velocity

# Camera selection
CAM_ID = 2 # Usually the camera id for phone
SCENE_CALIBRATION_TIME = 20 # number of seconds to calibrate program to find intersection and distances

# Aruco Tags
TRAIN_ID = 0
EV_ID = 1
INTERSECTION_IDS = (2, 3) # The Aruco Tag IDs for the 
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

###############
## Main Loop ##
###############
async def main():
    # Find the bluetooth devices first
    train_addr, ev_addr = ble_scan()
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
    max_res = 10000
    cam.set(cv.CAP_PROP_FRAME_WIDTH, max_res)
    cam.set(cv.CAP_PROP_FRAME_HEIGHT, max_res)
    del max_res
    end = time.time()
    print(f"Camera opened in {end - start} s")
    
    print("Calibrating")
    # Get number of frames needed to update velocity
    framerate = cam.get(cv.CV_CAP_PROP_FPS)
    VELOCITY_WINDOW = framerate // VELOCITY_UPDATE_FREQ
    # Finding position of the intersection
    start = time.time()
    end = time.time()
    # Stores the average coordinates for the two corners of the tag facing the other tag (the top-left and top-right)
    intersection_tag_positions = {0: [0, 0], 1: [0, 0]}
    n = 0
    while (end - start) < SCENE_CALIBRATION_TIME:
        ret, frame = cam.read()
        if not ret:
            print("Failed to read frame")
        
        # Gray out the frame for tag detection
        frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        corners, ids, rejected = detector.detectMarkers(frame_gray)
        # Assuming the intersection tags will be visible
        for i, id in enumerate(ids):
            try:
                tag_id = INTERSECTION_IDS.index(id) # Just see if this is the first or second intersetion tag
                # Compute a moving average
                n += 1
                intersection_tag_positions[tag_id][0] += (corners[i][0] - intersection_tag_positions[tag_id][0]) / n
                intersection_tag_positions[tag_id][1] += (corners[i][1] - intersection_tag_positions[tag_id][1]) / n
            except ValueError:
                # If the detected tag isn't the intersection tags, skip
                continue
            
        # Draw window
        if ids is not None:
            cv.aruco.drawDetectedMarkers(frame, corners, ids)
        cv.imshow("Intersection Birds-Eye-View (type \"quit\" in the terminal to close)", frame)
        
        end = time.time()
    del n # Clean up variable
    # Find the conversion and position of the intersection
    intersection_position, cm_per_px = calibrate_intersection(intersection_tag_positions)
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

    # Main Loop
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
        
        # Main experiment and logic
        # Select naive or advanced algorithm
        alg_select = input("Select an algorithm to use (naive or smart): ").lower()
        while alg_select not in ["naive", "smart"]:
            print("Input not recognized")
            alg_select = input("Select an algorithm to use (naive or smart): ").lower()
        
        # Start the vehicles
        await asyncio.gather(
                train.write_gatt_char(UUID, start_veh.encode(), response=False),
                ev.write_gatt_char(UUID, start_veh.encode(), response=False)
            )
        # Start recording the time it takes for both vehicles to cross the intersection
        metric_start_time = time.time()


        # End time recording and report the time it took for the vehicles to pass the intersection
        metric_end_time = time.time()
        print(f"The {alg_select} algorithm took {round(metric_end_time - metric_start_time, 3)}s to complete.")


    # Closing everything
    print("== Cleaning up ==")
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

