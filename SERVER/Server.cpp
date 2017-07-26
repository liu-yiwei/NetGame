#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "Server.h"
#include "threadhandle.h"

GameServer::GameServer(QObject *parent, int numConnections) :
	QTcpServer(parent)
{
	//�����б��Լ����������Ŀ
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
	this->QTcpServer::setMaxPendingConnections(numConnections);//����Qtcpsocket�����������������������Ҫ��ʹmaxPendingConnections()��Ȼ��Ч
	this->maxConnections = numConnections;
}

void GameServer::incomingConnection(qintptr socketDescriptor) //���̱߳����ڴ˺����ﲶ��������
{
	if (tcpClient->size() > maxPendingConnections())//�̳���д�˺�����QTcpServerĬ�ϵ��ж����������ʧЧ���Լ�ʵ��
	{
		QTcpSocket tcp;
		tcp.setSocketDescriptor(socketDescriptor);
		tcp.disconnectFromHost();
		return;
	}

	//�㵽һ��������
	auto th = ThreadHandle::getClass().getThread();
	auto tcpTemp = new GameSocket(socketDescriptor);
	QString ip = tcpTemp->peerAddress().toString();
	qint16 port = tcpTemp->peerPort();

	connect(tcpTemp, &GameSocket::sockDisConnect, this, &GameServer::sockDisConnectSlot);//NOTE:�Ͽ����ӵĴ������б��Ƴ������ͷŶϿ���Tcpsocket���˲۱���ʵ�֣��̹߳������Ҳ�ǿ�����
	connect(this, &GameServer::sentDisConnect, tcpTemp, &GameSocket::disConTcp);//�Ͽ��ź�

	tcpTemp->moveToThread(th);//��tcp���ƶ����µ��̣߳����̹߳������л�ȡ
	tcpClient->insert(socketDescriptor, tcpTemp);//���뵽������Ϣ��
	emit connectClient(socketDescriptor, ip, port);
}

void GameServer::sockDisConnectSlot(int handle, const QString & ip, quint16 prot, QThread * th)
{
	tcpClient->remove(handle);//���ӹ������Ƴ��Ͽ����ӵ�socket
	ThreadHandle::getClass().removeThread(th); //�����̹߳������Ǹ��߳�������ӶϿ���
	emit sockDisConnect(handle, ip, prot);
}


void GameServer::clear()
{
	emit this->sentDisConnect(-1);
	ThreadHandle::getClass().clear();
	tcpClient->clear();
}
