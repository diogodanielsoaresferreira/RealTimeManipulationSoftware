/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

#include "RealTimeManipulationSoftware.h"
#include "ParameterInserting.h"


RealTimeManipulationSoftware::RealTimeManipulationSoftware(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::RealTimeManipulationSoftwareClass)
{
	saveVideo = false;

	myPlayer = new Player();
	myPlayer->name = "Original video";
	QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
		this, SLOT(updatePlayerUI(QImage)));

	myPlayerTransformed = new Player();
	myPlayerTransformed->name = "Transformed video";
	QObject::connect(myPlayerTransformed, SIGNAL(processedImage(QImage)),
		this, SLOT(updatePlayer2UI(QImage)));

	ui->setupUi(this);
}

void RealTimeManipulationSoftware::updatePlayerUI(QImage img)
{
	
	if (!img.isNull())
	{
		ui->label->setAlignment(Qt::AlignCenter);
		ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),
		Qt::KeepAspectRatio, Qt::FastTransformation));
		
	}
}

void RealTimeManipulationSoftware::updatePlayer2UI(QImage img)
{

	if (!img.isNull())
	{
		ui->label_2->setAlignment(Qt::AlignCenter);
		ui->label_2->setPixmap(QPixmap::fromImage(img).scaled(ui->label_2->size(),
			Qt::KeepAspectRatio, Qt::FastTransformation));

	}
}

RealTimeManipulationSoftware::~RealTimeManipulationSoftware()
{
	myPlayer->Stop();
	myPlayerTransformed->Stop();
	delete myPlayer;
	delete myPlayerTransformed;
	delete ui;
}


void RealTimeManipulationSoftware::on_pushButton_2_clicked()
{
	if (myPlayer->isStopped())
	{
		if (ui->saveVideo->text() == "Save video")
			ui->saveVideo->setEnabled(false);

		myPlayer->setHistogram();
		myPlayerTransformed->setHistogram();
		myPlayer->PlayCamera();
		myPlayerTransformed->PlayCamera();
		myPlayerTransformed->PlayVideo();
		myPlayer->PlayVideo();
		ui->loadVideoButton->setEnabled(false);
		ui->pushButton_2->setEnabled(false);
		ui->stopVideoButton->setEnabled(true);
	}
	
}

void RealTimeManipulationSoftware::action_loadFromFile() {
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Load Video"), "",
		tr("Video (*.avi);;All Files (*)"));
	if (fileName.isEmpty() || fileName.isNull()) return;
	if (ui->saveVideo->text() == "Save Video")
		ui->saveVideo->setEnabled(false);
	ui->pushButton_2->setEnabled(false);
	myPlayer->loadVideo(fileName.toUtf8().constData());
	myPlayerTransformed->loadVideo(fileName.toUtf8().constData());
	myPlayer->setHistogram();
	myPlayerTransformed->setHistogram();
	myPlayer->PlayVideo();
	myPlayerTransformed->PlayVideo();
	ui->loadVideoButton->setEnabled(false);
	ui->stopVideoButton->setEnabled(true);

}

void RealTimeManipulationSoftware::action_stopVideoButton() {
	myPlayer->Stop();
	myPlayerTransformed->Stop();
	ui->loadVideoButton->setEnabled(true);
	ui->pushButton_2->setEnabled(true);
	ui->saveVideo->setEnabled(true);
	ui->stopVideoButton->setEnabled(false);
}

void RealTimeManipulationSoftware::action_saveVideo() {
	if (saveVideo) {
		myPlayerTransformed->saveVideoStop();
		ui->saveVideo->setText(tr("Save video"));
	}
	else {
		QString fileName = QFileDialog::getSaveFileName(this,
			tr("Save video"), "",
			tr("Video (*.avi);;All Files (*)"));
		if (fileName.isEmpty() || fileName.isNull()) return;
		myPlayerTransformed->saveVideoStart(fileName.toUtf8().constData());
		ui->saveVideo->setText(tr("Stop saving video"));
	}
	saveVideo = !saveVideo;
}

void RealTimeManipulationSoftware::updateTransformationList(std::deque <Transformation*> transformations) {
	ui->transformationList->clear();
	for (int i = 0; i < transformations.size(); i++)
		ui->transformationList->addItem(QString::fromStdString(transformations.at(i)->name));
}

void RealTimeManipulationSoftware::action_transformationClicked(QListWidgetItem* item) {
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Remove Transformation", "Do you want to remove this transformation?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		myPlayerTransformed->deleteByIndex(ui->transformationList->selectionModel()->currentIndex().row());
		updateTransformationList(myPlayerTransformed->transformations);
	}
}

void RealTimeManipulationSoftware::setRedImage() {
	myPlayerTransformed->setRedImage();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::setGreenImage() {
	myPlayerTransformed->setGreenImage();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::setBlueImage() {
	myPlayerTransformed->setBlueImage();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::setBrightnessContrast() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Alpha (Recommended: 1.5)", "Beta (Recommended: 0.5)", "The values must be real numbers");
	delete pi;

	if (res.size() < 2) {
		return;
	}
	
	try {
		float arg1 = stof(res.at(0));
		float arg2 = stof(res.at(1));
		myPlayerTransformed->setBrightnessContrast(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
	
}

void RealTimeManipulationSoftware::setColor() {
	myPlayerTransformed->setColor(COLOR_BGR2GRAY, COLOR_GRAY2BGR);
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_changeColor() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getSixParameters("Source Color Red", "Source Color Green", "Source Color Blue", "Destination Color Red", "Destination Color Green", "Destination Color Blue", "All values are integers from 0 to 255");
	delete pi;

	if (res.size() < 6) {
		return;
	}

	try {

		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		int arg3 = stoi(res.at(2));
		int arg4 = stoi(res.at(3));
		int arg5 = stoi(res.at(4));
		int arg6 = stoi(res.at(5));

		if (arg1 < 0 || arg1>255 ||
			arg2 < 0 || arg2>255 ||
			arg3 < 0 || arg3>255 ||
			arg4 < 0 || arg4>255 ||
			arg5 < 0 || arg5>255 ||
			arg6 < 0 || arg6>255) {
			throw Exception();
		}

		myPlayerTransformed->enableChangeColor(Vec3b(arg3, arg2, arg1), Vec3b(arg6, arg5, arg4));
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
	
}

void RealTimeManipulationSoftware::action_invertImage() {
	myPlayerTransformed->setImageInverted();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_createSegmentation() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Width(x) of Ellipse", "Height(y) of Ellipse", "Size of structuring element. Must be integer greater that zero.");
	delete pi;

	if (res.size() < 2) {
		return;
	}

	try {

		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));

		if (arg1 < 0 || arg2 < 0) throw Exception();

		myPlayerTransformed->applySegmentation(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_backgroundSubtractionKNN() {
	myPlayerTransformed->applyBackgroundSubtractionKNN();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_backgroundSubtractionMOG2() {
	myPlayerTransformed->applyBackgroundSubtractionMOG2();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_meanBlur() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::string res = pi->getOneParameter("Kernel Size", "Must be integer greater that zero.");
	delete pi;

	if (res.empty()) {
		return;
	}

	try {
		int arg1 = stoi(res);
		if (arg1 < 0) throw Exception();

		myPlayerTransformed->applyMeanBlur(arg1);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_medianBlur() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::string res = pi->getOneParameter("Kernel Size", "Must be integer greater that one and odd.");
	delete pi;

	if (res.empty()) {
		return;
	}

	try {
		int arg1 = stoi(res);
		if (arg1 < 3 || (arg1%2==0)) throw Exception();

		myPlayerTransformed->applyMedianBlur(arg1);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_gaussianBlur() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Kernel Size", "SigmaX (real numeric)", "Kernel size must be a positive odd integer");
	delete pi;

	if (res.size()<2) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		double arg2 = stod(res.at(1));
		if (arg1 < 0 || arg2 < 0 || (arg1%2==0)) throw Exception();

		myPlayerTransformed->applyGaussianBlur(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_contrastStreching() {
	myPlayerTransformed->applyContrastStreching();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_equalizeHist() {
	myPlayerTransformed->applyEqualizeHistogram();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_backProj() {
	myPlayerTransformed->applyBackProjecton();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_brightContAuto() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::string res = pi->getOneParameter("Clipping percentage(0 to 100)", "Cut wings of histogram at given percentage.");
	delete pi;

	if (res.empty()) {
		return;
	}

	try {
		int arg1 = stoi(res);
		if (arg1 < 0 || arg1>100) throw Exception();

		myPlayerTransformed->applyBrightContAuto(arg1);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_erode() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));
		
		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyErode(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_dilate() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyDilate(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_opening() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyOpening(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_closing() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyClosing(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_morphologicalGradient() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyMorphologicalGradient(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_topHat() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyTopHat(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_blackHat() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Shape", "Width(x) of structuring element", "Height(y) of structuring element", "Threshold value (0 to 255, or -1)", "Shape codes: 1 - Cross; 2 - Ellipse; 3 - Rect. If no threshold, insert -1.");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stod(res.at(1));
		int arg3 = stod(res.at(2));
		int arg4 = stod(res.at(3));

		if (arg1 == 1) {
			arg1 = CV_SHAPE_CROSS;
		}
		else if (arg1 == 2) {
			arg1 = CV_SHAPE_ELLIPSE;
		}
		else if (arg1 == 3) {
			arg1 = CV_SHAPE_RECT;
		}
		else {
			throw Exception();
		}

		if (arg2 < 0 || arg3 < 0) {
			throw Exception();
		}

		if (arg4 < -1 || arg4>255) {
			throw Exception();
		}

		myPlayerTransformed->applyBlackHat(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_thresBinary() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Threshold Value (0 to 255)", "Maximum grey value (0 to 255)");
	delete pi;

	if (res.size()<2) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		if (arg1 < 0 || arg2 < 0 || arg1 > 255 || arg2 > 255) throw Exception();

		myPlayerTransformed->applyThresholdBinary(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_thresBinaryInv() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Threshold Value (0 to 255)", "Maximum grey value (0 to 255)");
	delete pi;

	if (res.size()<2) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		if (arg1 < 0 || arg2 < 0 || arg1 > 255 || arg2 > 255) throw Exception();

		myPlayerTransformed->applyThresholdBinaryInverted(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_truncate() {
	
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("Threshold Value (0 to 255)", "Maximum grey value (0 to 255)");
	delete pi;

	if (res.size()<2) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		if (arg1 < 0 || arg2 < 0 || arg1 > 255 || arg2 > 255) throw Exception();

		myPlayerTransformed->applyTruncate(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_thresZero() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::string res = pi->getOneParameter("Threshold Value (0 to 255)");
	delete pi;

	if (res.empty()) {
		return;
	}

	try {
		int arg1 = stoi(res);
		if (arg1 < 0 || arg1 > 255) throw Exception();

		myPlayerTransformed->applyThresholdToZero(arg1, 0);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}
}

void RealTimeManipulationSoftware::action_thresZeroInv() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::string res = pi->getOneParameter("Threshold Value (0 to 255)");
	delete pi;

	if (res.empty()) {
		return;
	}

	try {
		int arg1 = stoi(res);
		if (arg1 < 0 || arg1 > 255) throw Exception();

		myPlayerTransformed->applyThresholdToZeroInverted(arg1, 0);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_sobelOperator() {
	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getThreeParameters("X Coeficient (0 to 1)", "Y Coeficient (0 to 1)", "Sobel Kernel (1, 3, 5 or 7)");
	delete pi;

	if (res.size()<3) {
		return;
	}

	try {
		double arg1 = stod(res.at(0));
		double arg2 = stod(res.at(1));
		int arg3 = stoi(res.at(2));
		if (arg1 < 0 || arg2 < 0 || arg2 > 1 || arg1 > 1 || (arg3 != 1 && arg3 != 3 && arg3 != 5 && arg3 != 7)) throw Exception();

		myPlayerTransformed->applySobelOperator(arg1, arg2, arg3);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_cannyOperator() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getTwoParameters("First Threshold (0 to 255)", "Second threshold (0 to 255)");
	delete pi;

	if (res.size()<2) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		if (arg1 < 0 || arg2 < 0 || arg2 > 255 || arg1 > 255) throw Exception();

		myPlayerTransformed->applyCannyOperator(arg1, arg2);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_detectEdgesDilate() {
	myPlayerTransformed->applyDetectEdgesDilate();
	updateTransformationList(myPlayerTransformed->transformations);
}

void RealTimeManipulationSoftware::action_drawContours() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Threshold(0 to 255)", "Red Value(0 to 255)", "Green Value(0 to 255)", "Blue Value(0 to 255)");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		int arg3 = stoi(res.at(2));
		int arg4 = stoi(res.at(3));
		if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0 ||
			arg2 > 255 || arg1 > 255 || arg3 > 255 || arg4 > 255) throw Exception();

		myPlayerTransformed->applyDrawContours(arg1, Scalar(arg4, arg3, arg2));
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_laplaceOperator() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getThreeParameters("Kernel Size (must be odd)", "Scale", "Delta");
	delete pi;

	if (res.size()<3) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		int arg3 = stoi(res.at(2));
		if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg1 % 2 == 0) throw Exception();

		myPlayerTransformed->applyLaplaceOperator(arg1, arg2, arg3);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

}

void RealTimeManipulationSoftware::action_harrisCornerDetection() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getFourParameters("Threshold(0 to 255)", "Block Size", "Aperture Size (1, 3, 5 or 7)", "K (0 to 1)");
	delete pi;

	if (res.size()<4) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		int arg2 = stoi(res.at(1));
		int arg3 = stoi(res.at(2));
		double arg4 = stod(res.at(3));
		if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0 || arg1>255 || arg4>1 || (arg3!=1 && arg3!=3 && arg3!= 5 && arg3!=7)) throw Exception();

		myPlayerTransformed->applyHarrisCornerDetection(arg1, arg2, arg3, arg4);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}


	
}

void RealTimeManipulationSoftware::action_shiTomasiCornerDetection() {

	ParameterInserting* pi = new ParameterInserting(this);
	std::vector<std::string> res = pi->getSixParameters("Max Corners (R: 20-30)", "Quality Level (R: 0.01)", "Minimum Distance (R: 10)", "Block Size (R: 3)", "Use Harris Detector? (True/False)", "K (0 to 1) (R: 0.04)", "Recomended values in R labels");
	delete pi;

	if (res.size()<6) {
		return;
	}

	try {
		int arg1 = stoi(res.at(0));
		double arg2 = stod(res.at(1));
		double arg3 = stod(res.at(2));
		int arg4 = stoi(res.at(3));
		bool arg5 = false;
		if (res.at(4) == "True")
			arg5 = true;
		double arg6 = stod(res.at(5));
		
		if (arg1 < 0 || arg2 < 0 || arg3 < 0 || arg4 < 0 || arg2>1 || arg6>1) throw Exception();

		myPlayerTransformed->applyShiTomasiCornerDetection(arg1, arg2, arg3, arg4, arg5, arg6);
		updateTransformationList(myPlayerTransformed->transformations);
	}
	catch (...) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Invalid parameters");
		messageBox.setFixedSize(500, 200);
	}

	
}

