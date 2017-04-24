import os
import cv2
import numpy as np
from utils import imutils

PATH = "/Users/kidio/git/motionscloud/CracksDetection/dataset/test"

def mean_size():
    if os.path.exists(PATH):
        files = os.listdir(PATH)
        width = []
        height = []
        for m in files:
            file = os.path.join(PATH, m)
            im = cv2.imread(file)
            w, h, _ = im.shape
            width.append(w)
            height.append(h)

        print(np.mean(width), np.mean(height))


def convert2GRAY():
    if os.path.exists(PATH):
        files = os.listdir(PATH)
        width = []
        height = []
        for m in files:
            file = os.path.join(PATH, m)
            im = cv2.imread(file)
            gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
            cv2.imwrite(file, gray)


def resize(width):
    if os.path.exists(PATH):
        files = os.listdir(PATH)

        for m in files:
            file = os.path.join(PATH, m)
            im = cv2.imread(file)
            im = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
            resized = imutils.resize(im, width)
            print resized.shape
            cv2.imwrite(file, resized)
