#include "GameController.h"
#include "MainWindow.h"
#include<iostream>
#include"CheckerBoard.h"

GameController::GameController(QObject* parent)
	: QObject(parent),
	  gameSize(9),
	  checkerboard(new CheckerBoard(gameSize, parent)),
	  state(BoardState::noChosed)
{
	connect(&timer, SIGNAL(timeout()), checkerboard, SLOT(advance()));
	timer.start(1000 / 33);
}

GameController::GameController(int gameSize, QObject* parent)
	: QObject(parent),
	  gameSize(gameSize),
	  checkerboard(new CheckerBoard(gameSize, parent)),
	  state(BoardState::noChosed)
{
	checkerboard->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
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
	this->checkerboard->array[x][y]->setColor(color);
	this->checkerboard->array[x][y]->setState(still);
	this->checkerboard->array[x][y]->update();
}

//人选择棋子
void
GameController::chooseBead(int x, int y)
{
	this->checkerboard->array[x][y]->setScale(1.3);
	this->checkerboard->array[x][y]->setState(BeadState::choosed);
}

//人把选中棋子还原
void
GameController::noChooseBead(int x,int y)
{
	this->checkerboard->array[x][y]->setScale(1);
	this->checkerboard->array[x][y]->setState(BeadState::still);
}


//移动一个棋子，调用远处百度百科的A*算法
void
GameController::moveBeadTo(int sx, int sy, int dx, int dy)
{

	//改变初始位置的状态
	this->checkerboard->array[sx][sy]->setState(BeadState::nothing);
	this->checkerboard->array[sx][sy]->setColor(BeadColor::no);
}





//TODO：处理单击事件
void GameController::handleBead(int x, int y) const
{
	switch (checkerboard->array[x][y]->getState())
	{
	case BeadState::nothing:
		if (this->state == BoardState::oneChosed)//choose的时候有用，其他情况跳过
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

void GameController::setState(BoardState state)
{
	//todo:这里排除一些特殊的状态改变，没太大必要
	this->state = state;
}


