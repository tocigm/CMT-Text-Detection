# import the necessary packages
import numpy as np
import cv2
from sklearn.cluster import KMeans

def is_dominant_color(img, img_mean):
    image = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    image = image.reshape((image.shape[0] * image.shape[1], 3))

    # cluster the pixel intensities
    clt = KMeans(n_clusters=2)
    clt.fit(image)

    offset = 3
    dominant_colors = np.mean(clt.cluster_centers_, axis=1)
    return img_mean - offset < dominant_colors[0] < img_mean + offset or \
           img_mean - offset < dominant_colors[1] < img_mean + offset