import os



IN = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/crop"
EVAL = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/eval_crop"
TEST = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/test_crop"

if not os.path.exists(TEST):
    os.mkdir(TEST)

if not os.path.exists(EVAL):
    os.mkdir(EVAL)

i = 0
for f in os.listdir(IN):
    folder = os.path.join(IN, f)
    if os.path.isdir(folder):
        for img in os.listdir(folder):
            i +=1

            if i == 250 or i == 400:
                print "========================="

            if i < 250:
                print os.path.join("./train_crop/" + f, img), img.split(".")[0]
            elif i < 400:
                print os.path.join("./eval_crop/" + f, img), img.split(".")[0]
                if not os.path.exists(os.path.join(EVAL, f)):
                    os.mkdir(os.path.join(EVAL, f))
                os.rename(os.path.join(folder, img), os.path.join(EVAL, f +"/"+img))
            else:
                print os.path.join("./test_crop/" + f, img), img.split(".")[0]
                if not os.path.exists(os.path.join(TEST, f)):
                    os.mkdir(os.path.join(TEST, f))
                os.rename(os.path.join(folder, img), os.path.join(TEST, f + "/" + img))
print i