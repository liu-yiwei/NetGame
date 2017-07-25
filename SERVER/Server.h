#pragma once
#include <QTcpServer>
//�����б���server��ά�����������ݿ���
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
