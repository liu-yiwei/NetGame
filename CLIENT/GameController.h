#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
class QGraphicsScene;

//����������Ϸ���������view��scene��beads��
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

	int gameSize;//���̱߳�

	QGraphicsScene& scene;
	QList<QList<Bead>> beads;

	QTimer timer;
	
	
	
};
