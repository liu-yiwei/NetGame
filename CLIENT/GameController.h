#pragma once

#include<QObject>
#include<QTimer>
#include "bead.h"
#include"CheckerBoard.h"
#include"contants.h"
class QGraphicsScene;

//������Ϸ��״̬��
//û�����ӱ�ѡ�У�һ�����ӱ�ѡ�У������˶���
enum BoardState
{
	noChosed,oneChosed,oneMove
};

//����������Ϸ���������view��scene��beads��
class GameController
	:public QObject
{
	Q_OBJECT
public:
	GameController(QObject* parent);
	GameController(int gameSize, QObject* parent);
	~GameController();
	void addBead(int x, int y, BeadColor color) const;
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);

	void handleBead(int x, int y) const;//�����һ�����Ӹ��ӵĵ���¼�
	void setState(BoardState state);
	QTimer timer;
	int gameSize;//���̱߳�
	COOR* path;

	CheckerBoard* checkerboard;
	BoardState state;

};
