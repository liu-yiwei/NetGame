#pragma once
#include<QTcpSocket>
#include <QtWidgets/QMainWindow>
#include "ui_testservr.h"

class testservr : public QMainWindow
{
	Q_OBJECT

public:
	testservr(QWidget *parent = Q_NULLPTR);

public slots:
	void redMsg();
private:
	Ui::testservrClass ui;
	QTcpSocket *socket;
	void sendMsg();
};
