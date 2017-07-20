#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include "gamescene.h"
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

private:


	QList<QList<Bead>> beads;

	QTimer timer;
};
