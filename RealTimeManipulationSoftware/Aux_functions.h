/*
* Aux_functions.h
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/


#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

Mat getHistogram(Mat frame);

//Basics
Mat changeBrightnessContrast(Mat frame, double alpha, double beta);
Mat getRedImage(Mat frame);
Mat getGreenImage(Mat frame);
Mat getBlueImage(Mat frame);
Mat invertImage(Mat frame);
Mat drawGrid(Mat frame, int dist = 20, Scalar color = Scalar(255, 255, 255));
Mat convertToColor(Mat frame, int colorSpace = CV_RGB2HLS);
Mat convertToColorTwoTimes(Mat frame, int colorSpace = CV_RGB2HLS, int colorSpace2 = CV_HLS2RGB);
Mat changeColor(Mat frame, Vec3b colorfrom, Vec3b colorTo);


// Segmentation
Mat segmentation(Mat frame, int x, int y);

// Video operations
Mat differenceBetweenTwoFrames(Mat firstFrame, Mat secondFrame);
Mat backgroundSubtractionKNN(Mat frame);
Mat backgroundSubtractionMOG2(Mat frame);

// Automatic operations
Mat contrastStreching(Mat frame);
Mat equalizeHistogram(Mat frame);
Mat BrightnessAndContrastAuto(Mat src, float clipHistPercent);
Mat getBackProjection(Mat frame);

// Smoothing images
Mat meanBlurFrame(Mat frame, int size);
Mat medianBlurFrame(Mat frame, int size);
Mat gaussianBlurFrame(Mat frame, int size, double sigmaX = 50);

// Morphologic transformations
Mat erodeFrame(Mat frame, int shape, int x, int y, int thresholdValue=-1);
Mat dilateFrame(Mat frame, int shape, int x, int y, int thresholdValue = -1);
Mat openingFrame(Mat frame, int shape, int x, int y, int thresholdValue = -1);
Mat closingFrame(Mat frame, int shape, int x, int y, int thresholdValue = -1);
Mat morphologicalGradient(Mat frame, int shape, int x, int y, int thresholdValue = -1);
Mat topHat(Mat frame, int shape, int x, int y, int thresholdValue = -1);
Mat blackHat(Mat frame, int shape, int x, int y, int thresholdValue = -1);

// Thresholding operations
Mat thresholding(Mat frame, int thresholdValue = 100, int maxColor = 255, int thresholdType = THRESH_BINARY);

// Edge detectors
Mat sobelOperator(Mat frame, double x, double y, int size);
Mat cannyDetector(Mat frame, double threshold1, double threshold2);
Mat detectEdgesWithDilate(Mat frame);
Mat finalAndDrawContours(Mat frame, int threshold, Scalar color);
Mat laplaceOperator(Mat frame, int kernel_size, int scale, int delta);


// Corner detection
Mat harrisCornerDetection(Mat frame, int threshold, int blockSize, int apertureSize, double k);
Mat shiTomasiCornerDetector(Mat frame, int maxCorners = 23, double qualityLevel = 0.01, double minDistance = 10, int blockSize = 3, bool useHarrisDetector = false, double k = 0.04);
