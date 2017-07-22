#include "MainWindow.h"
#include"ui_LoginDialog.h"
#include <QApplication>

//返回登陆信息
std::vector<char*> login()
{
	char* actionType;
	Ui_Dialog b;
	if (b.exec())
	{

	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	std::vector<QString> b = login();
	if (true)//判断用户操作类型
	{
		MainWindow w;
		w.show();
		return a.exec();
	}
	

	
}
