/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <queue>
#include <memory>
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Aux_functions.h"
#include "transformations.h"

using namespace cv;
using namespace std;


// Base code for reproduce an Open CV video in QT from http://codingexodus.blogspot.pt/2012/12/working-with-video-using-opencv-and-qt.html
class Player : public QThread
{
	Q_OBJECT
private:
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	Mat frame;
	int frameRate;
	VideoCapture capture;
	Mat RGBframe;
	QImage img;
	VideoWriter video;
	string filename;
	Mat applyTransformations(Mat frame);
	bool saveVideo;

signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
protected:
	void run();
	void msleep(double ms);
public:
	//Constructor
	Player(QObject *parent = 0);
	//Destructor
	~Player();
	//Load a video from memory
	bool loadVideo(string filename);
	//Play the video from local file
	void PlayVideo();
	//Play the video from camera
	void PlayCamera();
	//Stop the video
	void Stop();
	//check if the player has been stopped
	bool isStopped() const;
	void saveVideoStart(string filename);
	void saveVideoStop();
	void deleteByIndex(int idx);

	char* name;
	// List of transformations
	std::deque <Transformation*> transformations;
	// Transformations
	void setRedImage();
	void setGreenImage();
	void setBlueImage();
	void setBrightnessContrast(double alpha, double beta);
	void setColor(int colorspace, int colorspaceBack);
	void enableChangeColor(Vec3b colorFrom, Vec3b colorTo);
	void setImageInverted();
	void setHistogram();
	void applySegmentation(int x, int y);
	void applyBackgroundSubtractionKNN();
	void applyBackgroundSubtractionMOG2();
	void applyMeanBlur(int size);
	void applyMedianBlur(int size);
	void applyGaussianBlur(int size, double sigmaX);
	void applyContrastStreching();
	void applyEqualizeHistogram();
	void applyBackProjecton();
	void applyBrightContAuto(float clipHistPercent);
	void applyErode(int shape, int x, int y, int thresholdValue);
	void applyDilate(int shape, int x, int y, int thresholdValue);
	void applyOpening(int shape, int x, int y, int thresholdValue);
	void applyClosing(int shape, int x, int y, int thresholdValue);
	void applyMorphologicalGradient(int shape, int x, int y, int thresholdValue);
	void applyTopHat(int shape, int x, int y, int thresholdValue);
	void applyBlackHat(int shape, int x, int y, int thresholdValue);
	void applyThresholdBinary(int thValue, int maxColor);
	void applyThresholdBinaryInverted(int thValue, int maxColor);
	void applyTruncate(int thValue, int maxColor);
	void applyThresholdToZero(int thValue, int maxColor);
	void applyThresholdToZeroInverted(int thValue, int maxColor);
	void applyCannyOperator(double threshold1, double threshold2);
	void applySobelOperator(double x, double y, int size);
	void applyDetectEdgesDilate();
	void applyDrawContours(int threshold, Scalar color);
	void applyLaplaceOperator(int kernel_size, int scale, int delta);
	void applyHarrisCornerDetection(int threshold, int blockSize, int apertureSize, double k);
	void applyShiTomasiCornerDetection(int maxCorners, double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k);

};
#endif // VIDEOPLAYER_H