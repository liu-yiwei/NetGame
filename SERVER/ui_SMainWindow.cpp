
#include"Config.h"
#include<iostream>
#include <windows.h>
#include"ui_SMainWindow.h"
//��iocp�Ķ������ӵ���
using namespace std;
//���캯��
Ui_MainWindow::Ui_MainWindow(QWidget * parent)
	:QMainWindow(parent)
	
	//m_IOCP(new CIOCPModel())
{
	setupUi(this);
	m_server = new GameServer(this,8888);
	m_server->listen(QHostAddress::Any, 6666);
	//m_IOCP->setMainWindow(this);
	//Init();
}



//////////////////////////////////////////////////////////////////////
// ��ʼ��Socket���Լ�������Ϣ
//void 
//Ui_MainWindow::Init()
//{
//	Config configSettings("server.ini");
//	// ��ʼ��Socket��
//	if (false == this->m_IOCP->LoadSocketLib())
//	{
//		LOG(INFO) << "����Winsock 2.2ʧ�ܣ����������޷����У�";
//		PostQuitMessage(0);
//	}
//
//	// ���ñ���IP��ַ
////	SetDlgItemText(IDC_STATIC_SERVERIP, m_IOCP.GetLocalIP());
//
//
//	std::string saveInfo = configSettings.Read("saveInfo", saveInfo);
//	std::string port = configSettings.Read("port", port);
//	std::string dbip = configSettings.Read("dbip", dbip);
//	std::string dbUserName = configSettings.Read("dbUserName", dbUserName);
//	std::string dbPassWord = configSettings.Read("dbPassWord", dbPassWord);
//	
//	
//	if (saveInfo.compare("True") == 0)
//	{
//		this->LineEdit_IP->setText(QString::fromStdString(saveInfo));//����IP
//		this->LineEdit_port->setText(QString::fromStdString(port));
//		this->LineEdit_IP->setText(QString::fromStdString(dbip));
//		this->LineEdit_dbUserName->setText(QString::fromStdString(dbUserName));
//		this->LineEdit_dbPassWord->setText(QString::fromStdString(dbPassWord));
//	}
//	else
//	{
//		this->LineEdit_IP->setText(QString::fromStdString(m_IOCP->getLocalIP()));
//	}
//
//	
//	m_IOCP->Start();
//
//}