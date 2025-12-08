# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# ##############################################
# ## HARD-CODED PHYSICAL MEASUREMENT AVERAGE  ##
# ##############################################

# # UPDATE THESE VALUES BASED ON YOUR REAL MEASUREMENTS (in cm)
# physical_measurements = [10.0, 9.9, 10.1, 9.8, 10.0]

# # Auto-average to remove human ruler error
# KNOWN_CM = sum(physical_measurements) / len(physical_measurements)

# print(f"\n[PHYSICAL CALIBRATION] Averaged real distance = {KNOWN_CM:.3f} cm\n")


# #############
# ## SETUP   ##
# #############

# # Load ArUco dictionary (4x4, 50 IDs)
# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)

# # Default detection parameters
# parameters = cv.aruco.DetectorParameters()

# # Create ArUco detector
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # Calibration marker IDs
# REF_A = 0
# REF_B = 1

# # Pixel-to-cm scale (computed after calibration)
# cm_per_pixel = None

# # Pixel noise reduction: collect multiple measurements
# calibration_samples = []
# NUM_SAMPLES = 10   # number of frames to average pixel distance


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

#     # Convert frame to grayscale
#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     # Detect markers
#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     # Only process if >= 2 markers visible
#     if ids is not None and len(ids) >= 2:

#         ###########################################
#         ## STEP 1 — COMPUTE MARKER CENTERS
#         ###########################################

#         centers = {}

#         for i in range(len(ids)):
#             marker_id = int(ids[i][0])
#             c = corners[i][0]   # 4 corner points for each marker

#             # Compute center: average of 4 corners
#             cx = (c[0][0] + c[1][0] + c[2][0] + c[3][0]) / 4
#             cy = (c[0][1] + c[1][1] + c[2][1] + c[3][1]) / 4

#             centers[marker_id] = (cx, cy)

#         ###########################################
#         ## STEP 2 — PAIRWISE CENTER DISTANCES
#         ###########################################

#         marker_ids = sorted(centers.keys())

#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):

#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 A = centers[idA]
#                 B = centers[idB]

#                 # Euclidean pixel distance
#                 dist_px = np.sqrt((B[0] - A[0])**2 + (B[1] - A[1])**2)
#                 print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

#                 ######################################################
#                 ## STEP 3 — COLLECT PIXEL CALIBRATION SAMPLES
#                 ######################################################
#                 if cm_per_pixel is None:
#                     if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):

#                         # Collect pixel samples until full
#                         if len(calibration_samples) < NUM_SAMPLES:
#                             calibration_samples.append(dist_px)
#                             print(f"[CALIBRATION] Sample {len(calibration_samples)}/{NUM_SAMPLES}: {dist_px:.2f} px")

#                         # Compute cm_per_pixel after enough samples
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
#     ## DRAW AND DISPLAY
#     ############################

#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)

#     cv.imshow("ArUco Center-to-Center Tracker", frame)

#     if cv.waitKey(1) == ord('q'):
#         break


# ############################
# ## CLEANUP
# ############################
# cam.release()
# cv.destroyAllWindows()












# edge to ede pixel to cm 


#############
## Imports ##
#############
import cv2 as cv
import numpy as np
import time

##################################################
## HARD-CODED PHYSICAL MEASUREMENT AVERAGING   ##
##################################################

# UPDATE THESE BASED ON YOUR REAL MEASUREMENTS (cm)
physical_measurements = [10.0, 9.9, 10.1, 9.8, 10.0]

# Average to remove ruler measurement noise
KNOWN_CM = sum(physical_measurements) / len(physical_measurements)

print(f"\n[PHYSICAL CALIBRATION] Averaged real distance = {KNOWN_CM:.3f} cm\n")


#############
## SETUP   ##
#############

# Load the 4×4 ArUco dictionary
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)

# Default detector parameters
parameters = cv.aruco.DetectorParameters()

# Create ArUco detector
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Calibration markers (top-edge midpoint distance)
REF_A = 1
REF_B = 2

# Pixel → cm scale (computed after calibration)
cm_per_pixel = None

# Pixel noise reduction
calibration_samples = []
NUM_SAMPLES = 20   # average 10 frames of pixel distance


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

    # Convert to grayscale
    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    # Detect ArUco markers
    corners, ids, rejected = detector.detectMarkers(frame_gray)

    if ids is not None and len(ids) >= 2:

        ###########################################
        ## STEP 1 — COMPUTE EDGE MIDPOINTS
        ###########################################

        edge_midpoints = {}  # marker_id → (mid_x, mid_y)

        for i in range(len(ids)):
            marker_id = int(ids[i][0])
            c = corners[i][0]  # 4 corner points (TL, TR, BR, BL)

            # EDGE-TO-EDGE uses the TOP EDGE midpoint
            top_left  = c[0]
            top_right = c[1]

            mid_x = (top_left[0] + top_right[0]) / 2.0
            mid_y = (top_left[1] + top_right[1]) / 2.0

            edge_midpoints[marker_id] = (mid_x, mid_y)

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

                # Pixel distance between TOP edges
                dist_px = np.sqrt((B[0] - A[0])**2 + (B[1] - A[1])**2)

                print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

                ######################################################
                ## STEP 3 — COLLECT PIXEL CALIBRATION SAMPLES
                ######################################################
                if cm_per_pixel is None:
                    if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):

                        # Still collecting samples
                        if len(calibration_samples) < NUM_SAMPLES:
                            calibration_samples.append(dist_px)
                            print(f"[CALIBRATION] Sample {len(calibration_samples)}/{NUM_SAMPLES}: {dist_px:.2f} px")

                        # After enough samples → compute pixel→cm scale
                        if len(calibration_samples) == NUM_SAMPLES:
                            avg_px = sum(calibration_samples) / NUM_SAMPLES
                            cm_per_pixel = KNOWN_CM / avg_px

                            print(f"\n[CALIBRATION DONE]")
                            print(f"Averaged pixel distance = {avg_px:.2f} px")
                            print(f"Averaged physical distance = {KNOWN_CM:.3f} cm")
                            print(f"1 pixel = {cm_per_pixel:.5f} cm\n")

                ######################################################
                ## STEP 4 — PIXELS → CM
                ######################################################
                if cm_per_pixel is not None:
                    dist_cm = dist_px * cm_per_pixel
                    print(f"[CM] Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

        print()  # spacing


    ############################
    ## DRAW & DISPLAY
    ############################

    if ids is not None:
        cv.aruco.drawDetectedMarkers(frame, corners, ids)

    cv.imshow("ArUco Edge-to-Edge Tracker", frame)

    if cv.waitKey(1) == ord('q'):
        break


############################
## CLEANUP
############################
cam.release()
cv.destroyAllWindows()
