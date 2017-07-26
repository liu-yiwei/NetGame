#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "Server.h"
#include "threadhandle.h"

GameServer::GameServer(QObject *parent, int numConnections) :
	QTcpServer(parent)
{
	//连接列表，以及最大连接数目
	tcpClient = new  QHash<int, GameSocket *>;
	setMaxPendingConnections(numConnections);
}

GameServer::~GameServer()
{
	emit this->sentDisConnect(-1);
	delete tcpClient;
}

void GameServer::setMaxPendingConnections(int numConnections)
{
	this->QTcpServer::setMaxPendingConnections(numConnections);//调用Qtcpsocket函数，设置最大连接数，主要是使maxPendingConnections()依然有效
	this->maxConnections = numConnections;
}

void GameServer::incomingConnection(qintptr socketDescriptor) //多线程必须在此函数里捕获新连接
{
	if (tcpClient->size() > maxPendingConnections())//继承重写此函数后，QTcpServer默认的判断最大连接数失效，自己实现
	{
		QTcpSocket tcp;
		tcp.setSocketDescriptor(socketDescriptor);
		tcp.disconnectFromHost();
		return;
	}

	//搞到一个单例类
	auto th = ThreadHandle::getClass().getThread();
	auto tcpTemp = new GameSocket(socketDescriptor);
	QString ip = tcpTemp->peerAddress().toString();
	qint16 port = tcpTemp->peerPort();

	connect(tcpTemp, &GameSocket::sockDisConnect, this, &GameServer::sockDisConnectSlot);//NOTE:断开连接的处理，从列表移除，并释放断开的Tcpsocket，此槽必须实现，线程管理计数也是考的他
	connect(this, &GameServer::sentDisConnect, tcpTemp, &GameSocket::disConTcp);//断开信号

	tcpTemp->moveToThread(th);//把tcp类移动到新的线程，从线程管理类中获取
	tcpClient->insert(socketDescriptor, tcpTemp);//插入到连接信息中
	emit connectClient(socketDescriptor, ip, port);
}

void GameServer::sockDisConnectSlot(int handle, const QString & ip, quint16 prot, QThread * th)
{
	tcpClient->remove(handle);//连接管理中移除断开连接的socket
	ThreadHandle::getClass().removeThread(th); //告诉线程管理类那个线程里的连接断开了
	emit sockDisConnect(handle, ip, prot);
}


void GameServer::clear()
{
	emit this->sentDisConnect(-1);
	ThreadHandle::getClass().clear();
	tcpClient->clear();
}
