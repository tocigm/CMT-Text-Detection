import cv2
import numpy as np
import os
from Digits.example import classify
import random
from  color_classifier import is_dominant_color
BASE = "/home/ubuntu/CMT-Text-Detection/"

def remove_noise(img_path):
    img = cv2.imread(img_path)

    if not is_dominant_color(img, 165):
        return ""

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

    return foreground

def crop_digits(img_path, output_path, crop_original_img = False):

    foreground = remove_noise(img_path)

    save_path = os.path.join(output_path, img_path.split("/")[-1][:-4]) #BASE+ "/Digits/crop/"
    if not os.path.isdir(save_path):
        os.mkdir(save_path)

    if crop_original_img:
        split_digits_from_img(foreground, save_path, cv2.imread(img_path))
    else:
        split_digits_from_img(foreground, save_path, None)

    return save_path

def split_digits_from_img(img, path, original_img = None):
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
    # print abc.shape
    fake = np.zeros(abc.shape).astype('uint8')

    blurred = cv2.GaussianBlur(abc, (5, 5), 0)
    xyz = cv2.Canny(abc, 200, 255)

    cnts, _ = cv2.findContours(xyz, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

    # print len(cnts)
    img_name = path.split("/")[-1]
    i = 0
    for c in cnts:
        if cv2.arcLength(c, True) > 100:
            i = i + 1
            x, y, w, h = cv2.boundingRect(c)

            # print cv2.boundingRect(c)

            num_of_crop = 6
            for j in xrange(num_of_crop):
                left_pad = random.randint(2,10)
                right_pad = random.randint(2,10)
                core = img[y:y + h, x:x + w] if original_img is None else original_img[y:y + h, x-left_pad:x + w +right_pad]

                # npad = ((10, 10), (10, 10))
                # pad_img = np.pad(core, pad_width=npad, mode='constant', constant_values=255)

                cv2.imwrite(path +"/"+ str(x) + "_" + str(y)+"_"+img_name +"+"+str(j)+ ".jpg", core)



# FILE = BASE + "upload/460884941172522-2015.12.05-11.36.03.jpg"

def crop_CMT_digits_by_size(img_path, output_path):
    img = cv2.imread(img_path)
    img_name = img_path.split("/")[-1][:-4]
    y,x,_ = img.shape
    digit_size = int(x/9)

    save_path = os.path.join(output_path, img_name)  # BASE+ "/Digits/crop/"
    if not os.path.isdir(save_path):
        os.mkdir(save_path)

    for i in xrange(9):
        l = i*digit_size if i < 8 else i*digit_size - 8
        r = (i+1)*digit_size if i < 8 else (i+1)*digit_size - 8
        cv2.imwrite(save_path + "/" + str(i) + "_" + img_name + ".jpg",
                    cv2.cvtColor(img[:, l:r,:], cv2.COLOR_BGR2GRAY))

    return save_path


def recognize_CMT_number (caffenet, img_path):
    saved_path = crop_CMT_digits_by_size(img_path, BASE+ "/Digits/crop/")
    # xxx("/Users/kidio/git/bagiks/CMT-Text-Detection/upload/604684941172522-2015.12.05-11.36.03.jpg")

    if saved_path == "":
        return saved_path

    IMG_FOLDER = saved_path
    imgs = []
    for i in os.listdir(IMG_FOLDER):
        imgs.append(os.path.join(IMG_FOLDER, i))


    result = classify(
        caffenet,
        BASE + "/models/digit/mnist_model/deploy.prototxt",  # args['deploy_file'],
        imgs,  # args['image_file'],
        mean_file=BASE + "/models/digit/mnist_model/mean_.binaryproto",  # args['mean'],
        labels_file=BASE + "/models/digit/mnist_model/labels.txt",  # args['labels'],
        batch_size=1,  # args['batch_size'],
        use_gpu=True  # not args['nogpu'],
    )
    return result