#include <cairo/cairo.h>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <random>

#include <vector>

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>


using namespace cv;
using namespace std;
using std::vector;

string BASE = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/";

void putTextCairo(
        cv::Mat &targetImage,
        std::string const& text,
        cv::Point2d centerPoint,
        std::string const& fontFaceStr,
        double fontSize,
        cv::Scalar textColor,
        bool fontItalic,
        bool fontBold)
{
    // Create Cairo
    cairo_surface_t* surface =
            cairo_image_surface_create(
                CAIRO_FORMAT_ARGB32,
                targetImage.cols,
                targetImage.rows);

    cairo_t* cairo = cairo_create(surface);

    // Wrap Cairo with a Mat
    cv::Mat cairoTarget(
                cairo_image_surface_get_height(surface),
                cairo_image_surface_get_width(surface),
                CV_8UC4,
                cairo_image_surface_get_data(surface),
                cairo_image_surface_get_stride(surface));

    // Put image onto Cairo
    cv::cvtColor(targetImage, cairoTarget, cv::COLOR_BGR2BGRA);

    // Set font and write text
    cairo_select_font_face (
                cairo,
                fontFaceStr.c_str(),
                fontItalic ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
                fontBold ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);

    cairo_set_font_size(cairo, fontSize);
    cairo_set_source_rgb(cairo, textColor[2], textColor[1], textColor[0]);

    cairo_text_extents_t extents;
    cairo_text_extents(cairo, text.c_str(), &extents);

    cairo_move_to(
                cairo,
                centerPoint.x - extents.width/2 - extents.x_bearing,
                centerPoint.y - extents.height/2- extents.y_bearing);
    cairo_show_text(cairo, text.c_str());

    // Copy the data to the output image
    cvtColor(cairoTarget, targetImage, cv:: COLOR_BGRA2BGR);

    cairo_destroy(cairo);
    cairo_surface_destroy(surface);
}

vector<string> globVector(const string& pattern){
    string STRING;
    ifstream infile;
    vector<string> v;
    infile.open (pattern);
    cout << pattern << "\n";
    while(!infile.eof()) // To get you all the lines.
    {
        getline(infile,STRING); // Saves the line in STRING.
        v.push_back(STRING);
    }
    infile.close();

    return v;
}

void createMask( Mat & img, Mat & mask, Size textSize, string fontFaceStr, string text){

    // write text to white background
    putTextCairo(img,text, cv::Point2d(textSize.width/2 , textSize.height/2), fontFaceStr, 27, Scalar(0,0,0), false, false);
    

    cvtColor(img, mask, CV_BGR2GRAY);
    threshold(mask, mask, 240, 255, THRESH_BINARY);
    bitwise_not (mask, mask);

    const int range_from  = -5;
    const int range_to    = 5;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    std::uniform_int_distribution<int>  distr1(-10000, 10000);

    Mat fullImageHSV;
    cvtColor(img, fullImageHSV, CV_BGR2HSV);
    for(int y=0;y<fullImageHSV.rows;y++){
        for(int x=0;x< fullImageHSV.cols;x++){
            Vec3b & intensity = fullImageHSV.at<Vec3b>(y,x);
            // cout<< "image : "<< y << "-" << x << "\n";
                
            if((float)(intensity.val[2]) < 0.55 * 255  ){
                //cout<< (float)(intensity.val[0])<< ","<< (float)(intensity.val[1])<< ","<< (float)(intensity.val[2]) <<"\n";
            
                // randomly for black (0,0,0)

                
                if (distr1(generator) % 20 == 0){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 90 + distr(generator);
                    intensity2.val[1] = 13/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 88/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                } 
                else if (distr1(generator) % 20 < 5){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 176/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 57/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } 
                else if (distr1(generator) % 20  < 15){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 160/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            } else {  // randomly for other

                if (distr1(generator) % 15  < 10){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            }
            
        }
    }

    cvtColor(fullImageHSV,img, CV_HSV2BGR);
}

Mat getBackground(Size textSize){

    // globVector("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/bg/");
    vector<string> backgrounds = globVector(BASE + "/utils/backgrounds.txt");

    string background;
    Mat bg_mat;

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(0, backgrounds.size());

    do {
        background = backgrounds.at(distr(generator));
        bg_mat = imread(background);
    } while (bg_mat.cols <= textSize.width + 10 ||  bg_mat.rows <= textSize.height + 10);

    cout << background << "\n";
    cout << bg_mat.cols - textSize.width -10 << "\n";
    cout << bg_mat.rows - textSize.height -10 << "\n";
    
    
    Rect roi;
    
    roi.width = textSize.width ;
    roi.height = textSize.height ;


    std::uniform_int_distribution<int>  distrX(3, bg_mat.cols - textSize.width -10);
    std::uniform_int_distribution<int>  distrY(3, bg_mat.rows -  textSize.height - 10);
    roi.x = distrX(generator);
    roi.y = distrY(generator);

    cout << roi.x <<"-+-"<<  roi.y << "\n";

    return bg_mat(roi);

}

Size getTextSize(string text){
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1.0;
    int thickness = 1;
    int baseline= 1 ;
    
    Size textSize = getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);


    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(3, 8);


    textSize.width -= distr(generator);


    textSize.height += distr(generator) ;
    baseline += thickness;
    return textSize;
}


int main( int argc, const char** argv )
{
    ofstream trainFile;
    trainFile.open("trainFile.txt", std::ios_base::app);
    string text = "khuong d";

    Size textSize = getTextSize(text);


    string fontFaceStr = "Times";//"maszyna";//"Times"; //"Traveling _Typewriter";

    // creat text image  and its mask
    Mat img( textSize.height , textSize.width , CV_8UC3, Scalar(255,255,255));
    Mat mask;
    createMask(img, mask, textSize, fontFaceStr, text);

    
    // make background
    Mat background = getBackground(textSize);

    
    // write text to background
    Mat crop = background.clone();
    putTextCairo(crop,text, cv::Point2d(textSize.width/2 , textSize.height/2), fontFaceStr, 27, Scalar(124/255.0, 125/255.0, 85/255.0), false, false);

    resize(crop, crop, Size(), 10,10, INTER_CUBIC);
    resize(crop, crop, Size(), 0.1,0.1, INTER_AREA);
    double alpha = 0.95;
    Mat dst;
    addWeighted(crop, alpha, background, 1.0-alpha, 0.0, dst);

    // put things together
    img.copyTo(dst,mask);


    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    imwrite(BASE+ "/dataset/words/out2.jpg", dst);

    trainFile << BASE+ "/dataset/words/out2.jpg " << text << "\n";
    trainFile << BASE+ "/dataset/words/out2.jpg " << text << "\n";

    trainFile.close();
    imshow("MyWindow", dst); //display the image which is stored in the 'img' in the "MyWindow" window

    waitKey(0); //wait infinite time for a keypress

    destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

    return 0;
}
