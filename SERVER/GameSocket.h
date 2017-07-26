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
	QByteArray handleData(QByteArray data, const QString & ip, qint16 port);//�����������ݵĺ���

signals:
	void sockDisConnect(const int, const QString &, const quint16, QThread *);//NOTE:�Ͽ����ӵ��û���Ϣ�����źű��뷢�����̹߳���������źż�����

public slots:
	void sentData(const QByteArray &, const int);//�����źŵĲ�
	void disConTcp(int i);

protected slots:
	void readData();//��������
	void startNext();//������һ��

protected:
	QFutureWatcher<QByteArray> watcher;
	QQueue<QByteArray> datas;
private:
	qintptr socketID;
	QMetaObject::Connection dis;
};

