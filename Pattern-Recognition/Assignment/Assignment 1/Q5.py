import cv2
import numpy as np
import matplotlib.pyplot as plt

def l2(A,B,C,D,E,F):
    cur_sum1 = np.sum(np.square(A - D))
    cur_sum1 += np.sum(np.square(B - E))
    cur_sum1 += np.sum(np.square(C - F))
    return (cur_sum1)**0.5

def l1(A,B,C,D,E,F):
    cur_sum1 = np.sum(np.abs(A - D))
    cur_sum1 += np.sum(np.abs(B - E))
    cur_sum1 += np.sum(np.abs(C - F))
    return (cur_sum1)

def construct_hist(R, G, B, image_name):
    plt.plot(R, label = 'Red component', color = 'Red')
    plt.plot(G, label = 'Green component', color = 'Green')
    plt.plot(B, label = 'Blue component', color = 'Blue')

    plt.legend()
    plt.xlim([0, 256])
    plt.suptitle("RGB scale for " + str(image_name), fontweight = "bold")
    plt.xlabel("Color value", fontweight = "bold")
    plt.ylabel("Pixel count", fontweight = "bold")
    plt.show()

img = cv2.imread('Reference_image2.jpg')
B = cv2.calcHist([img], [0], None, [256], [0,256])
G = cv2.calcHist([img], [1], None, [256], [0,256])
R = cv2.calcHist([img], [2], None, [256], [0,256])

img2 = cv2.imread('Query_image.jpg')
B2 = cv2.calcHist([img2], [0], None, [256], [0,256])
G2 = cv2.calcHist([img2], [1], None, [256], [0,256])
R2 = cv2.calcHist([img2], [2], None, [256], [0,256])

img3 = cv2.imread('Reference_image1.jpg')
B3 = cv2.calcHist([img3], [0], None, [256], [0,256])
G3 = cv2.calcHist([img3], [1], None, [256], [0,256])
R3 = cv2.calcHist([img3], [2], None, [256], [0,256])

print("\nL1 distance between Query_image and Reference_image1 : ", l1(R2, G2, B2, R3, G3, B3))
print("L1 distance between Query_image and Reference_image2 : ", l1(R2, G2, B2, R, G, B))

print("\nL2 distance between Query_image and Reference_image1 : ", l2(R2, G2, B2, R3, G3, B3))
print("L2 distance between Query_image and Reference_image2 : ", l2(R2, G2, B2, R, G, B))

if(l1(R2, G2, B2, R3, G3, B3) < l1(R2, G2, B2, R, G, B)):
	print("\nAccording to L1 distance, Query_image and Reference_image1 are similar")
else:
	print("\nAccording to L1 distance, Query_image and Reference_image2 are similar")

if(l2(R2, G2, B2, R3, G3, B3) < l2(R2, G2, B2, R, G, B)):
	print("\nAccording to L2 distance, Query_image and Reference_image1 are similar")
else:
	print("\nAccording to L2 distance, Query_image and Reference_image2 are similar")

construct_hist(R3, G3, B3, 'Reference_image1.jpg')
construct_hist(R2, G2, B2, 'Query_image.jpg')
construct_hist(R, G, B, 'Reference_image2.jpg')