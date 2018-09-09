/*
*
* Real-time Image Modification
*
*
* Diogo Ferreira	Nº76504
* Luís Leira		Nº76514
*/

/*
	Class that takes care of the UI dialog,
	according to the number of parameters
*/

#include <QDialog>
#include <string>
#include <vector>
#include "ui_ParameterInserting.h"

namespace Ui {
	class Dialog;
}

class ParameterInserting : public QDialog, public Ui::Dialog {
	Q_OBJECT

public:
	ParameterInserting(QWidget * parent);
	std::string getOneParameter(std::string text1, std::string helper = "");
	std::vector<std::string> getTwoParameters(std::string text1, std::string text2, std::string helper = "");
	std::vector<std::string> getThreeParameters(std::string text1, std::string text2, std::string text3, std::string helper = "");
	std::vector<std::string> getFourParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string helper = "");
	std::vector<std::string> getFiveParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string text5, std::string helper = "");
	std::vector<std::string> getSixParameters(std::string text1, std::string text2, std::string text3, std::string text4, std::string text5, std::string text6, std::string helper = "");

private:
	Ui::Dialog *ui;
};