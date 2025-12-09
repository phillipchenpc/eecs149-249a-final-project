# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# ##########
# ## Main ##
# ##########

# # Grab the dictionary and create a detector
# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
# parameters = cv.aruco.DetectorParameters()
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # Open the camera
# print("Opening Camera...", end='\r')
# start = time.time()
# cam = cv.VideoCapture(0)
# end = time.time()
# print(f"Camera opened in {end - start} s")

# print("Press q to end the program (when the video window is selected)")

# # Reading from the camera
# while True:
#     start = time.time()
#     ret, frame = cam.read()

#     # Gray out the image
#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     # Detect the tags
#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     # Debug print: shows what IDs were detected each frame
#     #print("Detected IDs:", ids)

#     # -----------------------------------------------------
#     # EDGE-TO-EDGE DISTANCE BETWEEN ALL DETECTED MARKERS
#     # -----------------------------------------------------
#     if ids is not None and len(ids) >= 2:

#         # Dictionary to store midpoints for each marker ID
#         edge_midpoints = {}

#         # Compute midpoint of TOP EDGE for every detected marker
#         for i in range(len(ids)):
#             marker_id = int(ids[i][0])
#             c = corners[i][0]

#             # top-left (index 0) and top-right (index 1)
#             top_left = c[0]
#             top_right = c[1]

#             mid_x = (top_left[0] + top_right[0]) / 2
#             mid_y = (top_left[1] + top_right[1]) / 2

#             edge_midpoints[marker_id] = (mid_x, mid_y)

#         # Sort marker IDs so output order is consistent
#         marker_ids = sorted(edge_midpoints.keys())

#         # Compute pairwise distances for ALL marker pairs
#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):
#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 A_mid = edge_midpoints[idA]
#                 B_mid = edge_midpoints[idB]

#                 dist = np.sqrt((B_mid[0] - A_mid[0])**2 +
#                                (B_mid[1] - A_mid[1])**2)

#                 print(f"EDGE→EDGE distance Marker {idA} ↔ Marker {idB}: {dist:.2f} pixels")

#     # Draw detected markers on the frame
#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)
#     else:
#         cv.aruco.drawDetectedMarkers(frame, rejected, ids)

#     # Show the frame
#     cv.imshow("Detected Markers (press q to close)", frame)

#     end = time.time()
#     print(f"Time: {end - start}", end='\r')

#     # Ends the loop if you press 'q'
#     if cv.waitKey(1) == ord('q'):
#         break

# # Release camera
# cam.release()
# cv.destroyAllWindows()
# # THE ABOVE CODE IS EDGE TO EDGE DISTANCE 

# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# ##########
# ## Main ##
# ##########

# # Grab the dictionary and create a detector
# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
# parameters = cv.aruco.DetectorParameters()
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # Open the camera
# print("Opening Camera...", end='\r')
# start = time.time()
# cam = cv.VideoCapture(0)
# end = time.time()
# print(f"Camera opened in {end - start} s")

# print("Press q to end the program (when the video window is selected)")

# # Reading from the camera
# while True:
#     start = time.time()
#     ret, frame = cam.read()

#     # Gray out the image
#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     # Detect the tags
#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     # -----------------------------------------------------
#     # CENTER-TO-CENTER DISTANCE BETWEEN ALL MARKERS
#     # -----------------------------------------------------
#     if ids is not None and len(ids) >= 2:

#         # Dictionary to store marker centers
#         centers = {}

#         for i in range(len(ids)):
#             marker_id = int(ids[i][0])
#             c = corners[i][0]  # four corners
            
#             cx = (c[0][0] + c[1][0] + c[2][0] + c[3][0]) / 4
#             cy = (c[0][1] + c[1][1] + c[2][1] + c[3][1]) / 4

#             centers[marker_id] = (cx, cy)

#         marker_ids = sorted(centers.keys())

#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):
#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 (xA, yA) = centers[idA]
#                 (xB, yB) = centers[idB]

#                 dist = np.sqrt((xB - xA)**2 + (yB - yA)**2)

#                 print(f"CENTER→CENTER distance Marker {idA} ↔ Marker {idB}: {dist:.2f} pixels")

#     # Draw detected markers
#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)
#     else:
#         cv.aruco.drawDetectedMarkers(frame, rejected, ids)

#     cv.imshow("Detected Markers (press q to close)", frame)

#     end = time.time()
#     print(f"Time: {end - start}", end='\r')

#     if cv.waitKey(1) == ord('q'):
#         break

# cam.release()
# cv.destroyAllWindows()




#Edge to edge real pixel to cm 


#############
## Imports ##
#############
import cv2 as cv
import numpy as np
import time

##########
## Main ##
##########

# Grab the dictionary and create a detector
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Calibration variables
KNOWN_CM = 10.0            # Real-world distance between marker 0 and marker 1
REF_A, REF_B = 1, 3        # IDs of calibration markers
cm_per_pixel = None        # Will be computed once when both markers appear

# Open the camera
print("Opening Camera...", end='\r')
start = time.time()
cam = cv.VideoCapture(0)
end = time.time()
print(f"Camera opened in {end - start} s")

print("Press q to end the program (when the video window is selected)")

# Reading from the camera
while True:
    start = time.time()
    ret, frame = cam.read()

    if not ret:
        print("Failed to grab frame.")
        break

    # Gray out the image
    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    # Detect the tags
    corners, ids, rejected = detector.detectMarkers(frame_gray)

    # -----------------------------------------------------
    # EDGE-TO-EDGE DISTANCE BETWEEN ALL DETECTED MARKERS
    # -----------------------------------------------------
    if ids is not None and len(ids) >= 2:

        # Dictionary to store midpoints for each marker ID
        edge_midpoints = {}

        # Compute midpoint of TOP EDGE for every detected marker
        for i in range(len(ids)):
            marker_id = int(ids[i][0])
            c = corners[i][0]

            # top-left (index 0) and top-right (index 1)
            top_left = c[0]
            top_right = c[1]

            mid_x = (top_left[0] + top_right[0]) / 2
            mid_y = (top_left[1] + top_right[1]) / 2

            edge_midpoints[marker_id] = (mid_x, mid_y)

        # Sort marker IDs so output order is consistent
        marker_ids = sorted(edge_midpoints.keys())

        # Compute pairwise distances for ALL marker pairs
        for i in range(len(marker_ids)):
            for j in range(i + 1, len(marker_ids)):
                idA = marker_ids[i]
                idB = marker_ids[j]

                A_mid = edge_midpoints[idA]
                B_mid = edge_midpoints[idB]

                # Pixel distance
                dist_px = np.sqrt((B_mid[0] - A_mid[0])**2 +
                                  (B_mid[1] - A_mid[1])**2)

                print(f"EDGE→EDGE Marker {idA} ↔ {idB}: {dist_px:.2f} px")

                # -------------------------------
                # CALIBRATION STEP (only once)
                # -------------------------------
                if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):
                    if cm_per_pixel is None:  # Only calibrate once
                        cm_per_pixel = KNOWN_CM / dist_px
                        print(f"[CALIBRATION] Pixel Scale: 1 px = {cm_per_pixel:.5f} cm")

                # -------------------------------
                # PIXEL → CM conversion (after calibration)
                # -------------------------------
                if cm_per_pixel is not None:
                    dist_cm = dist_px * cm_per_pixel
                    print(f"Distance Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

    # Draw detected markers on the frame
    if ids is not None:
        cv.aruco.drawDetectedMarkers(frame, corners, ids)
    else:
        cv.aruco.drawDetectedMarkers(frame, rejected, ids)

    # Show the frame
    cv.imshow("Detected Markers (press q to close)", frame)

    end = time.time()
    print(f"Time: {end - start}", end='\r')

    # Ends the loop if you press 'q'
    if cv.waitKey(1) == ord('q'):
        break

# Release camera
cam.release()
cv.destroyAllWindows()


















































# #############
# ## Imports ##
# #############
# import cv2 as cv
# import numpy as np
# import time

# #############
# ## SETUP   ##
# #############

# # Load the 4x4 ArUco marker dictionary (50 IDs available)
# aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)

# # Default detector parameters (thresholds, corner refinement, etc.)
# parameters = cv.aruco.DetectorParameters()

# # Create the ArUco detector object
# detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # Calibration settings – real distance between marker 0 and marker 1 is **10 cm**
# REF_A = 0
# REF_B = 1
# KNOWN_CM = 10.0

# # Will store pixels→cm scale once calibration happens
# cm_per_pixel = None


# ############################
# ## OPEN CAMERA & MAIN LOOP
# ############################

# print("Opening Camera...", end="\r")
# start = time.time()

# # Open default camera (index 0)
# cam = cv.VideoCapture(0)

# end = time.time()
# print(f"Camera opened in {end - start:.2f} seconds")
# print("Press 'q' to close the program.\n")


# ############################
# ## FRAME-BY-FRAME PROCESSING
# ############################
# while True:

#     # Read a frame from the camera
#     ret, frame = cam.read()
#     if not ret:
#         print("Could not read frame. Exiting.")
#         break

#     # Convert the BGR camera frame to grayscale (ArUco works faster on grayscale)
#     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

#     # Detect ArUco markers: returns corners, IDs, and rejected candidates
#     corners, ids, rejected = detector.detectMarkers(frame_gray)

#     # Only process distances if 2 or more markers are visible
#     if ids is not None and len(ids) >= 2:

#         ############################
#         ## COMPUTE MARKER CENTERS
#         ############################

#         # Dictionary to store center positions for each marker ID
#         centers = {}

#         # Loop through every detected marker
#         for i in range(len(ids)):

#             marker_id = int(ids[i][0])       # Extract the marker ID
#             c = corners[i][0]                # c is shape (4,2): four corner points

#             # Compute center as the average of all four corners
#             center_x = (c[0][0] + c[1][0] + c[2][0] + c[3][0]) / 4.0
#             center_y = (c[0][1] + c[1][1] + c[2][1] + c[3][1]) / 4.0

#             centers[marker_id] = (center_x, center_y)

#         ###########################################
#         ## PAIRWISE CENTER-TO-CENTER DISTANCES
#         ###########################################

#         # Sort marker IDs for consistent output order
#         marker_ids = sorted(centers.keys())

#         # Compare every marker pair (i < j avoids duplicates)
#         for i in range(len(marker_ids)):
#             for j in range(i + 1, len(marker_ids)):

#                 idA = marker_ids[i]
#                 idB = marker_ids[j]

#                 A_center = centers[idA]
#                 B_center = centers[idB]

#                 # Pixel distance between centers using Euclidean formula
#                 dist_px = np.sqrt((B_center[0] - A_center[0])**2 +
#                                   (B_center[1] - A_center[1])**2)

#                 print(f"[PIXELS] Marker {idA} ↔ {idB}: {dist_px:.2f} px")

#                 ###################################
#                 ## ONE-TIME CALIBRATION STEP
#                 ###################################
#                 # If markers 0 and 1 appear, compute cm_per_pixel ONCE
#                 if cm_per_pixel is None:
#                     if (idA == REF_A and idB == REF_B) or (idA == REF_B and idB == REF_A):
#                         cm_per_pixel = KNOWN_CM / dist_px
#                         print(f"[CALIBRATION DONE] 1 pixel = {cm_per_pixel:.5f} cm")

#                 ###################################
#                 ## CONVERT PIXELS → CENTIMETERS
#                 ###################################
#                 if cm_per_pixel is not None:
#                     dist_cm = dist_px * cm_per_pixel
#                     print(f"[CM]      Marker {idA} ↔ {idB}: {dist_cm:.2f} cm")

#         print()  # Blank line for readability


#     ##########################
#     ## DRAWING & DISPLAY
#     ##########################

#     # Draw detected markers on the frame
#     if ids is not None:
#         cv.aruco.drawDetectedMarkers(frame, corners, ids)

#     # Display the live video feed
#     cv.imshow("ArUco Tracking (press q to close)", frame)

#     # Close program when 'q' is pressed
#     if cv.waitKey(1) == ord('q'):
#         break


# ##########################
# ## CLEAN UP
# ##########################
# cam.release()
# cv.destroyAllWindows()
