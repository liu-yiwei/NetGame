#include "GameController.h"
#include "MainWindow.h"
#include<iostream>
#include <locale>

GameController::GameController(QObject* parent)
	: QGraphicsScene(parent),
	state(GameState::noChosed),
	size(9),
	nextBeads(new ThreeBeads),
	choosed(new Point)
{
	srand(time(0));
	this->setSceneRect(0, 0, 9 * 40, 9 * 40);


	//��ʼ������
	array = new Bead**[size];
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

	//��ʼ����ͼ
	map = new int*[size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j] = this->array[i][j]->getState() != BeadState::nothing;
		}
	}//todo������Ϸ�����map
	generateThreeBeads();
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


//�ƶ�һ�����ӣ�����Զ���ٶȰٿƵ�A*�㷨
void
GameController::moveBeadTo(int sx, int sy, int dx, int dy)
{
	this->setState(GameState::oneMove);

	std::vector<Point> temp = getPath(map, 9, 9, sx, sy, dx, dy);//TODO����С�������Ҳ��ܸ�
	path.clear();
	path.assign(temp.begin(), temp.end());

	for (int i = 0; i < path.size(); i++)
	{
		for (int j = 0; j<100000; j++)
		{
			printf("adsfasdfasdfadsf");
		}
		this->array[path[i].x][path[i].y]->setState(BeadState::still);

		this->array[path[i].x][path[i].y]->setColor(BeadColor::green);

	}

	for (int i = 0; i < path.size(); i++)
	{
		if (i == path.size() - 1) break;
		this->array[path[i].x][path[i].y]->setState(BeadState::nothing);
		this->array[path[i].x][path[i].y]->setColor(BeadColor::no);

	}

	this->setState(GameState::noChosed);
}


void GameController::deleteBead(int x, int y)
{
}


//TODO���������¼�,����������״̬�ı�
void GameController::handleBead(int x, int y)
{
	//	�ж������ƶ�ʱ��û������¼�
	if (this->state == GameState::oneMove) return;

	if (this->state == GameState::noChosed)//û�ж�����ѡ�е�ʱ��
	{
		if (this->array[x][y]->getState() == BeadState::still)
		{
			this->array[x][y]->setState(BeadState::choosed);
			this->setState(GameState::oneChosed);

			this->choosed->x = x;
			this->choosed->y = y;
			return;
		}
		else
		{
			return;
		}
	}

	if (this->state == GameState::oneChosed)
	{
		if (this->array[x][y]->getState() == BeadState::choosed)//�����ѡ�е����ӻ��ߵ��û�е����ӣ���ѡ�еĶ����ûѡ��
		{
			this->array[x][y]->setState(BeadState::still);
			this->setState(GameState::noChosed);
			return;
		}
		else if (this->array[x][y]->getState() == BeadState::nothing)//����ط�û�ж���
		{
			moveBeadTo(choosed->x, choosed->y, x, y);//todo:�������Ҳ����������ı�״̬��,�����������������Ǹı�״̬�ĺ���
			this->setState(GameState::oneMove);
			return;
		}
		else if (this->array[x][y]->getState() == BeadState::still)//����ط������ӣ�ѡ���������ԭ��
		{
			this->array[choosed->x][choosed->y]->setState(BeadState::still);
			this->array[x][y]->setState(BeadState::choosed);
			this->choosed->x = x;
			this->choosed->y = y;
			return;
		}
	}
}

void GameController::setState(GameState state)
{
	//todo:�����ų�һЩ�����״̬�ı䣬û̫���Ҫ
	this->state = state;
}

void GameController::generateThreeBeads()
{
	while (true)
	{
		nextBeads->one.x = rand() % size;
		nextBeads->one.y = rand() % size;
		nextBeads->one.color = Bead::getColorByInt(rand() * rand() % 7 + 1);
		if (this->array[nextBeads->one.x][nextBeads->one.y]->getState() == BeadState::nothing)
			break;
	}


	while (true)
	{
		nextBeads->two.x = rand() % size;
		nextBeads->two.y = rand() % size;
		nextBeads->two.color = Bead::getColorByInt(rand() % 7 + 1);
		if (!(bEqual(nextBeads->one, nextBeads->two))
			&& this->array[nextBeads->two.x][nextBeads->two.y]->getState() == BeadState::nothing)
			break;
	}


	while (true)
	{
		nextBeads->three.x = rand() % size;
		nextBeads->three.y = rand() % size;
		nextBeads->three.color = Bead::getColorByInt(rand()*rand() / rand() % 7 + 1);
		if (!(bEqual(nextBeads->one, nextBeads->three)
			&& !bEqual(nextBeads->two, nextBeads->three)
			&& this->array[nextBeads->three.x][nextBeads->three.y]->getState() == BeadState::nothing))
			break;
	}

	addBead(nextBeads->one.x, nextBeads->one.y, nextBeads->one.color);
	addBead(nextBeads->two.y, nextBeads->two.y, nextBeads->two.color);
	addBead(nextBeads->three.x, nextBeads->three.y, nextBeads->three.color);
}

bool
GameController::bEqual(p p1, p p2)
{
	if (p1.x == p2.x && p1.y == p2.y && p1.color == p2.color)
		return true;
	return false;
}