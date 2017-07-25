#pragma once
#include <QThread>
#include <QTcpSocket>

#include "glog/logging.h"
//! [0]
#include <QDataStream>
class ServerThread : public QThread
{
	Q_OBJECT

public:
	ServerThread(int socketDescriptor, const QString &fortune, QObject *parent);

	void run() override;

signals:
	void error(QTcpSocket::SocketError socketError);

private slots:
	void readMsg();
	void sendMsg();

private:
	int socketDescriptor;
	QString text;
	QTcpSocket* tcpSocket;
	QDataStream in;

};
//! [0]

