#include "GameServer.h"

GameServer::GameServer(QObject* parent)
	:QTcpServer(parent)
{
}

GameServer::~GameServer()
{
}

void GameServer::incomingConnection(qintptr socketDescriptor)
{
}
