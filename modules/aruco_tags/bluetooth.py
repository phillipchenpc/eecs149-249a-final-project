# # """
# # Follows simple tutorial on how to detect AR tags in video
# # Source: https://docs.opencv.org/4.x/d5/dae/tutorial_aruco_detection.html
# # https://www.geeksforgeeks.org/python/python-opencv-capture-video-from-camera/#
# # """

# # #############
# # ## Imports ##
# # #############
# # import cv2 as cv
# # import numpy as np
# # import time

# # ##########
# # ## Main ##
# # ##########

# # # Grab the dictionary and create a detector
# # aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
# # parameters = cv.aruco.DetectorParameters()
# # detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# # # Open the camera
# # print("Opening Camera...", end='\r')
# # start = time.time()
# # cam = cv.VideoCapture(0)
# # end = time.time()
# # print(f"Camera opened in {end - start} s")

# # print("Press q to end the program (when the video window is selected)")

# # # Reading from the camera
# # while True:
# #     start = time.time()
# #     ret, frame = cam.read()

# #     # Gray out the image
# #     frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

# #     # Detect the tags
# #     corners, ids, rejected = detector.detectMarkers(frame_gray)

# #     # -------------------------------
# #     # Extract IDs and corner points
# #     # -------------------------------
# #     if ids is not None:
# #         for i in range(len(ids)):
# #             marker_id = int(ids[i][0])
# #             marker_corners = corners[i][0]

# #             print(f"Marker {marker_id}:")
# #             print(f"  Top-left:     {marker_corners[0]}")
# #             print(f"  Top-right:    {marker_corners[1]}")
# #             print(f"  Bottom-right: {marker_corners[2]}")
# #             print(f"  Bottom-left:  {marker_corners[3]}")
# #             print()

# #     # Draw out detections
# #     if ids is not None:
# #         cv.aruco.drawDetectedMarkers(frame, corners, ids)
# #     else:
# #         cv.aruco.drawDetectedMarkers(frame, rejected, ids)

# #     cv.imshow("Detected Markers (press q to close)", frame)

# #     end = time.time()
# #     print(f"Time: {end - start}", end='\r')

# #     # Ends the loop if you press 'q'
# #     if cv.waitKey(1) == ord('q'):
# #         break

# # # Release camera
# # cam.release()
# # cv.destroyAllWindows()


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
"""
Follows simple tutorial on how to detect AR tags in video
Source: https://docs.opencv.org/4.x/d5/dae/tutorial_aruco_detection.html
https://www.geeksforgeeks.org/python/python-opencv-capture-video-from-camera/#
"""

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

    # Gray out the image
    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    # Detect the tags
    corners, ids, rejected = detector.detectMarkers(frame_gray)

    # Draw out detections
    if ids is not None:
        cv.aruco.drawDetectedMarkers(frame, corners, ids)
    else:
        cv.aruco.drawDetectedMarkers(frame, rejected, ids)
    cv.imshow("Detected Markers (press q to close)", frame)

    end = time.time()
    print(f"Time: {end - start}", end='\r')
    # Ends the loop if you press 'q'
    if cv.waitKey(1) == ord('q'):
        break


# Release camera
cam.release()
# Destroy the window
cv.destroyAllWindows()