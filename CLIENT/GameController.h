#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include "gamescene.h"
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

private:


	QList<QList<Bead>> beads;

	QTimer timer;
};
