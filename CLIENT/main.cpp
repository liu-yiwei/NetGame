#include "MainWindow.h"
#include"ui_LoginDialog.h"
#include <QApplication>

//���ص�½��Ϣ
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
	if (true)//�ж��û���������
	{
		MainWindow w;
		w.show();
		return a.exec();
	}
	

	
}
