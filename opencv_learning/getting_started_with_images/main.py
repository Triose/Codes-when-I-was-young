# goals:
# 1. learn how to read an image, how to display it and how to save it back
# 2. learn the following functions: cv2.imread(), cv2.imshow(), cv2.imwrite()

import numpy as np
import cv2


# 1. Read an image
# cv2.imread(fir, sec):
# fir is the full path of one image
# sec's choices is as follows:
#   -1:  cv2.IMREAD_COLOR:       loads a color image
#    0:  cv2.IMREAD_GRAYSCALE:   loads image in grayscale mode
#    1:  cv2.IMREAD_UNCHANGED:   loads image as such including alpha channel

img = cv2.imread('test.jpeg', 0)    # 读入一个图片
# cv2.imshow('my photo', img) # 弹窗
# cv2.waitKey(0)              # 等待键入任意字符
# cv2.destroyAllWindows()     # 删除创建的窗口
print()
# cv2.namedWindow('image', cv2.WINDOW_NORMAL)     # 创建一个window 里面什么都没有名字是image 
# cv2.imshow('image', img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# 把图片写到工作目录中
# cv2.imwrite('newpic.png', img)

print();print()

# Sum up
img = cv2.imread('test.jpeg', 0)
cv2.imshow('my photo', img)
k = cv2.waitKey(0)
if k == 27:
    cv2.destroyAllWindows()
elif k == ord('s'):
    cv2.imwrite('triaan.jpg', img)
    cv2.destroyAllWindows()



