#include <cairo/cairo.h>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <random>

using namespace cv;
using namespace std;

void putTextCairo(
        cv::Mat &targetImage,
        std::string const& text,
        cv::Point2d centerPoint,
        std::string const& fontFace,
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
                fontFace.c_str(),
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


int main( int argc, const char** argv )
{
    //Mat image = imread("/Users/kidio/Downloads/000002.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
     
    string text = "NHUNG";
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1.0;
    int thickness = 2;
    int baseline= 3;

    Size textSize = getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);
    baseline += thickness;

    Size textSize2 = getTextSize(text, fontFace,
                            1, thickness, &baseline);
    
    std::cout << textSize.width << textSize.height << "\n";
    // center the text

    Mat img( textSize2.height+ 10,textSize2.width, CV_8UC3, Scalar(255,255,255));
    Mat mask;
    string fontFace2 = "Times";//"maszyna";//"Times"; //"Traveling _Typewriter";
    // write text to white background
    putTextCairo(img,text, cv::Point2d(textSize2.width/2, textSize2.height/2+ 5), fontFace2, 27, Scalar(0,0,0), false, false);
    

    cvtColor(img, mask, CV_BGR2GRAY);
    threshold(mask, mask, 240, 255, THRESH_BINARY);
    bitwise_not ( mask, mask);

    imwrite("./text.jpg", img);

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
                cout<< (float)(intensity.val[0])<< ","<< (float)(intensity.val[1])<< ","<< (float)(intensity.val[2]) <<"\n";
            
                // randomly for black (0,0,0)

                
                if (distr1(generator) % 20 == 0){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 90 + distr(generator);
                    intensity2.val[1] = 13/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 88/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                } 
                else if (distr1(generator) % 20 < 5){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 176/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 57/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } 
                else if (distr1(generator) % 20  < 15){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 160/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            } else {  // randomly for other

                if (distr1(generator) % 15  < 10){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            }
            
        }
    }

    cvtColor(fullImageHSV,img, CV_HSV2BGR);

    // write text to CMT background

    Mat img3 = imread("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/CMT/048805307.jpg");
   
    std::cout << img3.rows << "-" << img3.cols << "\n";

    Rect roi;
    roi.x = 410;
    roi.y = 200;
    roi.width = textSize.width;
    roi.height = textSize.height + 10;

    Mat crop = img3(roi);


    std::cout << crop.rows << "-" << crop.cols << "\n";
    Mat background = crop.clone(); 
    putTextCairo(crop,text, cv::Point2d(textSize.width/2, textSize.height/2+ 5), fontFace2, 27, Scalar(124/255.0, 125/255.0, 85/255.0), false, false);
   
    resize(crop, crop, Size(), 10,10, INTER_CUBIC);
    resize(crop, crop, Size(), 0.1,0.1, INTER_AREA);
    double alpha = 0.95;
    Mat dst;
    addWeighted(crop, alpha, background, 1.0-alpha, 0.0, dst);

    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    img.copyTo(dst,mask);

    imwrite("./out.jpg", dst);

    imshow("MyWindow", dst); //display the image which is stored in the 'img' in the "MyWindow" window

    waitKey(0); //wait infinite time for a keypress

    destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

    return 0;
}
