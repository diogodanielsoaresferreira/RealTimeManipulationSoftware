/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

#include "ParameterInserting.h"

ParameterInserting::ParameterInserting(QWidget * parent) : QDialog(parent), ui(new Ui::Dialog) {
	ui->setupUi(this);
}


std::string ParameterInserting::getOneParameter(std::string text1, std::string helper) {
	ui->label->setVisible(true);
	ui->label_2->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(false);
	ui->arg3->setVisible(false);
	ui->arg4->setVisible(false);
	ui->arg5->setVisible(false);
	ui->arg6->setVisible(false);

	ui->label->setText(QString::fromStdString(text1));

	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}

	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		return ui->arg1->toPlainText().toUtf8();
	}
	return "";
}

std::vector<std::string> ParameterInserting::getTwoParameters(std::string text1, std::string text2, std::string helper) {
	std::vector<std::string> args;

	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(true);
	ui->arg3->setVisible(false);
	ui->arg4->setVisible(false);
	ui->arg5->setVisible(false);
	ui->arg6->setVisible(false);

	ui->label->setText(QString::fromStdString(text1));
	ui->label_2->setText(QString::fromStdString(text2));

	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}

	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		args.push_back(ui->arg1->toPlainText().toUtf8().constData());
		args.push_back(ui->arg2->toPlainText().toUtf8().constData());
	}
	
	return args;
}

std::vector<std::string> ParameterInserting::getThreeParameters(std::string text1, std::string text2, std::string text3, std::string helper) {
	std::vector<std::string> args;

	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->label_3->setVisible(true);
	ui->label_4->setVisible(false);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(true);
	ui->arg3->setVisible(true);
	ui->arg4->setVisible(false);
	ui->arg5->setVisible(false);
	ui->arg6->setVisible(false);

	ui->label->setText(QString::fromStdString(text1));
	ui->label_2->setText(QString::fromStdString(text2));
	ui->label_3->setText(QString::fromStdString(text3));

	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}
	
	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		args.push_back(ui->arg1->toPlainText().toUtf8().constData());
		args.push_back(ui->arg2->toPlainText().toUtf8().constData());
		args.push_back(ui->arg3->toPlainText().toUtf8().constData());
	}

	return args;
}

std::vector<std::string> ParameterInserting::getFourParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string helper) {
	std::vector<std::string> args;

	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->label_3->setVisible(true);
	ui->label_4->setVisible(true);
	ui->label_5->setVisible(false);
	ui->label_6->setVisible(false);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(true);
	ui->arg3->setVisible(true);
	ui->arg4->setVisible(true);
	ui->arg5->setVisible(false);
	ui->arg6->setVisible(false);

	ui->label->setText(QString::fromStdString(text1));
	ui->label_2->setText(QString::fromStdString(text2));
	ui->label_3->setText(QString::fromStdString(text3));
	ui->label_4->setText(QString::fromStdString(text4));

	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}
	
	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		args.push_back(ui->arg1->toPlainText().toUtf8().constData());
		args.push_back(ui->arg2->toPlainText().toUtf8().constData());
		args.push_back(ui->arg3->toPlainText().toUtf8().constData());
		args.push_back(ui->arg4->toPlainText().toUtf8().constData());
	}

	return args;
}

std::vector<std::string> ParameterInserting::getFiveParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string text5, std::string helper) {
	std::vector<std::string> args;

	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->label_3->setVisible(true);
	ui->label_4->setVisible(true);
	ui->label_5->setVisible(true);
	ui->label_6->setVisible(true);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(true);
	ui->arg3->setVisible(true);
	ui->arg4->setVisible(true);
	ui->arg5->setVisible(true);
	ui->arg6->setVisible(false);

	ui->label->setText(QString::fromStdString(text1));
	ui->label_2->setText(QString::fromStdString(text2));
	ui->label_3->setText(QString::fromStdString(text3));
	ui->label_4->setText(QString::fromStdString(text4));
	ui->label_5->setText(QString::fromStdString(text5));

	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}
	
	
	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		args.push_back(ui->arg1->toPlainText().toUtf8().constData());
		args.push_back(ui->arg2->toPlainText().toUtf8().constData());
		args.push_back(ui->arg3->toPlainText().toUtf8().constData());
		args.push_back(ui->arg4->toPlainText().toUtf8().constData());
		args.push_back(ui->arg5->toPlainText().toUtf8().constData());
	}

	return args;
}

std::vector<std::string> ParameterInserting::getSixParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string text5, std::string text6, std::string helper) {
	std::vector<std::string> args;

	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->label_3->setVisible(true);
	ui->label_4->setVisible(true);
	ui->label_5->setVisible(true);
	ui->label_6->setVisible(true);

	ui->arg1->setVisible(true);
	ui->arg2->setVisible(true);
	ui->arg3->setVisible(true);
	ui->arg4->setVisible(true);
	ui->arg5->setVisible(true);
	ui->arg6->setVisible(true);

	ui->label->setText(QString::fromStdString(text1));
	ui->label_2->setText(QString::fromStdString(text2));
	ui->label_3->setText(QString::fromStdString(text3));
	ui->label_4->setText(QString::fromStdString(text4));
	ui->label_5->setText(QString::fromStdString(text5));
	ui->label_6->setText(QString::fromStdString(text6));


	if (helper.empty()) {
		ui->helper->setVisible(false);
	}
	else {
		ui->helper->setVisible(true);
		ui->helper->setText(QString::fromStdString(helper));
	}

	
	int dialogCode = exec();
	if (dialogCode == QDialog::Accepted) {
		args.push_back(ui->arg1->toPlainText().toUtf8().constData());
		args.push_back(ui->arg2->toPlainText().toUtf8().constData());
		args.push_back(ui->arg3->toPlainText().toUtf8().constData());
		args.push_back(ui->arg4->toPlainText().toUtf8().constData());
		args.push_back(ui->arg5->toPlainText().toUtf8().constData());
		args.push_back(ui->arg6->toPlainText().toUtf8().constData());
	}

	return args;
}