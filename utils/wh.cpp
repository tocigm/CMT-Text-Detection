#include <cairo/cairo.h>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>
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
     Mat image = imread("/Users/kidio/Downloads/000002.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
     image = image.clone();
     if (image.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }
    string text = "NHUNG";
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1.0;
    int thickness = 2;
    int baseline= 3;

    Size textSize = getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);
    baseline += thickness;
    
    std::cout << textSize.width << textSize.height << "\n";
    // center the text
    Mat img( textSize.height+ 10,textSize.width, CV_8UC4, Scalar(0,0,0));
    // then put the text itself
    // putText(img, text, textOrg, fontFace, fontScale,
    //    Scalar::all(255), thickness, font);
    string fontFace2 = "Times";//"maszyna";//"Times"; //"Traveling _Typewriter";

    
    Mat img3 = imread("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/CMT/048805307.jpg");
   
    std::cout << img3.rows << "-" << img3.cols << "\n";
    Rect roi;
    roi.x = 410;
    roi.y = 200;
    roi.width = textSize.width;
    roi.height = textSize.height + 10;

     Mat img4 = img3(roi);
    std::cout << img4.rows << "-" << img4.cols << "\n";
    Mat img5 = img4.clone(); 
    putTextCairo(img4,text, cv::Point2d(textSize.width/2, textSize.height/2+ 5), fontFace2, 27, Scalar(124/255.0, 125/255.0, 85/255.0), false, false);
   
    //resize(img4, img4, Size(), 4,4);
    //resize(img4, img4, Size(), 0.25,0.25);
    resize(img4, img4, Size(), 10,10, INTER_CUBIC);
    resize(img4, img4, Size(), 0.1,0.1, INTER_AREA);
    double alpha = 1;
    Mat dst;
    addWeighted(img4, alpha, img5, 1.0-alpha, 0.0, dst);


    //putTextCairo(img, "Vũ Khương Duy2", cv::Point2d(1,1), "Times", 45, Scalar(0,0,255), false, false);
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    imwrite("./out.jpg", dst);
     imshow("MyWindow", dst); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(0); //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
