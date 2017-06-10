import os



PATH = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/crop"
TEST = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/test"

if not os.path.exists(TEST):
    os.mkdir(TEST)

i = 0
for f in os.listdir(PATH):
    folder = os.path.join(PATH, f)
    if os.path.isdir(folder):
        for img in os.listdir(folder):
            i +=1

            if i == 300:
                print "========================="

            if i < 300:
                print os.path.join("./crop/" + f, img), img.split(".")[0]
            else:
                print os.path.join("./test/" + f, img), img.split(".")[0]
                if not os.path.exists(os.path.join(TEST, f)):
                    os.mkdir(os.path.join(TEST, f))
                os.rename(os.path.join(folder, img), os.path.join(TEST, f +"/"+img))
print i