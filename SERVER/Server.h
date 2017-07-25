#pragma once
#include <QTcpServer>
//房间列表由server类维护，不用数据库了
#include "glog/logging.h"
class Ui_MainWindow;
class Server
	:public QTcpServer
{
	Q_OBJECT
public:
	Server(Ui_MainWindow * main,int port);
	~Server();
	void setPort(int port);
protected:
	void incomingConnection(qintptr socketDescriptor) override;


private:
	Ui_MainWindow *m_pmain;
	int port;
	QStringList fortunes;

};
