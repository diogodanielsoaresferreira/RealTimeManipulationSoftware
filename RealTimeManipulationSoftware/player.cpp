/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

#include "player.h"
#include <time.h>


// Base code for reproduce an Open CV video in QT from http://codingexodus.blogspot.pt/2012/12/working-with-video-using-opencv-and-qt.html
Player::Player(QObject *parent)
	: QThread(parent)
{
	stop = true;
	saveVideo = false;
	name = "Unknown";
}

bool Player::loadVideo(string filename) {
	if (capture.isOpened()) {
		capture.release();
	}

	capture.open(filename);
	if (capture.isOpened())
	{
		// Get the frame rate
		frameRate = (int)capture.get(CV_CAP_PROP_FPS);

		// If save video is true, open a video writer to save video
		if (saveVideo) {
			int frame_width = int(capture.get(CV_CAP_PROP_FRAME_WIDTH));
			int frame_height = int(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
			video = VideoWriter(Player::filename, CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));
		}
		return true;
	}
	else
		return false;
}



void Player::PlayVideo()
{
	if (isStopped()) {
		stop = false;
	}
	start(LowPriority);
	
}

void Player::PlayCamera()
{	
	// Open camera and set framerate as 60
	if (capture.isOpened()) {
		capture.release();
	}
	capture.open(0);
	frameRate = 60;

	// If save video is true, open a video writer to save video
	if (saveVideo) {
		int frame_width = int(capture.get(CV_CAP_PROP_FRAME_WIDTH));
		int frame_height = int(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
		video = VideoWriter(Player::filename, CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));
	}
	
}

void Player::run()
{
	clock_t t;
	double elapsedTime;
	double delay = 1000 / frameRate;

	
	// Loop forever until the end of video, or until the user stops it
	while (!stop) {
		t = clock();


		try {
			// Get the next frame
			if (!capture.read(frame))
			{
				stop = true;
				return;
			}
		}
		catch (...) {
			stop = true;
			return;
		}
		

		// Apply all transformations to frame
		frame = applyTransformations(frame);
		
		// Translate from BGR to RGB
		if (frame.channels() == 3) {
			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
			img = QImage((const unsigned char*)(RGBframe.data),
				RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		}
		
		// If the histogram window exists, open histogram
		if (cvGetWindowHandle(name)) {
			imshow(name, getHistogram(frame));
		}

		// Save frame of video, if requested
		if (saveVideo) {
			video.write(frame);
		}
			
		emit processedImage(img);
		t = clock() - t;
		elapsedTime = 1000*((double)t / CLOCKS_PER_SEC);

		// If the elapsed time to calculate the transformations is more than the delay time,
		// Don't do the delay
		// Other wise, delay only the time that lefts
		if (elapsedTime < delay) {
			this->msleep(delay-elapsedTime);
		}
		
	}
}

void Player::saveVideoStart(string filename) {
	saveVideo = true;
	Player::filename = filename;
}

void Player::saveVideoStop() {
	saveVideo = false;
	video.release();
}

Player::~Player()
{
	mutex.lock();
	stop = true;
	capture.release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}

void Player::Stop()
{
	stop = true;
	
}

void Player::msleep(double ms) {
	usleep(ms*1000);
}

bool Player::isStopped() const {
	return this->stop;
}

void Player::deleteByIndex(int idx) {
	delete Player::transformations.at(idx);
	Player::transformations.erase(Player::transformations.begin() + idx);
}

Mat Player::applyTransformations(Mat frame) {
	Mat modFrame = frame.clone();
	for (int i = 0; i < Player::transformations.size(); i++)
		modFrame = Player::transformations.at(i)->applyTransformation(modFrame);
	return modFrame;
}


void Player::setRedImage() {
	
	NoParameters* t = new NoParameters(getRedImage, "Get Red Image");
	transformations.push_back(t);
}

void Player::setGreenImage() {
	NoParameters* t = new NoParameters(getGreenImage, "Get Green Image");
	transformations.push_back(t);
}

void Player::setBlueImage() {
	NoParameters* t = new NoParameters(getBlueImage, "Get Blue Image");
	transformations.push_back(t);
}


void Player::setBrightnessContrast(double alpha, double beta) {
	TwoDoubleParameters*  t = new TwoDoubleParameters(changeBrightnessContrast, alpha, beta, "Brightness and Contrast");
	transformations.push_back(t);
	
}

void Player::setColor(int colorspace, int colorspaceBack) {
	TwoIntParameters*  t = new TwoIntParameters(convertToColorTwoTimes, colorspace, colorspaceBack, "Set Color");
	transformations.push_back(t);
	
}

void Player::enableChangeColor(Vec3b colorFrom, Vec3b colorTo) {
	TwoVec3bParameters*  t = new TwoVec3bParameters(changeColor, colorFrom, colorTo, "Change Color");
	transformations.push_back(t);
}


void Player::setImageInverted() {
	NoParameters*  t = new NoParameters(invertImage, "Invert Image");
	transformations.push_back(t);
}

void Player::applySegmentation(int x, int y) {
	TwoIntParameters*  t = new TwoIntParameters(segmentation, x, y, "Segmentation");
	transformations.push_back(t);
}

void Player::applyBackgroundSubtractionKNN() {
	NoParameters*  t = new NoParameters(backgroundSubtractionKNN, "Backgrund Subtraction using KNN");
	transformations.push_back(t);
}

void Player::applyBackgroundSubtractionMOG2() {
	NoParameters*  t = new NoParameters(backgroundSubtractionMOG2, "Background Subtraction using MOG2");
	transformations.push_back(t);
}

void Player::applyMeanBlur(int size) {
	OneIntParameters*  t = new OneIntParameters(meanBlurFrame, size, "Mean Blur");
	transformations.push_back(t);
}

void Player::applyMedianBlur(int size) {
	OneIntParameters*  t = new OneIntParameters(medianBlurFrame, size, "Median Blur");
	transformations.push_back(t);
}

void Player::applyGaussianBlur(int size, double sigmaX) {
	IntDoubleParameters*  t = new IntDoubleParameters(gaussianBlurFrame, size, sigmaX, "Gaussian Blur");
	transformations.push_back(t);
}

void Player::applyContrastStreching() {
	NoParameters*  t = new NoParameters(contrastStreching, "Contrast streching");
	transformations.push_back(t);
}
void Player::applyEqualizeHistogram() {
	NoParameters*  t = new NoParameters(equalizeHistogram, "Equalize Histogram");
	transformations.push_back(t);
}
void Player::applyBackProjecton() {
	NoParameters*  t = new NoParameters(getBackProjection, "Back Projection");
	transformations.push_back(t);
}

void Player::applyBrightContAuto(float clipHistPercent) {
	OneFloatParameter*  t = new OneFloatParameter(BrightnessAndContrastAuto, clipHistPercent, "Auto brightness and contrast");
	transformations.push_back(t);
}

void Player::applyErode(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(erodeFrame, shape, x, y, thresholdValue, "Erode");
	transformations.push_back(t);
}

void Player::applyDilate(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(dilateFrame, shape, x, y, thresholdValue, "Dilate");
	transformations.push_back(t);
}

void Player::applyOpening(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(openingFrame, shape, x, y, thresholdValue, "Opening");
	transformations.push_back(t);
}

void Player::applyClosing(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(closingFrame, shape, x, y, thresholdValue, "Closing");
	transformations.push_back(t);
}

void Player::applyMorphologicalGradient(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(morphologicalGradient, shape, x, y, thresholdValue, "Morphlogical Gradient");
	transformations.push_back(t);
}

void Player::applyTopHat(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(topHat, shape, x, y, thresholdValue, "Top Hat");
	transformations.push_back(t);
}

void Player::applyBlackHat(int shape, int x, int y, int thresholdValue) {
	FourIntParameters*  t = new FourIntParameters(blackHat, shape, x, y, thresholdValue, "Black Hat");
	transformations.push_back(t);
}

void Player::applyThresholdBinary(int thValue, int maxColor) {
	ThreeIntParameters*  t = new ThreeIntParameters(thresholding, thValue, maxColor, THRESH_BINARY, "Binary Threshold");
	transformations.push_back(t);
}

void Player::applyThresholdBinaryInverted(int thValue, int maxColor) {
	ThreeIntParameters*  t = new ThreeIntParameters(thresholding, thValue, maxColor, THRESH_BINARY_INV, "Inverted Binary Threshold");
	transformations.push_back(t);
}

void Player::applyTruncate(int thValue, int maxColor) {
	ThreeIntParameters*  t = new ThreeIntParameters(thresholding, thValue, maxColor, THRESH_TRUNC, "Truncate");
	transformations.push_back(t);
}

void Player::applyThresholdToZero(int thValue, int maxColor) {
	ThreeIntParameters*  t = new ThreeIntParameters(thresholding, thValue, maxColor, THRESH_TOZERO, "Threshold to Zero");
	transformations.push_back(t);
}

void Player::applyThresholdToZeroInverted(int thValue, int maxColor) {
	ThreeIntParameters*  t = new ThreeIntParameters(thresholding, thValue, maxColor, THRESH_TOZERO_INV, "Threshold to Zero Inverted");
	transformations.push_back(t);
}

void Player::applyCannyOperator(double threshold1, double threshold2) {
	TwoDoubleParameters*  t = new TwoDoubleParameters(cannyDetector, threshold1, threshold2, "Canny Operator");
	transformations.push_back(t);
}

void Player::applySobelOperator(double x, double y, int size) {
	TwoDoubleIntParameters*  t = new TwoDoubleIntParameters(sobelOperator, x, y, size, "Sobel Operator");
	transformations.push_back(t);
}

void Player::applyDetectEdgesDilate() {
	NoParameters*  t = new NoParameters(detectEdgesWithDilate, "Detect edges with dilate");
	transformations.push_back(t);
}

void Player::applyDrawContours(int threshold, Scalar color) {
	IntScalarParameters*  t = new IntScalarParameters(finalAndDrawContours, threshold, color, "Draw contours");
	transformations.push_back(t);
}

void Player::applyLaplaceOperator(int kernel_size, int scale, int delta) {
	ThreeIntParameters*  t = new ThreeIntParameters(laplaceOperator, kernel_size, scale, delta, "Laplace Operator");
	transformations.push_back(t);
}

void Player::applyHarrisCornerDetection(int threshold, int blockSize, int apertureSize, double k) {
	ThreeIntDoubleParameters*  t = new ThreeIntDoubleParameters(harrisCornerDetection, threshold, blockSize, apertureSize, k, "Harris Corner Detection");
	transformations.push_back(t);
}

void Player::applyShiTomasiCornerDetection(int maxCorners, double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k) {
	ShiTomasiCornerDetectionParameters*  t = new ShiTomasiCornerDetectionParameters(shiTomasiCornerDetector, maxCorners, qualityLevel, minDistance, blockSize, useHarrisDetector, k, "Shi-Tomasi Corner Detection");
	transformations.push_back(t);
}

void Player::setHistogram() {
	namedWindow(name, WINDOW_AUTOSIZE);
}

