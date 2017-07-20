#include "GameThread.h"


GameThread::GameThread(int socketDescriptor, QObject* parent)
	: QThread(parent),
	  socketDescriptor(socketDescriptor)
{
}

void GameThread::run()
{
	QTcpSocket tcpSocket;
	if (!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		return;
	}

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_9);

	out << text;
	tcpSocket.write(block);
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}
