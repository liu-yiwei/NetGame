#include "MainWindow.h"
#include"ui_LoginDialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//	Ui_Dialog lgoin;
	//	lgoin.show();
	MainWindow w;
	w.show();
	return a.exec();
}
