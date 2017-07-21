#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include<QGraphicsScene>
#include"contants.h"
#include "AStar.h"


class QGraphicsScene;

//整个游戏的状态：
//没有棋子被选中，一个棋子被选中，正在运动，
enum GameState
{
	noChosed, oneChosed, oneMove
};

//维护一个棋盘，完整包含一个棋盘的所有东西
//这个类负责执行具体的操作
class GameController :public QGraphicsScene , public QObject
{
	Q_OBJECT
public:
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();

	void addBead(int x, int y, BeadColor color) const;
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);

	void deleteBead(int x, int y);
	void handleBead(int x, int y) const;//处理对一个棋子格子的点击事件
	void setState(GameState state);

	GameState state;
	std::vector<Point> * path;
	int** map;

	QTimer timer;

	//所有棋子都在这里
	Bead*** array;//TODO：出错记得看这里有问题没

private:
	int size;
};