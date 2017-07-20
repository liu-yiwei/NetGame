#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include "gamescene.h"
#include"CheckerBoard.h"
#include"contants.h"
class QGraphicsScene;

//控制所有游戏对象包括：view，scene，beads，
class GameController
	:public QObject
{
	Q_OBJECT
public:
	
	
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();

	int gameSize;//棋盘边长
	GameScene* scene;


public slots:

	void gameOver();
	void generateBeads(int x,int y,BeadColor color);

	//controller需要维护的东西：棋盘
	//棋盘
private:


	CheckerBoard* checkerboard;
	QTimer timer;
};
