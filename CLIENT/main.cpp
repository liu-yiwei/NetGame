#include <QApplication>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimeLine>
#include "MainWindow.h"
#include "ui_LoginDialog.h"
#include "OnLineMainWindow.h"
std::map<int,std::string>login() {
	Ui_Dialog log;
	log.show();
	std::map<int, std::string> temp;
	int a = log.exec();
	if (a ==QDialog::Accepted)
	{
		temp.clear();
		temp.insert(std::pair<int, std::string>(0, "offline"));
		return temp;
	}else if (a == QDialog::Rejected)
	{
		temp.clear();
		temp.insert(std::pair<int, std::string>(0, "online"));
		return temp;
	}
}

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);


	std::map<int, std::string> temp = login();
	if (temp.begin()->second=="offline")
	{
		MainWindow w;
		w.show();
		return app.exec();
	}
	else if(temp.begin()->second == "online")
	{
		Ui_MainWindow w;
		w.show();
		return app.exec();
	}
	

}