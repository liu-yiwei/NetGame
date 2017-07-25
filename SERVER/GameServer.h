#pragma once
#include <QObject>
#include <QTcpServer>
#include "DB.h"

class GameServer
	:public QTcpServer
{
	Q_OBJECT
public:
	explicit GameServer(QObject* parent = 0);
	~GameServer();

	DB *db;
protected:
	void incomingConnection(qintptr socketDescriptor) override;

};
