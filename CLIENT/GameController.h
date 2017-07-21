#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include"CheckerBoard.h"
#include"contants.h"
class QGraphicsScene;

//整个游戏的状态：
//没有棋子被选中，一个棋子被选中，正在运动，
enum BoardState
{
	noChosed,oneChosed,oneMove
};

//控制所有游戏对象包括：view，scene，beads，
class GameController
	:public QObject
{
	Q_OBJECT
public:
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();
	void addBead(int x, int y, BeadColor color) const;
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);

	void handleBead(int x, int y) const;//处理对一个棋子格子的点击事件
	void setState(BoardState state);
	QTimer timer;
	int gameSize;//棋盘边长
	COOR* path;

	CheckerBoard* checkerboard;
	BoardState state;

};
