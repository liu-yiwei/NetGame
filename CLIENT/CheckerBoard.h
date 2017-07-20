#pragma once
#include"contants.h"
#include "bead.h"

class QColor;
#include<QGraphicsScene>


//维护一个棋盘，完整包含一个棋盘的所有东西，所有妻子都在这里，没有操作
class CheckerBoard:public QGraphicsScene
{
public:
	explicit CheckerBoard(int gameSize, QObject* parent);
	~CheckerBoard();

	void addBead(int x, int y, BeadColor color) const;

	Bead*** array;//TODO：出错记得看这里有问题没

private:

	int size;
};
