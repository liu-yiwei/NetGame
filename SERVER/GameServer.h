#pragma once
#include <QObject>
#include <QTcpServer>

class GameServer
	:public QTcpServer
{
	Q_OBJECT
public:
	explicit GameServer(QObject* parent = 0);
	~GameServer();


protected:
	void incomingConnection(qintptr socketDescriptor) override;

};
