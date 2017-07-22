#include "SMainWindow.h"
#include"qsql.h"
#include <QtWidgets/QApplication>
#include<ui_SMainWindow.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ui_MainWindow w;
	w.show();
	return a.exec();
}
