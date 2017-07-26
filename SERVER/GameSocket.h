#pragma once
#include <QTcpSocket>
#include <QQueue>
#include <QFutureWatcher>
#include <QByteArray>

#include <QTime>
class GameSocket : public QTcpSocket
{
	Q_OBJECT
public:
	explicit GameSocket(qintptr socketDescriptor, QObject *parent = 0);
	~GameSocket();
	QByteArray handleData(QByteArray data, const QString & ip, qint16 port);//用来处理数据的函数

signals:
	void sockDisConnect(const int, const QString &, const quint16, QThread *);//NOTE:断开连接的用户信息，此信号必须发出！线程管理类根据信号计数的

public slots:
	void sentData(const QByteArray &, const int);//发送信号的槽
	void disConTcp(int i);

protected slots:
	void readData();//接收数据
	void startNext();//处理下一个

protected:
	QFutureWatcher<QByteArray> watcher;
	QQueue<QByteArray> datas;
private:
	qintptr socketID;
	QMetaObject::Connection dis;
};

