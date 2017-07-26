#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include<QGraphicsScene>
#include"contants.h"
#include "AStar.h"
#include<vector>
#include<time.h>
#include<stdio.h>
#include<iostream>
#include<ctime>
typedef struct {
	int x;
	int y;
	BeadColor color;
}p;
typedef struct
{
	p one, two, three;
} ThreeBeads;;

class QGraphicsScene;

//整个游戏的状态：
//没有棋子被选中，一个棋子被选中，正在运动，
enum GameState
{
	noChosed,
	oneChosed,
	oneMove
};
class MainWindow;

//维护一个棋盘，完整包含一个棋盘的所有东西
//这个类负责执行具体的操作
class GameController :public QGraphicsScene
{
	Q_OBJECT
public:
	GameController(MainWindow *mainWindow);
	GameController(int gameSize, QObject* parent);
	~GameController();

	void addBead(int x, int y, BeadColor color);
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void move();

	void moveOne(int x, int y, int dx, int dy);

	void deleteBead(int x, int y);
	void handleBead(int x, int y);//处理对一个棋子格子的点击事件
	void setState(GameState state);

	void generateThreeBeads();
	static bool bEqual(p p1, p p2);




	GameState state;
	std::vector<Point> path;
	int** map;

	Point* choosed;//已被选中的坐标
	ThreeBeads* nextBeads;

	//所有棋子都在这里
	Bead*** array;//TODO：出错记得看这里有问题没
	//移动结束之后的扫尾工作，包括
	public slots:
	void affterMoveAni();
private:
	int size;
	int score;
	MainWindow *m_mainWindow;

	QTimeLine *timer;
	QGraphicsItemAnimation *animation;
};
