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

//todo:�����scene���controller��ϲ����������鷳
//todo:����ʵ�ֵ������Ժ����ع�
//��������һ���յ�λ��������� nothing->still
void
GameController::addBead(int x, int y, BeadColor color)
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
	this->setState(GameState::oneMove);

	//map�ĳ�ʼ��
	map = new int*[size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j] = this->array[i][j]->getState() != BeadState::nothing;
		}
	}//todo������Ϸ�����и���map


	std::vector<Point> temp = getPath(map, 9, 9, sx, sy, dx, dy);//TODO����С�������Ҳ��ܸ�
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


//TODO���������¼�,����������״̬�ı�
void GameController::handleBead(int x, int y)
{
	moveBeadTo(0, 0, 3, 3);
	//	//�ж������ƶ�ʱ��û������¼�
	//	if (this->state == GameState::oneMove)
	//		return;
	//	if (this->state == GameState::noChosed)//û�ж�����ѡ�е�ʱ��
	//	{
	//		if (this->array[x][y]->getState() == BeadState::still)
	//		{
	//			this->array[x][y]->setState(BeadState::choosed);
	//		}
	//	}
	//
	//	if (this->state == GameState::oneChosed)
	//	{
	//		if (this->array[x][y]->getState() == BeadState::choosed)//�����ѡ�е����ӻ��ߵ��û�е����ӣ���ѡ�еĶ����ûѡ��
	//		{
	//			this->array[choosed->x][y]->setState(BeadState::still);
	//		}
	//		else if (this->array[x][y]->getState() == BeadState::nothing)//����ط�û�ж���
	//		{
	//			moveBeadTo(choosed->x, choosed->y, x, y);//todo:�������Ҳ����������ı�״̬��,�����������������Ǹı�״̬�ĺ���
	//		}
	//		else if (this->array[x][y]->getState() == BeadState::still)//����ط������ӣ�ѡ���������ԭ��
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
	//todo:�����ų�һЩ�����״̬�ı䣬û̫���Ҫ
	this->state = state;
}
