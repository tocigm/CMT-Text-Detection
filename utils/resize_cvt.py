import os

import numpy as np
import PIL.Image
import scipy.misc

import cv2

def load_image(path, height, width):
    image = PIL.Image.open(path)
    image = image.convert('L')
    image = np.array(image)
    # squash
    image = scipy.misc.imresize(image, (height, width), 'bilinear')
    print image.shape
    return image


SRC = "/Users/kidio/git/bagiks/CMT-Text-Detection/dataset/temp/labelled"
DES = "/Users/kidio/git/bagiks/CMT-Text-Detection/dataset/temp/gray_labelled"



for f in os.listdir(SRC):
    color_digits_folder = os.path.join(SRC, f)
    gray_digits_folder = os.path.join(DES, f)

    if  not os.path.exists(gray_digits_folder):
        os.mkdir(gray_digits_folder)

    for i in os.listdir(color_digits_folder):
        gray = cv2.imread(os.path.join(color_digits_folder, i),0)
        print gray.shape
        resized = cv2.resize(gray, (28,28))
        cv2.imwrite(os.path.join(gray_digits_folder, i), resized)