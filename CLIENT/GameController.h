#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include "gamescene.h"
#include"CheckerBoard.h"
#include"contants.h"
class QGraphicsScene;

//����������Ϸ���������view��scene��beads��
class GameController
	:public QObject
{
	Q_OBJECT
public:
	
	
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();

	int gameSize;//���̱߳�
	GameScene* scene;


public slots:

	void gameOver();
	void generateBeads(int x,int y,BeadColor color);

	//controller��Ҫά���Ķ���������
	//����
private:


	CheckerBoard* checkerboard;
	QTimer timer;
};
