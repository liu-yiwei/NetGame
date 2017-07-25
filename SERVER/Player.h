#pragma once
#include <QObject>
#include <QString>

class Room;

class Player:public QObject
{
public:
	Player(QString name,QString ip,QObject * parent = 0);
	~Player();
	


	QString name;//����ǳ�
	QString ip;//���ip
	int score;//��ҷ���
	Room * room;//������ڵķ���
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