#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "OnLineMainWindow.h"

Ui_MainWindow::Ui_MainWindow()
	:MainWindow(),
	score2(new QLCDNumber(this->centralWidget)),
	chatRecard(new QTextBrowser(this->centralWidget)),
	but_lose(new QPushButton(this->centralWidget)),
	but_send(new QPushButton(this->centralWidget)),
	edit_info(new QLineEdit(this->centralWidget)),
	playerInfo(new QLineEdit(this->centralWidget))
{
	this->initUI();
	
}

void Ui_MainWindow::initUI()
{

	score2->setGeometry(481, 1, 120, 80);
	score2->display(0);

	playerInfo->setGeometry(361, 81, 240, 40);
	playerInfo->setEnabled(false);
	playerInfo->setText("asdf");
	playerInfo->setFont(QFont("黑体", 28, QFont::Bold));

	this->view2->setGeometry(361, 41, 120, 40);
	
	chatRecard->setGeometry(361, 121, 240, 160);
	chatRecard->setFont(QFont("微软雅黑", 10));
	chatRecard->setStyleSheet("background-color:#778899");//背景色  
	chatRecard->setText("liuyiwei(127.0.0.1:8888):");

	edit_info->setGeometry(361, 281, 240, 40);
	edit_info->setFont(QFont("微软雅黑", 28, QFont::Bold));
	edit_info->setStyleSheet("background-color:#B9D3EE");
	

	but_send->setGeometry(362, 322, 118, 38);
	but_send->setFont(QFont("幼圆", 15));
	but_send->setFlat(true);
	but_lose->setGeometry(482, 322, 118, 38);
	but_lose->setFont(QFont("幼圆", 15));
	but_lose->setFlat(true);
	
	but_send->setText("发送");
	but_lose->setText("投降");
	this->setFixedSize(602, 387);
}


