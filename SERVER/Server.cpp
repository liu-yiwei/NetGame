#include <Server.h>
#include "ServerThread.h"
#include "ui_SMainWindow.h"


Server::Server(Ui_MainWindow * main,int port)
	:QTcpServer(main),
	m_pmain(main),
	port(port)
{
	fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
		<< tr("You've got to think about tomorrow.")
		<< tr("You will be surprised by a loud noise.")
		<< tr("You will feel hungry again in another hour.")
		<< tr("You might have mail.")
		<< tr("You cannot kill time without injuring eternity.")
		<< tr("Computers are not intelligent. They only think they are.");

	this->listen(QHostAddress::AnyIPv4, 8888);
	LOG(INFO) << "服务器已被初始化，监听端口号：" << this->serverPort();
}

void
Server::incomingConnection(qintptr socketDescriptor) {
	LOG(INFO) << "新连接："  << "连接描述符:" <<socketDescriptor;
	QString fortune = fortunes.at(qrand() % fortunes.size());
	ServerThread * thread = new ServerThread(socketDescriptor, fortune, this);
	connect(thread, SIGNAL(finished()),thread,SLOT(deleteLater()));
	thread->start();
}

Server::~Server()
{
} 

void
Server::setPort(int port) {
	this->port = port;
}