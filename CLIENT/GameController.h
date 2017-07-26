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

//������Ϸ��״̬��
//û�����ӱ�ѡ�У�һ�����ӱ�ѡ�У������˶���
enum GameState
{
	noChosed,
	oneChosed,
	oneMove
};
class MainWindow;

//ά��һ�����̣���������һ�����̵����ж���
//����ฺ��ִ�о���Ĳ���
class GameController :public QGraphicsScene
{
	Q_OBJECT
public:
	GameController(MainWindow *mainWindow);
	GameController(int gameSize, QObject* parent);
	~GameController();

	void addBead(int x, int y, BeadColor color);
	void chooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void remove();
	void removeBead(int x, int y);


	void deleteBead(int x, int y);
	void handleBead(int x, int y);//�����һ�����Ӹ��ӵĵ���¼�
	void setState(GameState state);

	void generateThreeBeads();
	static bool bEqual(p p1, p p2);

	GameState state;

	std::vector<Point> path;
	int**		map;
	Point*		moveFrom;
	Point*		moveTo;
	ThreeBeads* nextBeads;
	Bead***		array;


	public slots:
	void affterMoveAni();
private:
	int size;
	int score;
	MainWindow *m_mainWindow;

	QTimeLine *timer;
	QGraphicsItemAnimation *animation;
};
