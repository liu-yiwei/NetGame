#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include<QGraphicsItem>
#include<QMessageBox>

class GameScene :public QGraphicsScene
{

public:
	GameScene(QObject *parent);

protected:
	void mousePressEvent(QMouseEvent *event);
};

#endif // GAMESCENE_H
