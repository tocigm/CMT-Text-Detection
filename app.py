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



@app.route("/")
def index():
    return send_file("templates/index.html")


def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS


@app.route('/upload', methods=['POST'])
def upload_file():
    if request.method == 'POST':
        print("gotit")
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


CRACK_MODEL_JOB_NUM = '20170407-104337-315f'  ## Remember to set this to be the job number for your model
CRACK_DATASET_JOB_NUM = '20170406-014549-1149'  ## Remember to set this to be the job number for your dataset

CRACK_MODEL_FILE = '/usr/share/digits/digits/jobs/' + CRACK_MODEL_JOB_NUM + '/deploy.prototxt'  # Do not change
CRACK_PRETRAINED = '/usr/share/digits/digits/jobs/' + CRACK_MODEL_JOB_NUM + '/snapshot_iter_91719.caffemodel'  # Do not change
CRACK_MEAN_IMAGE = '/usr/share/digits/digits/jobs/' + CRACK_DATASET_JOB_NUM + '/mean.jpg'  # Do not change

# load the mean image
crack_mean_image = caffe.io.load_image(CRACK_MEAN_IMAGE)



PHONE_MODEL_JOB_NUM = '20170412-002927-d232'  ## Remember to set this to be the job number for your model
PHONE_DATASET_JOB_NUM = '20170411-235941-f32b'  ## Remember to set this to be the job number for your dataset

PHONE_MODEL_FILE = '/usr/share/digits/digits/jobs/' + PHONE_MODEL_JOB_NUM + '/deploy.prototxt'  # Do not change
PHONE_PRETRAINED = '/usr/share/digits/digits/jobs/' + PHONE_MODEL_JOB_NUM + '/snapshot_iter_10440.caffemodel'  # Do not change
PHONE_MEAN_IMAGE = '/usr/share/digits/digits/jobs/' + PHONE_DATASET_JOB_NUM + '/mean.jpg'  # Do not change

# load the mean image
phone_mean_image = caffe.io.load_image(PHONE_MEAN_IMAGE)


caffe.set_mode_gpu()
crack_net = caffe.Classifier(CRACK_MODEL_FILE, CRACK_PRETRAINED,
                             channel_swap=(2, 1, 0),
                             raw_scale=255,
                             image_dims=(256, 256))
phone_net = caffe.Classifier(PHONE_MODEL_FILE, PHONE_PRETRAINED,
                             channel_swap=(2, 1, 0),
                             raw_scale=255,
                             image_dims=(256, 256))

@app.route('/pic/<path:filename>')
def send_pic(filename):
    return send_from_directory(UPLOAD_FOLDER, filename)


def detectCracks(inputImg):
    originalImgPath = os.getcwd() + "/upload/" + inputImg
    annotatedImgPath = os.getcwd() + "/upload/annotated_" + inputImg

    # Tell Caffe to use the GPU
    # caffe.set_mode_gpu()

    # Load the input image into a numpy array and display it
    input_image = caffe.io.load_image(originalImgPath)
    img = cv2.imread(originalImgPath)

    has_phone = detect_phone(input_image)
    result = {}

    if has_phone:
        hasCracked, accuracy = detect_crack(annotatedImgPath, img, input_image)
        result['hasPhone'] = True
        result['hasCracked'] = hasCracked
        result['crack_accuracy'] = round(accuracy * 100, 2)
        result['cracked'] = annotatedImgPath.split("/")[-1]

    else:
        result['hasPhone'] = False

    return jsonify(result)


def detect_phone(input_image):
    grid_square = resize(input_image)
    # subtract the mean image
    grid_square -= phone_mean_image
    # make prediction
    prediction = phone_net.predict([grid_square])
    return prediction[0].argmax() > 0

def resize(img):
    cvt_img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    return cv2.resize(cvt_img, (256, 256), interpolation=cv2.INTER_LINEAR)


def detect_crack(annotatedImgPath, img, input_image):
    # Initialize the Caffe model using the model trained in DIGITS

    # Calculate how many 256x256 grid squares are in the image
    rows = input_image.shape[0] / 256
    cols = input_image.shape[1] / 256
    # Initialize an empty array for the detections
    detections = np.zeros((rows, cols))
    # Iterate over each grid square using the model to make a class prediction
    hasCracked = False
    threshold = 0.4
    for i in range(0, rows):
        for j in range(0, cols):
            grid_square = input_image[i * 256:(i + 1) * 256, j * 256:(j + 1) * 256]
            # subtract the mean image
            grid_square -= crack_mean_image
            # make prediction
            prediction = crack_net.predict([grid_square])
            detections[i, j] = prediction[0][1]  # postive score
            if detections[i, j] > threshold:
                cnt = np.array([[j * 256, i * 256], [j * 256, (i + 1) * 256],
                                [(j + 1) * 256, (i + 1) * 256], [(j + 1) * 256, i * 256]])
                cv2.drawContours(img, [cnt], -1, (255, 0, 3), 3)
                hasCracked = True if not hasCracked else hasCracked

    # Display the predicted class for each grid square
    cv2.imwrite(annotatedImgPath, img)

    positive_detections = detections[np.where(detections > threshold)]
    accuracy = np.mean(positive_detections) if positive_detections.size > 0 else 1

    return hasCracked, accuracy


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8888)
