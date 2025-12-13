# # edge to ede pixel to cm 
# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# ##################################################
# ## HARD-CODED PHYSICAL MEASUREMENT AVERAGING   ##
# ##################################################

# # UPDATE THESE BASED ON YOUR REAL MEASUREMENTS (cm)
# physical_measurements = [10.0, 9.9, 10.1, 9.8, 10.0]

# # Average to remove ruler measurement noise
# KNOWN_CM = sum(physical_measurements) / len(physical_measurements)

# print(f"\n[PHYSICAL CALIBRATION] Averaged real distance = {KNOWN_CM:.3f} cm\n")


# #############
# ## SETUP   ##
# #############

# # Load the 4×4 ArUco dictionary
# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)

# # Default detector parameters
# parameters = cv.aruco.DetectorParameters()

# # Create ArUco detector
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # Calibration markers (top-edge midpoint distance)
# REF_A = 0
# REF_B = 3

# # Pixel → cm scale (computed after calibration)
# cm_per_pixel = None

# # Pixel noise reduction
# calibration_samples = []
# NUM_SAMPLES = 30   # average 10 frames of pixel distance


# ############################
# ## OPEN CAMERA
# ############################

# print("Opening Camera...", end="\r")
# start = time.time()

# cam = cv.VideoCapture(0)

# end = time.time()
# print(f"Camera opened in {end - start:.2f} seconds")
# print("Press 'q' to close the program.\n")


# ############################
# ## MAIN LOOP
# ############################
# while True:

#     ret, frame = cam.read()
#     if not ret:
#         print("Failed to read frame.")
#         break

#     # Convert to grayscale
#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     # Detect ArUco markers
#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     if ids is not None and len(ids) >= 2:

#         ###########################################
#         ## STEP 1 — COMPUTE EDGE MIDPOINTS
#         ###########################################

#         edge_midpoints = {}  # marker_id → (mid_x, mid_y)

#         for i in range(len(ids)):
#             marker_id = int(ids[i][0])
#             c = corners[i][0]  # 4 corner points (TL, TR, BR, BL)

#             # EDGE-TO-EDGE uses the TOP EDGE midpoint
#             top_left  = c[0]
#             top_right = c[1]

#             mid_x = (top_left[0] + top_right[0]) / 2.0
#             mid_y = (top_left[1] + top_right[1]) / 2.0

#             edge_midpoints[marker_id] = (mid_x, mid_y)

#         ###########################################
#         ## STEP 2 — PAIRWISE EDGE DISTANCES
#         ###########################################

#         marker_ids = sorted(edge_midpoints.keys())

#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):

#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 A = edge_midpoints[idA]
#                 B = edge_midpoints[idB]

#                 # Pixel distance between TOP edges
#                 dist_px = np.sqrt((B[0] - A[0])**2 + (B[1] - A[1])**2)

#                 print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

#                 ######################################################
#                 ## STEP 3 — COLLECT PIXEL CALIBRATION SAMPLES
#                 ######################################################
#                 if cm_per_pixel is None:
#                     if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):

#                         # Still collecting samples
#                         if len(calibration_samples) < NUM_SAMPLES:
#                             calibration_samples.append(dist_px)
#                             print(f"[CALIBRATION] Sample {len(calibration_samples)}/{NUM_SAMPLES}: {dist_px:.2f} px")

#                         # After enough samples → compute pixel→cm scale
#                         if len(calibration_samples) == NUM_SAMPLES:
#                             avg_px = sum(calibration_samples) / NUM_SAMPLES
#                             cm_per_pixel = KNOWN_CM / avg_px

#                             print(f"\n[CALIBRATION DONE]")
#                             print(f"Averaged pixel distance = {avg_px:.2f} px")
#                             print(f"Averaged physical distance = {KNOWN_CM:.3f} cm")
#                             print(f"1 pixel = {cm_per_pixel:.5f} cm\n")

#                 ######################################################
#                 ## STEP 4 — PIXELS → CM
#                 ######################################################
#                 if cm_per_pixel is not None:
#                     dist_cm = dist_px * cm_per_pixel
#                     print(f"[CM] Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

#         print()  # spacing


#     ############################
#     ## DRAW & DISPLAY
#     ############################

#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)

#     cv.imshow("ArUco Edge-to-Edge Tracker", frame)

#     if cv.waitKey(1) == ord('q'):
#         break


# ############################
# ## CLEANUP
# ############################
# cam.release()
# cv.destroyAllWindows()






# # EDGE TO EDGE MID POINT PIXEL TO CM 
# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# ##################################################
# ## HARD-CODED PHYSICAL MEASUREMENT AVERAGING   ##
# ##################################################

# physical_measurements = [10.0, 9.9, 10.1, 9.8, 10.0]
# KNOWN_CM = sum(physical_measurements) / len(physical_measurements)
# print(f"\n[PHYSICAL CALIBRATION] Averaged real distance = {KNOWN_CM:.3f} cm\n")

# #############
# ## SETUP   ##
# #############

# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
# parameters = cv.aruco.DetectorParameters()
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# REF_A = 0
# REF_B = 3

# cm_per_pixel = None
# calibration_samples = []
# NUM_SAMPLES = 30

# ############################
# ## OPEN CAMERA
# ############################

# print("Opening Camera...", end="\r")
# start = time.time()
# cam = cv.VideoCapture(0)
# end = time.time()
# print(f"Camera opened in {end - start:.2f} seconds")
# print("Press 'q' to close the program.\n")

# ############################
# ## MAIN LOOP
# ############################
# while True:

#     ret, frame = cam.read()
#     if not ret:
#         print("Failed to read frame.")
#         break

#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     drawn_midpoints = []  # <-- ALWAYS defined so drawing never fails

#     if ids is not None and len(ids) >= 2:

#         ###########################################
#         ## STEP 1 — COMPUTE EDGE MIDPOINTS
#         ###########################################

#         edge_midpoints = {}

#         for i in range(len(ids)):
#             marker_id = int(ids[i][0])
#             c = corners[i][0]  # TL, TR, BR, BL

#             top_left = c[0]
#             top_right = c[1]

#             mid_x = (top_left[0] + top_right[0]) / 2.0
#             mid_y = (top_left[1] + top_right[1]) / 2.0

#             edge_midpoints[marker_id] = (mid_x, mid_y)

#             # For drawing red dot
#             drawn_midpoints.append((int(mid_x), int(mid_y), marker_id))

#         ###########################################
#         ## STEP 2 — PAIRWISE EDGE DISTANCES
#         ###########################################

#         marker_ids = sorted(edge_midpoints.keys())

#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):

#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 A = edge_midpoints[idA]
#                 B = edge_midpoints[idB]

#                 dist_px = np.sqrt((B[0] - A[0])**2 + (B[1] - A[1])**2)
#                 print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

#                 ######################################################
#                 ## STEP 3 — CALIBRATION
#                 ######################################################
#                 if cm_per_pixel is None:
#                     if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):

#                         if len(calibration_samples) < NUM_SAMPLES:
#                             calibration_samples.append(dist_px)
#                             print(f"[CALIBRATION] Sample {len(calibration_samples)}/{NUM_SAMPLES}: {dist_px:.2f} px")

#                         if len(calibration_samples) == NUM_SAMPLES:
#                             avg_px = sum(calibration_samples) / NUM_SAMPLES
#                             cm_per_pixel = KNOWN_CM / avg_px

#                             print("\n[CALIBRATION DONE]")
#                             print(f"Averaged pixel distance = {avg_px:.2f} px")
#                             print(f"Averaged physical distance = {KNOWN_CM:.3f} cm")
#                             print(f"1 pixel = {cm_per_pixel:.5f} cm\n")

#                 ######################################################
#                 ## STEP 4 — PIXELS → CM
#                 ######################################################
#                 if cm_per_pixel is not None:
#                     dist_cm = dist_px * cm_per_pixel
#                     print(f"[CM] Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

#         print()  # spacing

#     ############################
#     ## DRAW ON FRAME
#     ############################

#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)

#     # DRAW RED DOT MIDPOINTS (NEVER REMOVED)
#     for (mx, my, mid) in drawn_midpoints:
#         cv.circle(frame, (mx, my), 6, (0, 0, 255), -1)
#         cv.putText(frame, f"M{mid}", (mx + 5, my - 5),
#                     cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)

#     ############################
#     ## SHOW WINDOW  (THIS IS WHAT YOU WANT)
#     ############################

#     cv.imshow("ArUco Edge-to-Edge Tracker", frame)

#     if cv.waitKey(1) == ord('q'):
#         break

# ############################
# ## CLEANUP
# ############################
# cam.release()
# cv.destroyAllWindows()





# edge to edge pixel to cm + velocity in m/s
#############
## Imports ##
#############
import cv2 as cv
import numpy as np
import time
import math

##################################################
## HARD-CODED PHYSICAL MEASUREMENT AVERAGING   ##
##################################################

physical_measurements = [10.0, 9.9, 10.1, 9.8, 10.0]
KNOWN_CM = sum(physical_measurements) / len(physical_measurements)
print(f"\n[PHYSICAL CALIBRATION] Averaged real distance = {KNOWN_CM:.3f} cm\n")

#############
## SETUP   ##
#############

aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Calibration markers (top-edge midpoint distance)
REF_A = 2
REF_B = 3

cm_per_pixel = None
calibration_samples = []
NUM_SAMPLES = 30

# For velocity: marker_id -> (x_prev, y_prev, t_prev)
prev_states = {}

############################
## OPEN CAMERA
############################

print("Opening Camera...", end="\r")
start = time.time()
cam = cv.VideoCapture(0)
end = time.time()
print(f"Camera opened in {end - start:.2f} seconds")
print("Press 'q' to close the program.\n")

############################
## MAIN LOOP
############################
while True:

    ret, frame = cam.read()
    if not ret:
        print("Failed to read frame.")
        break

    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    corners, ids, rejected = detector.detectMarkers(frame_gray)

    drawn_midpoints = []
    velocities_to_draw = []   # (x, y, "0.05 m/s")

    if ids is not None and len(ids) >= 1:

        ###########################################
        ## STEP 1 — COMPUTE EDGE MIDPOINTS
        ###########################################

        edge_midpoints = {}
        now = time.time()

        for i in range(len(ids)):
            marker_id = int(ids[i][0])
            c = corners[i][0]  # TL, TR, BR, BL

            top_left = c[0]
            top_right = c[1]

            mid_x = (top_left[0] + top_right[0]) / 2.0
            mid_y = (top_left[1] + top_right[1]) / 2.0

            edge_midpoints[marker_id] = (mid_x, mid_y)
            drawn_midpoints.append((int(mid_x), int(mid_y), marker_id))

            ###########################################
            ## STEP 1.5 — VELOCITY IN METERS/SECOND
            ###########################################
            if marker_id in prev_states:
                x_prev, y_prev, t_prev = prev_states[marker_id]
                dt = now - t_prev

                if dt > 0:
                    dx = mid_x - x_prev
                    dy = mid_y - y_prev
                    dist_px = math.sqrt(dx*dx + dy*dy)

                    if cm_per_pixel is not None:
                        # convert px → cm → m
                        dist_m = (dist_px * cm_per_pixel) / 100.0
                        vel_m_s = dist_m / dt
                        vel_str = f"{vel_m_s:.3f} m/s"
                        print(f"[VEL] Marker {marker_id}: {vel_m_s:.3f} m/s")
                    else:
                        vel_px_s = dist_px / dt
                        vel_str = f"{vel_px_s:.2f} px/s"
                        print(f"[VEL] Marker {marker_id}: {vel_px_s:.2f} px/s (no calibration yet)")

                    velocities_to_draw.append((int(mid_x), int(mid_y), vel_str))

            # update last state
            prev_states[marker_id] = (mid_x, mid_y, now)

        ###########################################
        ## STEP 2 — PAIRWISE EDGE DISTANCES
        ###########################################

        marker_ids = sorted(edge_midpoints.keys())

        for i in range(len(marker_ids)):
            for j in range(i + 1, len(marker_ids)):

                idA = marker_ids[i]
                idB = marker_ids[j]

                A = edge_midpoints[idA]
                B = edge_midpoints[idB]

                dist_px = math.dist(A, B)
                print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

                ######################################################
                ## STEP 3 — CALIBRATION
                ######################################################
                if cm_per_pixel is None:
                    if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):

                        if len(calibration_samples) < NUM_SAMPLES:
                            calibration_samples.append(dist_px)
                            print(f"[CALIBRATION] Sample {len(calibration_samples)}/{NUM_SAMPLES}: {dist_px:.2f} px")

                        if len(calibration_samples) == NUM_SAMPLES:
                            avg_px = sum(calibration_samples) / NUM_SAMPLES
                            cm_per_pixel = KNOWN_CM / avg_px

                            print("\n[CALIBRATION DONE]")
                            print(f"Averaged pixel distance = {avg_px:.2f} px")
                            print(f"Averaged physical distance = {KNOWN_CM:.3f} cm")
                            print(f"1 pixel = {cm_per_pixel:.5f} cm\n")

                ######################################################
                ## STEP 4 — PIXELS → CM
                ######################################################
                if cm_per_pixel is not None:
                    dist_cm = dist_px * cm_per_pixel
                    print(f"[CM] Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

        print()

    ############################
    ## DRAW ON FRAME
    ############################

    if ids is not None:
        cv.aruco.drawDetectedMarkers(frame, corners, ids)

    # Draw midpoint red dots
    for (mx, my, mid) in drawn_midpoints:
        cv.circle(frame, (mx, my), 6, (0, 0, 255), -1)
        cv.putText(frame, f"M{mid}", (mx + 5, my - 5),
                   cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)

    # Draw velocities near midpoints
    for (mx, my, vel_str) in velocities_to_draw:
        cv.putText(frame, vel_str, (mx + 5, my + 15),
                   cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)

    ############################
    ## SHOW WINDOW
    ############################

    cv.imshow("ArUco Edge-to-Edge Tracker", frame)

    if cv.waitKey(1) == ord('q'):
        break

############################
## CLEANUP
############################
cam.release()
cv.destroyAllWindows()
