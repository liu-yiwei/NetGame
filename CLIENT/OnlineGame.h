#pragma once

#include <QTcpSocket>
#include "GameController.h"
#include "OnLineMainWindow.h"

class OnlineGame
{
	
public:
	~OnlineGame();

private:
	QTcpSocket * tcpsocket;
	Ui_MainWindow * m_mainWindow;

};