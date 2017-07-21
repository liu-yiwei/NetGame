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

//todo:�����scene���controller��ϲ����������鷳
//todo:����ʵ�ֵ������Ժ����ع�
//��������һ���յ�λ��������� nothing->still
void
GameController::addBead(int x, int y, BeadColor color) const
{
	this->array[x][y]->setColor(color);
	this->array[x][y]->setState(still);
	this->array[x][y]->update();
}

//��ѡ������
void
GameController::chooseBead(int x, int y)
{
	this->array[x][y]->setState(BeadState::choosed);
}

//�˰�ѡ�����ӻ�ԭ
void
GameController::noChooseBead(int x, int y)
{
	this->array[x][y]->setScale(1);
	this->array[x][y]->setState(BeadState::still);
}


//�ƶ�һ�����ӣ�����Զ���ٶȰٿƵ�A*�㷨
void
GameController::moveBeadTo(int sx, int sy, int dx, int dy)
{
//	//map�ĳ�ʼ��
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
//	//�ı��ʼλ�õ�״̬
//	this->array[sx][sy]->setState(BeadState::nothing);
//	this->array[sx][sy]->setColor(BeadColor::no);
//
//	path = getPath(map, 9, 9, sx, sy, dx, dy);//TODO����С�������Ҳ��ܸ�
//	if (path->size() == 0)
//	{
//		//todo:�ƶ����˵ĺ���
//	}
//	else
//	{
//		timer.start(500);// ÿ������뷢һ���ź�
//	}
//
//	//�ı�ĩβ���ӵ�״̬
//	this->array[sx][sy]->setState(BeadState::still);
//	this->array[sx][sy]->setColor(BeadColor::no);
//
//	delete path;
//	delete map;
}

void GameController::deleteBead(int x, int y)
{
}


//TODO���������¼�
void GameController::handleBead(int x, int y) const
{
	switch (this->array[x][y]->getState())
	{
	case BeadState::nothing:
		if (this->state == GameState::oneChosed)//choose��ʱ�����ã������������
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

void GameController::setState(GameState state)
{
	//todo:�����ų�һЩ�����״̬�ı䣬û̫���Ҫ
	this->state = state;
}
