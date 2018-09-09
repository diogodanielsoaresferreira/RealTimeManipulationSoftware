#include "RealTimeManipulationSoftware.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RealTimeManipulationSoftware* w = new RealTimeManipulationSoftware();
	w->setAttribute(Qt::WA_DeleteOnClose, true);

	w->show();

	return a.exec();
}