#pragma once
#include <QTcpSocket
#include <QtWidgets/QMainWindow>
#include "ui_tests.h"

class tests : public QMainWindow
{
	Q_OBJECT

public:
	tests(QWidget *parent = Q_NULLPTR);

private:
	Ui::testsClass ui;
	QTcpSocket * socket;
};
