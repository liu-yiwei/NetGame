#pragma once
//////////////////////////////////////////////////////////////////////////
//��Ϸ����
#include <QObject>

//����roomΪ������
class Room
	: public QObject
{
	Q_OBJECT
public:
	QString hostName;//�������ǳ�

};