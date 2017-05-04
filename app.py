import os

import numpy as np
from flask import Flask, jsonify, request, redirect, send_from_directory
from flask import send_file
from werkzeug.utils import secure_filename

import numpy as np
import caffe
import cv2

from cfg import Config as cfg
from CTPN.other import draw_boxes, resize_im, CaffeModel
import cv2, os, caffe, sys
from CTPN.detectors import TextProposalDetector, TextDetector
from CTPN.utils.timer import Timer
import os.path as osp
import random
from  Digits.detect_digit import recognize_CMT_number
from Digits.example import  get_net

from Digits.color_classifier import is_dominant_color


UPLOAD_FOLDER = os.path.join(os.getcwd(), 'upload')
ALLOWED_EXTENSIONS = set(['jpg', 'png', 'jpeg'])
app = Flask(__name__, static_path='/static')
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
NET_DEF_FILE="models/deploy.prototxt"
MODEL_FILE="models/ctpn_trained_model.caffemodel"

caffe.set_mode_gpu()
# initialize the text block detectors
text_proposals_detector=TextProposalDetector(CaffeModel(NET_DEF_FILE, MODEL_FILE))
text_detector=TextDetector(text_proposals_detector)


BASE = "/home/ubuntu/CMT-Text-Detection/"
digits_net = get_net(os.path.join(BASE, "models/digit/mnist_model/snapshot_iter_3080.caffemodel"),
                     os.path.join(BASE, "models/digit/mnist_model/deploy.prototxt"))


@app.route("/")
def index():
    return send_file("templates/index.html")


def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS


@app.route('/upload', methods=['POST', 'GET'])
def upload_file():
    if request.method == 'POST':
        print("uploaded file")
        # check if the post request has the file part
        if 'file' not in request.files:
            print('No file part')
            return redirect(request.url)
        file = request.files['file']
        # if user does not select file, browser also
        # submit a empty part without filename
        if file.filename == '':
            print('No selected file')
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
            return detectCracks(filename)
    return jsonify(result={"status": 200})



@app.route('/pic/<path:filename>')
def send_pic(filename):
    return send_from_directory(UPLOAD_FOLDER, filename)


def detectCracks(inputImg):
    originalImgPath = os.getcwd() + "/upload/" + inputImg
    annotatedImgPath = os.getcwd() + "/upload/annotated_" + inputImg


    # Load the input image into a numpy array and display it
    input_image = caffe.io.load_image(originalImgPath)
    img = cv2.imread(originalImgPath)


    img, f = resize_im(img, cfg.SCALE, cfg.MAX_SCALE)
    text_lines = text_detector.detect(img)

    print text_lines
    scores = []
    CMT_number = ""
    for line in text_lines:
        x1, y1, x3, y3, score = line
        cnt = np.array([[x1, y1], [x1, y3], [x3, y3], [x1, y3]]).astype('int32')

        cropped = remove_pad(img.copy()[y1:y3, x1:x3])
        name = os.getcwd() + "/upload/"+str(random.randint(1,10000))+inputImg

        if is_dominant_color(cropped, 165):
            cv2.imwrite(name, cropped)

            temp = recognize_CMT_number(digits_net, name)
            if temp is not None and temp != "":
                CMT_number = temp

        cv2.drawContours(img, [cnt], -1, (255, 0, 0), 3)
        scores.append(score)

    cv2.imwrite(annotatedImgPath, img)

    has_phone = True
    result = {}

    if has_phone:
        result['hasPhone'] = True
        result['hasCracked'] = True
        result['crack_accuracy'] = str(np.mean(np.array(scores)) * 100)[:6]
        result['cracked'] = annotatedImgPath.split("/")[-1]
        result['CMT'] = CMT_number

    else:
        result['hasPhone'] = False

    return jsonify(result)

def remove_pad(img):
    y, x, _ = img.shape
    return img[y - 37:y, 53:359, :]

if __name__ ==  '__main__':
  app.run(host='0.0.0.0', port=5000)