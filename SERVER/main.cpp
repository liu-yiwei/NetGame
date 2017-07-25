#include "ui_SMainWindow.h"
#include <QtWidgets/QApplication>
#include "glog/logging.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ui_MainWindow w;
	w.show();

	return a.exec();
}