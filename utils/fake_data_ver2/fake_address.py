import os
import cv2
import numpy as np

def getRandomLetter(letter, LETTERS_DICT):
    if letter not in LETTERS_DICT:
        letter = letter.swapcase()
    letters = LETTERS_DICT[letter]
    index = np.random.randint(len(letters))

    return letters [index]


def getLetterDict(letters_dic_path):
    letters = {}
    for letter in os.listdir(letters_dic_path):
        letter_dic_path = os.path.join(letters_dic_path, letter)
        if os.path.isdir(letter_dic_path):
            a_letter = []
            for l in os.listdir(letter_dic_path):
                a_letter.append(os.path.join(letter_dic_path, l))

            letters[letter.replace("_", '')] = a_letter
    return letters


if __name__ == '__main__':
    i = 0
    TRAIN = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/train"
    VAL = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/eval"
    LETTERS_DICT = getLetterDict("/Users/kidio/git/bagiks/CMT-Text-Detection/dataset/crop_quequan/")

    with open(os.path.realpath('../../dataset/words.txt'), 'r') as f:
        words = f.readlines()

    with open(os.path.realpath('../../dataset/train.txt'), 'wb') as w:
        with open(os.path.realpath('../../dataset/eval.txt'), 'wb') as t:

            for line in words:
                i +=1
                word = line.strip("\r\n").title()
                img = None
                print word
                for letter in word:
                    letter_path = getRandomLetter(letter, LETTERS_DICT)
                    letter_img = cv2.imread(letter_path)
                    if img is not None:
                        img = np.concatenate((img, letter_img), axis=1)
                    else:
                        img = letter_img
                if i < 35560:#29500:
                    img_path = os.path.join(TRAIN, word + ".jpg")
                    cv2.imwrite(img_path, img)
                    w.write(img_path + " " + word.lower())
                    w.write("\n")
                else:
                    img_path = os.path.join(VAL, word + ".jpg")
                    cv2.imwrite(img_path, img)
                    t.write(img_path + " " + word.lower())
                    t.write("\n")
    print i