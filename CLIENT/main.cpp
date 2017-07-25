#include <QApplication>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimeLine>
#include "MainWindow.h"
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	MainWindow w;
	w.show();
	app.exec();

}