"""
Follows a simple tutorial on generating ArUco tags with OpenCV
Source: https://www.geeksforgeeks.org/computer-vision/detecting-aruco-markers-with-opencv-and-python-1/
"""

#############
## Imports ##
#############
import cv2 as cv
import numpy as np

##########
## Main ##
##########

save_path = "./ar_tags/"

# Loading in predefined dictionary of tags
dictionary = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)

# Generate a marker
markerImage = np.zeros((200, 200), dtype=np.uint8)
markerImage_idx = 0 # Valid indices for this dictionary is 0 to 249
border_width = 1 # The number of bits for the thickness of the border; the markers are 6x6 bits, so adding a border of 1 means a 7x7 image
markerImage = cv.aruco.generateImageMarker(dictionary, markerImage_idx, 200, markerImage, border_width)

# Save the image
# TODO Update to os path to make this agnostic to the file system
cv.imwrite(save_path + "marker" + str(markerImage_idx) + ".png", markerImage)

# Get a second image
markerImage_idx = 1 
markerImage = cv.aruco.generateImageMarker(dictionary, markerImage_idx, 200, markerImage, border_width)
cv.imwrite(save_path + "marker" + str(markerImage_idx) + ".png", markerImage)
