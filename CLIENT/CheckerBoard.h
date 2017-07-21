#pragma once
#include"contants.h"
#include "bead.h"

class QColor;
#include<QGraphicsScene>


//维护一个棋盘，完整包含一个棋盘的所有东西
//这个类负责执行具体的操作
class CheckerBoard:public QGraphicsScene
{
public:
	CheckerBoard(int gameSize, QObject* parent);
	~CheckerBoard();

	void addBead(int x, int y, BeadColor color) const;
	void chooseBead(int x, int y);
	void noChooseBead(int x, int y);
	void moveBeadTo(int sx, int sy, int dx, int dy);

	void deleteBead(int x, int y);


	//所有棋子都在这里
	Bead*** array;//TODO：出错记得看这里有问题没

private:
	int size;
};
