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


class QGraphicsScene;

//������Ϸ��״̬��
//û�����ӱ�ѡ�У�һ�����ӱ�ѡ�У������˶���
enum GameState
{
	noChosed,
	oneChosed,
	oneMove
};

//ά��һ�����̣���������һ�����̵����ж���
//����ฺ��ִ�о���Ĳ���
class GameController :public QGraphicsScene
{
public:
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();

	void addBead(int x, int y, BeadColor color);
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void move();

	void deleteBead(int x, int y);
	void handleBead(int x, int y);//�����һ�����Ӹ��ӵĵ���¼�
	void setState(GameState state);

public slots:
	void move(int x, int y);


	GameState state;
	std::vector<Point> path;
	int** map;

	Point* choosed;//�ѱ�ѡ�е�����

	QTimer *timer;

	//�������Ӷ�������
	Bead*** array;//TODO������ǵÿ�����������û

private:
	int size;
};
