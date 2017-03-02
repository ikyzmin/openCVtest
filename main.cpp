#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{

    Mat image;
    image = imread( "../banana.jpg", 1);
    imwrite("../banana_saved.jpg",image);

    if ( !image.data )
    {
        printf("No image data \n");
        return 0;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    namedWindow("Copy Image",WINDOW_AUTOSIZE);
    Mat copy;
    image.copyTo(copy);
    imshow("Copy Image",copy);
    Mat convertedImage;
    cvtColor(image,convertedImage,CV_RGB2GRAY,0);
    namedWindow("Converted to gray scaled Image",WINDOW_AUTOSIZE);
    imshow("Converted to gray scaled Image",convertedImage);
    Mat resizedImage;
    Size size(100,100);
    resize(image,resizedImage,size,0,0,INTER_LINEAR);
    namedWindow("Resized Image",WINDOW_AUTOSIZE);
    imshow("Resized Image",resizedImage);

    namedWindow("Image ROI [100,100]",WINDOW_AUTOSIZE);
    imshow("Image ROI [100,100]",image(Rect(100,100,100,100)));

    Mat binImage;
    threshold(convertedImage,binImage,175,255,CV_THRESH_BINARY);
    namedWindow("Bin image",WINDOW_AUTOSIZE);
    imshow("Bin image",binImage);

    vector<vector<Point>> contours;
    findContours(binImage,contours,CV_RETR_TREE,CV_CHAIN_APPROX_TC89_L1);

    Scalar color(0,255,0);
    namedWindow("Contour",WINDOW_AUTOSIZE);
    drawContours(copy,contours,-1,color,2);
    imwrite("../CV_CHAIN_APPROX_TC89_L1.jpg",copy);
    imshow("Contour",copy);

    copy.release();
    convertedImage.release();
    resizedImage.release();
    image.release();
    binImage.release();


    waitKey(0);

    return 0;
}