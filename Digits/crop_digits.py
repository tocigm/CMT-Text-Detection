import numpy as np
from Digits.color_classifier import is_dominant_color
from Digits.detect_digit import crop_digits
from cfg import Config as cfg
from CTPN.other import draw_boxes, resize_im, CaffeModel
import cv2, os, caffe, sys
from CTPN.detectors import TextProposalDetector, TextDetector

NET_DEF_FILE="models/deploy.prototxt"
MODEL_FILE="models/ctpn_trained_model.caffemodel"

caffe.set_mode_gpu()
# initialize the text block detectors
text_proposals_detector=TextProposalDetector(CaffeModel(NET_DEF_FILE, MODEL_FILE))
text_detector=TextDetector(text_proposals_detector)


BASE = "/home/ubuntu/CMT-Text-Detection/"

if __name__ ==  '__main__':
    CMT_photos_path = BASE + "/dataset/CMT/"
    ID_photos_path = BASE + "/dataset/ID/"
    digits_path = BASE + "/dataset/digits/"

    for CMT_photo in os.listdir(CMT_photos_path):
        img = cv2.imread(os.path.join(CMT_photos_path, CMT_photo))

        img, f = resize_im(img, cfg.SCALE, cfg.MAX_SCALE)
        text_lines = text_detector.detect(img)

        print text_lines
        scores = []
        CMT_number = ""
        for line in text_lines:
            x1, y1, x3, y3, score = line
            cnt = np.array([[x1, y1], [x1, y3], [x3, y3], [x1, y3]]).astype('int32')

            cropped = img.copy()[y1:y3, x1:x3]
            if is_dominant_color(cropped, 165):
                name = ID_photos_path + CMT_photo
                cv2.imwrite(name, cropped)

                crop_digits(name, digits_path, crop_original_img= True )

