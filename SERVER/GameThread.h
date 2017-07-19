#pragma once
#include <QThread>
#include <QTcpSocket>
#include<qdatastream.h>

class GameThread
	:public QThread
{
	Q_OBJECT
public:
	GameThread(int socketDescriptor,QObject *parent);
	void run() override;
signals:
	void error(QTcpSocket::SocketError socketError);

private:
	int socketDescriptor;
	QString text;
};
