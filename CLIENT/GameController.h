#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
class QGraphicsScene;

//控制所有游戏对象包括：view，scene，beads，
class GameController
	:public QObject
{
	Q_OBJECT
public:
	GameController(QGraphicsScene& scene, QObject* parent);
	~GameController();

public slots:
	void gameOver();

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:

	int gameSize;//棋盘边长

	QGraphicsScene& scene;
	QList<QList<Bead>> beads;

	QTimer timer;
	
	
	
};
