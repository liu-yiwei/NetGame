#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QtConcurrent/QtConcurrent>
#include <QHostAddress>
#include <QDebug>

#include <glog/logging.h>
#include "GameSocket.h"


//��д��socket�������Դ��Ķ�д����
GameSocket::GameSocket(qintptr socketDescriptor, QObject *parent) : 
	QTcpSocket(parent), socketID(socketDescriptor)
{
	this->setSocketDescriptor(socketDescriptor);

	connect(this, &GameSocket::readyRead, this, &GameSocket::readData);//��
	dis = connect(this, &GameSocket::disconnected,
		[&]() {
		emit sockDisConnect(socketID, this->peerAddress().toString(), this->peerPort(), QThread::currentThread());//���ͶϿ����ӵ��û���Ϣ
		this->deleteLater();
	});
	connect(&watcher, &QFutureWatcher<QByteArray>::finished, this, &GameSocket::startNext);
	connect(&watcher, &QFutureWatcher<QByteArray>::canceled, this, &GameSocket::startNext);
	LOG(INFO) << "�µ�����";
}

GameSocket::~GameSocket()
{
}

//�ۺ�����
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
	else if (i == -1) //-1Ϊȫ���Ͽ�
	{
		disconnect(dis); //�ȶϿ����ӵ��źŲۣ���ֹ��������
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
	//���ﴦ������,��������ʾ�ڽ���
	this->write(data);

}

//��ʽ������
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
