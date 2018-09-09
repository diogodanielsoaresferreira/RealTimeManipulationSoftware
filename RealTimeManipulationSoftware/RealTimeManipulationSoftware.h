/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets/QLabel>
#include <QMessageBox>
#include <player.h>
#include "ui_RealTimeManipulationSoftware.h"

namespace Ui {
	class RealTimeManipulationSoftwareClass;
}

class RealTimeManipulationSoftware : public QMainWindow
{
	Q_OBJECT

public:
	explicit RealTimeManipulationSoftware(QWidget *parent = 0);
	~RealTimeManipulationSoftware();

	private slots:
	//Display video frame in player UI
	void updatePlayerUI(QImage img);
	void updatePlayer2UI(QImage img);
	// Slot for the play push button.
	void on_pushButton_2_clicked();
	void action_loadFromFile();
	void action_stopVideoButton();
	void action_saveVideo();

	void setRedImage();
	void setGreenImage();
	void setBlueImage();
	void setBrightnessContrast();
	void setColor();
	void action_changeColor();
	void action_invertImage();
	void action_createSegmentation();
	void action_backgroundSubtractionKNN();
	void action_backgroundSubtractionMOG2();
	void action_meanBlur();
	void action_medianBlur();
	void action_gaussianBlur();
	void action_contrastStreching();
	void action_equalizeHist();
	void action_backProj();
	void action_brightContAuto();
	void action_erode();
	void action_dilate();
	void action_opening();
	void action_closing();
	void action_morphologicalGradient();
	void action_topHat();
	void action_blackHat();
	void action_thresBinary();
	void action_thresBinaryInv();
	void action_truncate();
	void action_thresZero();
	void action_thresZeroInv();
	void action_sobelOperator();
	void action_cannyOperator();
	void action_detectEdgesDilate();
	void action_drawContours();
	void action_laplaceOperator();
	void action_harrisCornerDetection();
	void action_shiTomasiCornerDetection();
	void action_transformationClicked(QListWidgetItem* item);

private:
	Ui::RealTimeManipulationSoftwareClass *ui;
	Player* myPlayer;
	Player* myPlayerTransformed;

	bool saveVideo;
	void RealTimeManipulationSoftware::updateTransformationList(std::deque <Transformation*> transformations);
	
};
#endif // MAINWINDOW_H

