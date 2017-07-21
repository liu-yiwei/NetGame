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

//todo:�����scene���controller��ϲ����������鷳
//todo:����ʵ�ֵ������Ժ����ع�
//��������һ���յ�λ��������� nothing->still
void 
GameController::addBead(int x, int y, BeadColor color) const
{
	this->checkerboard->array[x][y]->setColor(color);
	this->checkerboard->array[x][y]->setState(still);
	this->checkerboard->array[x][y]->update();
}

//��ѡ������
void
GameController::chooseBead(int x, int y)
{
	this->checkerboard->array[x][y]->setScale(1.3);
	this->checkerboard->array[x][y]->setState(BeadState::choosed);
}

//�˰�ѡ�����ӻ�ԭ
void
GameController::noChooseBead(int x,int y)
{
	this->checkerboard->array[x][y]->setScale(1);
	this->checkerboard->array[x][y]->setState(BeadState::still);
}


//�ƶ�һ�����ӣ�����Զ���ٶȰٿƵ�A*�㷨
void
GameController::moveBeadTo(int sx, int sy, int dx, int dy)
{

	//�ı��ʼλ�õ�״̬
	this->checkerboard->array[sx][sy]->setState(BeadState::nothing);
	this->checkerboard->array[sx][sy]->setColor(BeadColor::no);
}





//TODO���������¼�
void GameController::handleBead(int x, int y) const
{
	switch (checkerboard->array[x][y]->getState())
	{
	case BeadState::nothing:
		if (this->state == BoardState::oneChosed)//choose��ʱ�����ã������������
		{
		//todo:�ƶ��Ĵ���
		}
		break;
	case BeadState::still:
		if (this->state == noChosed || this->state == oneChosed)
		{
		//TODO:ѡ�����ӵĴ���
		}
		break;
	case BeadState::choosed:
		Q_ASSERT(this->state == oneChosed);
		//TODO���������ʲôҲ������

		break;
	case BeadState::needToMove:
		//todo:�������Ҳʲô��������
		break;
	}
}

void GameController::setState(BoardState state)
{
	//todo:�����ų�һЩ�����״̬�ı䣬û̫���Ҫ
	this->state = state;
}


