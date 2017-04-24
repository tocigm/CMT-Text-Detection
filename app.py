import os

import numpy as np
from flask import Flask, jsonify, request, redirect, send_from_directory
from flask import send_file
from werkzeug.utils import secure_filename

import numpy as np
import caffe
import cv2

UPLOAD_FOLDER = os.path.join(os.getcwd(), 'upload')
ALLOWED_EXTENSIONS = set(['jpg', 'png', 'jpeg'])
app = Flask(__name__, static_path='/static')
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
caffe.set_mode_gpu()

@app.route("/")
def index():
    return send_file("templates/index.html")


def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS


@app.route('/upload', methods=['POST'])
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




@app.route('/pic/<path:filename>')
def send_pic(filename):
    return send_from_directory(UPLOAD_FOLDER, filename)


def detectCracks(inputImg):
    originalImgPath = os.getcwd() + "/upload/" + inputImg
    annotatedImgPath = os.getcwd() + "/upload/annotated_" + inputImg


    # Load the input image into a numpy array and display it
    input_image = caffe.io.load_image(originalImgPath)
    img = cv2.imread(originalImgPath)
    # Todo: fake
    cv2.imwrite(annotatedImgPath, img)


    has_phone = True
    result = {}

    if has_phone:
        result['hasPhone'] = True
        result['hasCracked'] = True
        result['crack_accuracy'] = 99.99
        result['cracked'] = annotatedImgPath.split("/")[-1]

    else:
        result['hasPhone'] = False

    return jsonify(result)

def detect_phone(img):
    pass

def detect_crack(annotatedImgPath, img, input_image):
    #
    # cv2.imwrite(annotatedImgPath, img)
    #
    # positive_detections = detections[np.where(detections > threshold)]
    # accuracy = np.mean(positive_detections) if positive_detections.size > 0 else 1
    #
    # return hasCracked, accuracy
    pass

if __name__ ==  '__main__':
  app.run(host='0.0.0.0', port=5000)