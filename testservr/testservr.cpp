#include "testservr.h"
#include <QLineEdit>
testservr::testservr(QWidget *parent)
	: QMainWindow(parent),
	socket(new QTcpSocket)
{
	ui.setupUi(this);
	this->socket->abort();	
	sendMsg();
	this->socket->connectToHost("127.0.0.1", 8888);

	
	connect(this->socket, &QIODevice::readyRead, this, &testservr::redMsg);
	connect(ui.pushButton, &QPushButton::clicked, this, &testservr::sendMsg);
}
void
testservr::redMsg() {
	QByteArray aa = this->socket->readAll();
	QString ss = QVariant(aa).toString();
	ui.lineEdit->setText(ss);
}

void
testservr::sendMsg() {
	QString ss = "liuyiwei";
	socket->write(ss.toStdString().c_str(), strlen(ss.toStdString().c_str()));
	ui.lineEdit->clear();
	ui.lineEdit->setText(ss);
}