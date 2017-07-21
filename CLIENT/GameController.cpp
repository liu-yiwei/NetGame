#include "GameController.h"
#include "MainWindow.h"
#include<iostream>

GameController::GameController(QObject* parent)
	: QGraphicsScene(parent),
	  QObject(parent),
	  state(GameState::noChosed)
{
	this->setSceneRect(0, 0, 9 * 40, 9 * 40);
}

GameController::GameController(int size, QObject* parent)
	: QGraphicsScene(parent),
	  QObject(parent),
	  size(size),
	  state(GameState::noChosed)
{
	this->setSceneRect(0, 0, size * 40, size * 40);
}


GameController::~GameController()
{
}

//todo:迟早把scene类和controller类合并咯，不少麻烦
//todo:完整实现单机版以后再重构
//电脑在在一个空的位置添加棋子 nothing->still
void
GameController::addBead(int x, int y, BeadColor color) const
{
	this->array[x][y]->setColor(color);
	this->array[x][y]->setState(still);
	this->array[x][y]->update();
}

//人选择棋子
void
GameController::chooseBead(int x, int y)
{
	this->array[x][y]->setState(BeadState::choosed);
}

//人把选中棋子还原
void
GameController::noChooseBead(int x, int y)
{
	this->array[x][y]->setScale(1);
	this->array[x][y]->setState(BeadState::still);
}


//移动一个棋子，调用远处百度百科的A*算法
void
GameController::moveBeadTo(int sx, int sy, int dx, int dy)
{
//	//map的初始化
//	map = new int*[size];
//	for (int i = 0; i < size; i++)
//	{
//		map[i] = new int[size];
//		for (int j = 0; j < size; j++)
//		{
//			map[i][j] = this->array[i][j]->getState() != BeadState::nothing;
//		}
//	}
//
//	//改变初始位置的状态
//	this->array[sx][sy]->setState(BeadState::nothing);
//	this->array[sx][sy]->setColor(BeadColor::no);
//
//	path = getPath(map, 9, 9, sx, sy, dx, dy);//TODO：大小参数暂且不能改
//	if (path->size() == 0)
//	{
//		//todo:移动不了的函数
//	}
//	else
//	{
//		timer.start(500);// 每间隔半秒发一次信号
//	}
//
//	//改变末尾棋子的状态
//	this->array[sx][sy]->setState(BeadState::still);
//	this->array[sx][sy]->setColor(BeadColor::no);
//
//	delete path;
//	delete map;
}

void GameController::deleteBead(int x, int y)
{
}


//TODO：处理单击事件
void GameController::handleBead(int x, int y) const
{
	switch (this->array[x][y]->getState())
	{
	case BeadState::nothing:
		if (this->state == GameState::oneChosed)//choose的时候有用，其他情况跳过
		{
			//todo:移动的代码
		}
		break;
	case BeadState::still:
		if (this->state == noChosed || this->state == oneChosed)
		{
			//TODO:选中棋子的代码
		}
		break;
	case BeadState::choosed:
		Q_ASSERT(this->state == oneChosed);
		//TODO：这种情况什么也不用做

		break;
	case BeadState::needToMove:
		//todo:这种情况也什么都不用做
		break;
	}
}

void GameController::setState(GameState state)
{
	//todo:这里排除一些特殊的状态改变，没太大必要
	this->state = state;
}
