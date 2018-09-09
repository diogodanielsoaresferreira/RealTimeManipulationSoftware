/*
* Aux_functions.cpp
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
#include <opencv2/video.hpp>
#include "Aux_functions.h"


using namespace cv;
using namespace std;

Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 Background subtractor
Ptr<BackgroundSubtractor> pKNN = createBackgroundSubtractorKNN(); //KNN Background subtractor

Mat changeBrightnessContrast(Mat frame, double alpha, double beta){

	Mat dst;
	frame.convertTo(dst, -1, alpha, beta);
	return dst;
}

Mat getRedImage(Mat frame) {
	Mat modFrame;
	vector<Mat> spl;
	split(frame, spl);
	for (int i = 0; i < 3; ++i)
		if (i != 2)
			spl[i] = Mat::zeros(frame.size(), spl[0].type());
	merge(spl, modFrame);
	return modFrame;
}

Mat getGreenImage(Mat frame) {
	Mat modFrame;
	vector<Mat> spl;
	split(frame, spl);
	for (int i = 0; i < 3; ++i)
		if (i != 1)
			spl[i] = Mat::zeros(frame.size(), spl[0].type());
	merge(spl, modFrame);
	return modFrame;
}

Mat getBlueImage(Mat frame) {
	Mat modFrame;
	vector<Mat> spl;
	split(frame, spl);
	for (int i = 0; i < 3; ++i)
		if (i != 0)
			spl[i] = Mat::zeros(frame.size(), spl[0].type());
	merge(spl, modFrame);
	return modFrame;
}

Mat invertImage(Mat frame) {
	Mat modFrame;
	bitwise_not(frame, modFrame);
	return modFrame;
}

Mat drawGrid(Mat frame, int dist, Scalar color) {
	Mat modFrame = frame.clone();
	for (int i = 0; i < frame.size().height; i += dist)
		cv::line(modFrame, cv::Point(0, i), Point(modFrame.size().width, i), color);

	for (int i = 0; i < frame.size().width; i += dist)
		cv::line(modFrame, cv::Point(i, 0), Point(i, modFrame.size().height), color);
	return modFrame;
}

Mat convertToColor(Mat frame, int colorSpace) {
	Mat dst;
	cvtColor(frame, dst, colorSpace);
	return dst;
}

Mat convertToColorTwoTimes(Mat frame, int colorSpace, int colorSpace2) {
	Mat dst;
	cvtColor(frame, dst, colorSpace);
	cvtColor(dst, dst, colorSpace2);
	return dst;
}

Mat changeColor(Mat frame, Vec3b colorfrom, Vec3b colorTo) {
	Mat modFrame = frame.clone();
	for (int x = 0; x < modFrame.rows; x++) {
		for (int y = 0; y < modFrame.cols; y++) {

			if (modFrame.at<Vec3b>(x, y) == Vec3b(colorfrom)) {
				modFrame.at<Vec3b>(x, y)[0] = colorTo[0];
				modFrame.at<Vec3b>(x, y)[1] = colorTo[1];
				modFrame.at<Vec3b>(x, y)[2] = colorTo[2];
			}
		}
	}
	return modFrame;
}

Mat segmentation(Mat frame, int x, int y) {
	Mat modFrame;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(x, y));

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);

	cv::threshold(modFrame, modFrame, 90, 255, THRESH_BINARY_INV);
	erode(modFrame, modFrame, element);
	erode(modFrame, modFrame, element);

	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat backgroundSubtractionMOG2(Mat frame) {
	Mat modFrame;
	pMOG2->apply(frame, modFrame);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat backgroundSubtractionKNN(Mat frame) {
	Mat modFrame;
	pKNN->apply(frame, modFrame);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

// Auto adjusment of brightness and contrast from http://answers.opencv.org/question/75510/how-to-make-auto-adjustmentsbrightness-and-contrast-for-image-android-opencv-image-correction/
Mat BrightnessAndContrastAuto(Mat src, float clipHistPercent = 0)
{
	Mat dst;

	CV_Assert(clipHistPercent >= 0);
	CV_Assert((src.type() == CV_8UC1) || (src.type() == CV_8UC3) || (src.type() == CV_8UC4));

	int histSize = 256;
	float alpha, beta;
	double minGray = 0, maxGray = 0;

	//to calculate grayscale histogram
	Mat gray;
	if (src.type() == CV_8UC1) gray = src;
	else if (src.type() == CV_8UC3) cvtColor(src, gray, CV_BGR2GRAY);
	else if (src.type() == CV_8UC4) cvtColor(src, gray, CV_BGRA2GRAY);
	if (clipHistPercent == 0)
	{
		// keep full available range
		minMaxLoc(gray, &minGray, &maxGray);
	}
	else
	{
		Mat hist; //the grayscale histogram

		float range[] = { 0, 256 };
		const float* histRange = { range };
		bool uniform = true;
		bool accumulate = false;
		calcHist(&gray, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

		// calculate cumulative distribution from the histogram
		std::vector<float> accumulator(histSize);
		accumulator[0] = hist.at<float>(0);
		for (int i = 1; i < histSize; i++)
		{
			accumulator[i] = accumulator[i - 1] + hist.at<float>(i);
		}

		// locate points that cuts at required value
		float max = accumulator.back();
		clipHistPercent *= (max / 100.0); //make percent as absolute
		clipHistPercent /= 2.0; // left and right wings
								// locate left cut
		minGray = 0;
		while (accumulator[minGray] < clipHistPercent)
			minGray++;

		// locate right cut
		maxGray = histSize - 1;
		while (accumulator[maxGray] >= (max - clipHistPercent))
			maxGray--;
	}

	// current range
	float inputRange = maxGray - minGray;

	alpha = (histSize - 1) / inputRange;   // alpha expands current range to histsize range
	beta = -minGray * alpha;             // beta shifts current range so that minGray will go to 0

										 // Apply brightness and contrast normalization
										 // convertTo operates with saurate_cast
	src.convertTo(dst, -1, alpha, beta);

	// restore alpha channel from source 
	if (dst.type() == CV_8UC4)
	{
		int from_to[] = { 3, 3 };
		mixChannels(&src, 4, &dst, 1, from_to, 1);
	}

	return dst;
}

Mat contrastStreching(Mat frame) {
	double minVal, maxVal;
	Mat modFrame = frame.clone();
	cv::minMaxLoc(modFrame, &minVal, &maxVal);
	for (int x = 0; x < modFrame.size().width*modFrame.elemSize(); x++)
		for (int y = 0; y < modFrame.size().height; y++) {
			modFrame.at<uchar>(y, x) = floor(((modFrame.at<uchar>(y, x) - minVal) / (maxVal - minVal)) * 255);
		}
	return modFrame;
}

// equalize histogram of a color image
Mat equalizeHistogram(Mat frame)
{
	vector<Mat> channels;
	Mat frame_hist_equalized;
	
	cvtColor(frame, frame_hist_equalized, CV_BGR2YCrCb); // change the color image from BGR to YCrCb format
	split(frame_hist_equalized, channels); // split the image into channels
	equalizeHist(channels[0], channels[0]); // equalize histogram on the 1st channel (Y)
	merge(channels, frame_hist_equalized); // merge 3 channels including the modified 1st channel into one image
	cvtColor(frame_hist_equalized, frame_hist_equalized, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)
	return frame_hist_equalized;
}

Mat getBackProjection(Mat frame) {
	Mat hsv, hue;
	int bins = 25;

	cvtColor(frame, hsv, CV_BGR2HSV);
	hue.create(hsv.size(), hsv.depth());
	int ch[] = { 0, 0 };
	mixChannels(&hsv, 1, &hue, 1, ch, 1);

	MatND hist;
	int histSize = MAX(bins, 2);
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };

	/// Get the Histogram and normalize it
	calcHist(&hue, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());

	/// Get Backprojection
	Mat backproj;
	calcBackProject(&hue, 1, 0, hist, backproj, &ranges, 1, true);
	cv::cvtColor(backproj, backproj, cv::COLOR_GRAY2BGR);
	return backproj;
}

Mat meanBlurFrame(Mat frame, int size) {
	Mat dst;
	cv::blur(frame, dst, Size(size, size));
	return dst;
}

Mat medianBlurFrame(Mat frame, int size) {
	Mat dst;
	cv::medianBlur(frame, dst, size);
	return dst;
}

Mat gaussianBlurFrame(Mat frame, int size, double sigmaX) {
	Mat dst;
	cv::GaussianBlur(frame, dst, Size(size, size), sigmaX);
	return dst;
}

Mat differenceBetweenTwoFrames(Mat firstFrame, Mat secondFrame) {
	Mat dst = secondFrame - firstFrame;
	return dst;
}

Mat thresholding(Mat frame, int thresholdValue, int maxColor, int thresholdType) {
	Mat dst;
	threshold(frame, dst, thresholdValue, maxColor, thresholdType);
	return dst;
}

Mat sobelOperator(Mat frame, double coefX, double coefY, int size) {
	Mat modFrame;
	Mat sobelX;
	Mat sobelY;
	Mat grad;

	GaussianBlur(frame, modFrame, Size(3, 3), 0);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_BGR2GRAY);
	cv::Sobel(modFrame, sobelX, CV_16S, 1, 0, size);
	cv::Sobel(modFrame, sobelY, CV_16S, 0, 1, size);
	cv::convertScaleAbs(sobelX, sobelX);
	cv::convertScaleAbs(sobelY, sobelY);
	cv::addWeighted(sobelX,coefX, sobelY, coefY, 0, grad);
	cv::cvtColor(grad, grad, cv::COLOR_GRAY2BGR);
	return grad;
}

Mat cannyDetector(Mat frame, double threshold1, double threshold2) {
	Mat modFrame;
	Canny(frame, modFrame, threshold1, threshold2);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat dilateFrame(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame;
	Mat element = getStructuringElement(shape, Size(x, y));

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	if(thresholdValue>=0)
		cv::threshold(modFrame, modFrame, thresholdValue, 255, cv::THRESH_BINARY_INV);
	cv::dilate(modFrame, modFrame, element);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat detectEdgesWithDilate(Mat frame) {
	Mat modFrame;
	Mat modFrame1;
	Mat modFrame2;
	Mat element = getStructuringElement(MORPH_CROSS, Size(5, 5));

	cvtColor(frame, modFrame1, cv::COLOR_BGR2GRAY);
	threshold(modFrame1, modFrame1, 120, 255, cv::THRESH_BINARY_INV);
	
	cv::dilate(modFrame1, modFrame2, element);
	modFrame = modFrame2 - modFrame1;
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat erodeFrame(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame;
	Mat element = getStructuringElement(shape, Size(x, y));

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		cv::threshold(modFrame, modFrame, thresholdValue, 255, cv::THRESH_BINARY_INV);
	cv::erode(modFrame, modFrame, element);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat openingFrame(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame;
	Mat element = getStructuringElement(shape, Size(x, y));

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		cv::threshold(modFrame, modFrame, thresholdValue, 255, cv::THRESH_BINARY_INV);
	cv::erode(modFrame, modFrame, element);
	cv::dilate(modFrame, modFrame, element);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat closingFrame(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame;
	Mat element = getStructuringElement(shape, Size(x, y));

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		cv::threshold(modFrame, modFrame, thresholdValue, 255, cv::THRESH_BINARY_INV);
	cv::dilate(modFrame, modFrame, element);
	cv::erode(modFrame, modFrame, element);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat morphologicalGradient(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat dilateTemp, erodeTemp, modFrame;
	Mat element = getStructuringElement(shape, Size(x, y));
	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		threshold(modFrame, modFrame, thresholdValue, 255, cv::THRESH_BINARY_INV);
	dilate(modFrame, dilateTemp, element);
	erode(modFrame, erodeTemp, element);

	return convertToColor(dilateTemp - erodeTemp, cv::COLOR_GRAY2BGR);
}

Mat topHat(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame, grayImage;
	Mat element = getStructuringElement(shape, Size(x, y));
	cv::cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		threshold(grayImage, grayImage, thresholdValue, 255, cv::THRESH_BINARY_INV);
	erode(grayImage, modFrame, element);
	dilate(modFrame, modFrame, element);
	return convertToColor(grayImage - modFrame, cv::COLOR_GRAY2BGR);
}

Mat blackHat(Mat frame, int shape, int x, int y, int thresholdValue) {
	Mat modFrame, grayImage;
	Mat element = getStructuringElement(shape, Size(x, y));
	cv::cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);
	if (thresholdValue >= 0)
		threshold(grayImage, grayImage, thresholdValue, 255, cv::THRESH_BINARY_INV);
	dilate(grayImage, modFrame, element);
	erode(modFrame, modFrame, element);
	return convertToColor(modFrame - grayImage, cv::COLOR_GRAY2BGR);
}

Mat finalAndDrawContours(Mat frame, int threshold, Scalar color) {
	Mat canny_output, modFrame;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);

	/// Detect edges using canny
	Canny(modFrame, canny_output, threshold, threshold + 50, 3);

	/// Find contours
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Draw contours
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}


	return drawing;
}

Mat laplaceOperator(Mat frame, int kernel_size, int scale, int delta) {
	Mat modFrame, greyImage;
	cv::cvtColor(frame, greyImage, cv::COLOR_BGR2GRAY);
	Laplacian(greyImage, modFrame, CV_16S, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(modFrame, modFrame);
	cv::cvtColor(modFrame, modFrame, cv::COLOR_GRAY2BGR);
	return modFrame;
}

Mat harrisCornerDetection(Mat frame, int threshold, int blockSize, int apertureSize, double k) {
	Mat dst_norm_scaled, modFrame;
	modFrame = Mat::zeros(frame.size(), CV_32FC1);

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);
	/// Detecting corners
	cornerHarris(modFrame, modFrame, blockSize, apertureSize, k, BORDER_DEFAULT);

	/// Normalizing
	normalize(modFrame, modFrame, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(modFrame, dst_norm_scaled);

	/// Drawing a circle around corners
	for (int j = 0; j < modFrame.rows; j++)
	{
		for (int i = 0; i < modFrame.cols; i++)
		{
			if ((int)modFrame.at<float>(j, i) > threshold)
			{
				circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
			}
		}
	}
	cv::cvtColor(dst_norm_scaled, dst_norm_scaled, cv::COLOR_GRAY2BGR);
	return dst_norm_scaled;
}

Mat shiTomasiCornerDetector(Mat frame, int maxCorners, double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k) {

	if (maxCorners < 1) { maxCorners = 1; }

	/// Parameters for Shi-Tomasi algorithm
	vector<Point2f> corners;

	/// Copy the source image
	Mat copy;
	copy = frame.clone();
	Mat src_gray;
	cvtColor(frame, src_gray, CV_BGR2GRAY);
	/// Apply corner detection
	goodFeaturesToTrack(src_gray,
		corners,
		maxCorners,
		qualityLevel,
		minDistance,
		Mat(),
		blockSize,
		useHarrisDetector,
		k);


	/// Draw corners detected
	int r = 4;
	for (int i = 0; i < corners.size(); i++)
	{
		circle(copy, corners[i], r, Scalar(255, 255, 255), -1, 8, 0);
	}

	return copy;
}

Mat getHistogram(Mat frame) {

	Mat histogram;
	Mat normalizedHist;
	Mat modFrame;

	cv::cvtColor(frame, modFrame, cv::COLOR_BGR2GRAY);

	int numImages = 1;
	const int* channels = { 0 };
	int dim = 1;
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true;
	bool accumulate = false;
	int histImageWidth = 512;
	int histImageHeight = 512;
	Scalar backgroundIsWhite(255);

	calcHist(&modFrame, numImages, channels, cv::Mat(), histogram, dim, &histSize, &histRange, uniform, accumulate);

	Mat histImage(histImageHeight, histImageWidth, CV_8UC1, backgroundIsWhite);

	int binWidth = (int)((float)histImageWidth / histSize + 0.5f);

	normalize(histogram, normalizedHist, 0, histImageHeight, cv::NORM_MINMAX);

	for (int i = 0; i < histSize; ++i)
	{
		rectangle(histImage,
			Point(i * binWidth, histImageHeight),
			Point((i + 1) * binWidth, histImageHeight - (int)(normalizedHist.at<float>(i))),
			Scalar(0), FILLED);
	}

	return histImage;
}
