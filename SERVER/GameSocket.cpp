#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QtConcurrent/QtConcurrent>
#include <QHostAddress>
#include <QDebug>

#include <glog/logging.h>
#include "GameSocket.h"


//重写的socket，增加自带的读写操作
GameSocket::GameSocket(qintptr socketDescriptor, QObject *parent) : 
	QTcpSocket(parent), socketID(socketDescriptor)
{
	this->setSocketDescriptor(socketDescriptor);

	connect(this, &GameSocket::readyRead, this, &GameSocket::readData);//读
	dis = connect(this, &GameSocket::disconnected,
		[&]() {
		emit sockDisConnect(socketID, this->peerAddress().toString(), this->peerPort(), QThread::currentThread());//发送断开连接的用户信息
		this->deleteLater();
	});
	connect(&watcher, &QFutureWatcher<QByteArray>::finished, this, &GameSocket::startNext);
	connect(&watcher, &QFutureWatcher<QByteArray>::canceled, this, &GameSocket::startNext);
	LOG(INFO) << "新的连接";
}

GameSocket::~GameSocket()
{
}

//槽函数：
void GameSocket::sentData(const QByteArray &data, const int id)
{
	if (id == socketID)
	{
		write(data);
	}
}

void GameSocket::disConTcp(int i)
{
	if (i == socketID)
	{
		this->disconnectFromHost();
	}
	else if (i == -1) //-1为全部断开
	{
		disconnect(dis); //先断开连接的信号槽，防止二次析构
		this->disconnectFromHost();
		this->deleteLater();
	}
}
void GameSocket::readData()
{
	//    datas.append(this->readAll());
	auto data = handleData(this->readAll(), this->peerAddress().toString(), this->peerPort());
	qDebug() << data;
	LOG(INFO) << data.toStdString();
	//这里处理数据,把数据显示在界面
	this->write(data);

}

//格式化数据
QByteArray GameSocket::handleData(QByteArray data, const QString &ip, qint16 port)
{
	QTime time;
	time.start();

	QElapsedTimer tm;
	tm.start();
	while (tm.elapsed() < 100)
	{
	}
	data = ip.toUtf8() + " " + QByteArray::number(port) + " " + data + " " + QTime::currentTime().toString().toUtf8();
	return data;
}

void GameSocket::startNext()
{
	this->write(watcher.future().result());
	if (!datas.isEmpty())
	{
		watcher.setFuture(QtConcurrent::run(this, &GameSocket::handleData, datas.dequeue(), this->peerAddress().toString(), this->peerPort()));
	}
}
