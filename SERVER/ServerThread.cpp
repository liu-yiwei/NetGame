#include "ServerThread.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QtNetwork>
ServerThread::ServerThread(int socketDescriptor, const QString &fortune, QObject *parent) 
	:QThread(parent),
	tcpSocket(new QTcpSocket(parent)),
	socketDescriptor(socketDescriptor),
	text(fortune)
{
	QObject::connect(tcpSocket, &QIODevice::readyRead, this, &ServerThread::readMsg);

}


//用来读取和发送数据
void
ServerThread::run() {

	if (!tcpSocket->setSocketDescriptor(socketDescriptor)) {
		emit error(tcpSocket->error());
		return;
	}


	
	in.setDevice(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);
	
	//接受读取数据的信号槽
	//todo:加入分析数据的东西
	

	LOG(INFO) << "客户机地址： "<<tcpSocket->peerAddress().toString().toStdString() << " 客户机端口： "
		<< tcpSocket->peerPort()<<" 要发送的数据： "  << text.toStdString();
	
	
	QByteArray	block;
	QDataStream out(&block, QIODevice::WriteOnly);//要输出的数据；
	out.setVersion(QDataStream::Qt_4_0);

	
	
	
	out << text;

	tcpSocket->write(block);
	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
}

void
ServerThread::readMsg() {
	QByteArray b = tcpSocket->readAll();;
	LOG(INFO) << QVariant(b).toString().toStdString();
}


void 
ServerThread::sendMsg() {
	tcpSocket->write(text.toStdString().c_str(), strlen(text.toStdString().c_str()));
}

