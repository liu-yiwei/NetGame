#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include<QGraphicsScene>
#include"contants.h"
#include "AStar.h"


class QGraphicsScene;

//������Ϸ��״̬��
//û�����ӱ�ѡ�У�һ�����ӱ�ѡ�У������˶���
enum GameState
{
	noChosed, oneChosed, oneMove
};

//ά��һ�����̣���������һ�����̵����ж���
//����ฺ��ִ�о���Ĳ���
class GameController :public QGraphicsScene , public QObject
{
	Q_OBJECT
public:
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();

	void addBead(int x, int y, BeadColor color) const;
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);

	void deleteBead(int x, int y);
	void handleBead(int x, int y) const;//�����һ�����Ӹ��ӵĵ���¼�
	void setState(GameState state);

	GameState state;
	std::vector<Point> * path;
	int** map;

	QTimer timer;

	//�������Ӷ�������
	Bead*** array;//TODO������ǵÿ�����������û

private:
	int size;
};