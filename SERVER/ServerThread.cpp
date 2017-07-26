#include "ServerThread.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


//数据的发送和接收
#include <QtNetwork>
ServerThread::ServerThread(int socketDescriptor, const QString &fortune, QObject *parent) 
	:QThread(parent),
	tcpSocket(new QTcpSocket(parent)),
	socketDescriptor(socketDescriptor),
	text(fortune)
{
	connect(this->tcpSocket, &QIODevice::readyRead, this, &ServerThread::readMsg);
}


//用来读取和发送数据
void
ServerThread::run() {

	//初始化socket
	if (!tcpSocket->setSocketDescriptor(socketDescriptor)) {
		emit error(tcpSocket->error());
		return;
	}

	LOG(INFO) << "客户机地址： "<<tcpSocket->peerAddress().toString().toStdString() << " 客户机端口： "
		<< tcpSocket->peerPort()<<" 要发送的数据： "  << text.toStdString() ;
	//连接读取数据的信号槽函数
	QByteArray aa = tcpSocket->readAll();
	QString ss = QVariant(aa).toString();
	LOG(INFO) << ss.toStdString();
	//tcpSocket->write(text.toStdString().c_str(), strlen(text.toStdString().c_str()));

	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
}


	//写数据
	//QByteArray	block;
	//QDataStream out(&block, QIODevice::WriteOnly);//要输出的数据；
	//out.setVersion(QDataStream::Qt_4_0);
	//out << text;
	//
	//tcpSocket->write(block);
	


//接收数据
void
ServerThread::readMsg() {
	exit(0);
	QByteArray aa = tcpSocket->readAll();
	QString ss = QVariant(aa).toString();
	LOG(INFO) << ss.toStdString();
}

//发送数据
void 
ServerThread::sendMsg() {
	tcpSocket->write(text.toStdString().c_str(), strlen(text.toStdString().c_str()));
}
