#include "GameController.h"
#include "MainWindow.h"
#include<iostream>
#include <locale>

GameController::GameController(QObject* parent)
	: QGraphicsScene(parent),
	  state(GameState::noChosed),
	  size(9)
{
	this->setSceneRect(0, 0, 9 * 40, 9 * 40);
	array = new Bead** [size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = new Bead*[size];
		for (int j = 0; j < size; j++)
		{
			array[i][j] = new Bead();//who care
			this->addItem(array[i][j]);
			array[i][j]->setPos(i * 40 + 20, j * 40 + 20);
		}
	}
}

GameController::GameController(int size, QObject* parent)
	: QGraphicsScene(parent),
	  size(size),
	  state(GameState::noChosed),
	  timer(new QTimer(this))
{
	this->setSceneRect(0, 0, size * 40, size * 40);
}


GameController::~GameController()
{
	delete map;
}

//todo:迟早把scene类和controller类合并咯，不少麻烦
//todo:完整实现单机版以后再重构
//电脑在在一个空的位置添加棋子 nothing->still
void
GameController::addBead(int x, int y, BeadColor color)
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
	this->setState(GameState::oneMove);

	//map的初始化
	map = new int*[size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j] = this->array[i][j]->getState() != BeadState::nothing;
		}
	}//todo：在游戏运行中更新map


	std::vector<Point> temp = getPath(map, 9, 9, sx, sy, dx, dy);//TODO：大小参数暂且不能改
	path.clear();
	path.assign(temp.begin(), temp.end());

	for (int i = 0; i < 4; i++)
	{

		this->array[path[i].x][path[i].y]->setState(BeadState::still);
		this->array[path[i].x][path[i].y]->setColor(BeadColor::green);
	}
}


void GameController::deleteBead(int x, int y)
{
}


//TODO：处理单击事件,负责了所有状态改变
void GameController::handleBead(int x, int y)
{
	moveBeadTo(0, 0, 3, 3);
	//	//有东西在移动时，没有鼠标事件
	//	if (this->state == GameState::oneMove)
	//		return;
	//	if (this->state == GameState::noChosed)//没有东西被选中的时候
	//	{
	//		if (this->array[x][y]->getState() == BeadState::still)
	//		{
	//			this->array[x][y]->setState(BeadState::choosed);
	//		}
	//	}
	//
	//	if (this->state == GameState::oneChosed)
	//	{
	//		if (this->array[x][y]->getState() == BeadState::choosed)//点击被选中的棋子或者点击没有的棋子，已选中的都变成没选中
	//		{
	//			this->array[choosed->x][y]->setState(BeadState::still);
	//		}
	//		else if (this->array[x][y]->getState() == BeadState::nothing)//这个地方没有东西
	//		{
	//			moveBeadTo(choosed->x, choosed->y, x, y);//todo:这个函数也是用来负责改变状态的,所以这个函数整体就是改变状态的函数
	//		}
	//		else if (this->array[x][y]->getState() == BeadState::still)//这个地方有妻子，选中这个放弃原来
	//		{
	//			this->array[choosed->x][choosed->y]->setState(BeadState::still);
	//			this->array[x][y]->setState(BeadState::choosed);
	//		}
	//	}
	//
	//	if (this->array[x][y]->getState() == BeadState::nothing)
	//	{
	//		addBead(x, y, BeadColor::RosyBrown);
	//	}
	//	else if (this->array[x][y]->getState() == BeadState::still)
	//	{
	//		this->array[x][y]->setState(BeadState::choosed);
	//	}
}

void GameController::setState(GameState state)
{
	//todo:这里排除一些特殊的状态改变，没太大必要
	this->state = state;
}
