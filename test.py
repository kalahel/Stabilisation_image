import numpy as np
import cv2

img = cv2.imread('example2.jpg', flags=cv2.IMREAD_COLOR)
cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()

print('Image shape :', img.shape)
