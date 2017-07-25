#pragma once
//////////////////////////////////////////////////////////////////////////
//游戏房间
#include <QObject>

//初定room为两个人
class Room
	: public QObject
{
	Q_OBJECT
public:
	QString hostName;//房主的昵称

};