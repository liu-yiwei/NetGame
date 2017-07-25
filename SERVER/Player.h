#pragma once
#include <QObject>
#include <QString>

class Room;

class Player:public QObject
{
public:
	Player(QString name,QString ip,QObject * parent = 0);
	~Player();
	


	QString name;//玩家昵称
	QString ip;//玩家ip
	int score;//玩家分数
	Room * room;//玩家所在的房间
};

Player::Player(QString name,QString ip,QObject * parent )
	:QObject(parent),
	name(name),
	ip(ip),
	score(0)
{
}

Player::~Player()
{
}