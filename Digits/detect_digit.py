import cv2
import numpy as np
import os
from Digits.example import classify
#BASE = "/Users/kidio/git/bagiks/CMT-Text-Detection/"
BASE = "/home/ubuntu/CMT-Text-Detection/"

def extract_digits(img, path):
    abc = img.copy()
    abc = cv2.bitwise_not(abc)
    x, y = abc.shape
    im = np.zeros(abc.shape).astype('uint8')

    size = 3
    for i in range(x - size):
        for j in range(y - size):
            if abc[i, j] > 80 and i > size and j > size:
                im[i - size:i + size, j - size:j + size] = 255

    abc = im
    print abc.shape
    fake = np.zeros(abc.shape).astype('uint8')

    blurred = cv2.GaussianBlur(abc, (5, 5), 0)
    xyz = cv2.Canny(abc, 200, 255)

    cnts, _ = cv2.findContours(xyz, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

    print len(cnts)
    i = 0
    for c in cnts:
        if cv2.arcLength(c, True) > 100:
            i = i + 1
            x, y, w, h = cv2.boundingRect(c)

            print cv2.boundingRect(c)

            core = img[y:y + h, x:x + w]
            npad = ((10, 10), (10, 10))
            pad_img = np.pad(core, pad_width=npad, mode='constant', constant_values=255)

            cv2.imwrite(path + str(x) + "_" + str(y) + ".jpg", np.array(pad_img))


def xxx(path):
    img = cv2.imread(path)

    img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # lower mask (0-10)
    lower_red = np.array([0, 0, 0])
    upper_red = np.array([180, 255, 30])
    mask0 = cv2.inRange(img_hsv, lower_red, upper_red)

    # upper mask (170-180)
    lower_red = np.array([0, 40, 40])
    upper_red = np.array([180, 255, 255])
    mask1 = cv2.inRange(img_hsv, lower_red, upper_red)

    # join my masks
    mask = mask0 + mask1

    # set my output img to zero everywhere except my mask
    output_img = img.copy()
    # output_img[np.where(mask==0)] = 0
    output_img = cv2.bitwise_and(output_img, output_img, mask=mask1)

    output_img = cv2.cvtColor(output_img, cv2.COLOR_BGR2GRAY)
    new_mask = np.zeros(output_img.shape, np.uint8)

    new_mask[:] = 255

    foreground = cv2.bitwise_not(output_img, output_img, mask=new_mask)

    # plt.imshow(cv2.cvtColor(abc, cv2.COLOR_BGR2GRAY))

    h, w = foreground.shape
    for i in range(h - 1):
        for j in range(w - 1):
            if foreground[i, j] < 80:
                foreground[i, j] = 255

    kernel = np.ones((2, 2), np.uint8)
    # abc = cv2.morphologyEx(abc, cv2.MORPH_OPEN, kernel)
    foreground = cv2.dilate(foreground, kernel, iterations=1)
    save_path = "/Users/kidio/git/bagiks/CMT-Text-Detection/Digits/crop/"+ path.split("/")[-1][:-5]
    if not os.path.isdir(save_path):
        os.mkdir(save_path)
    extract_digits(foreground, save_path)

    return save_path



FILE = BASE + "upload/460884941172522-2015.12.05-11.36.03.jpg"

saved_path = xxx(FILE)
# xxx("/Users/kidio/git/bagiks/CMT-Text-Detection/upload/604684941172522-2015.12.05-11.36.03.jpg")


BASE = "/home/ubuntu/CMT-Text-Detection/"
IMG_FOLDER = saved_path
imgs = []
for i in os.listdir(IMG_FOLDER):
    imgs.append(os.path.join(IMG_FOLDER, i))

result = classify(
    BASE + "/models/digit/mnist_model/snapshot_iter_21120.caffemodel",  # args['caffemodel'],
    BASE + "/models/digit/mnist_model/deploy.prototxt",  # args['deploy_file'],
    imgs,  # args['image_file'],
    BASE + "/models/digit/mnist_data/mean.binaryproto",  # args['mean'],
    BASE + "/models/digit/mnist_data/labels.txt",  # args['labels'],
    1,  # args['batch_size'],
    True  # not args['nogpu'],
)

print result
