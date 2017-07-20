#pragma once
#include"contants.h"
#include "bead.h"

class QColor;


//维护一个棋盘，完整包含一个棋盘的所有东西，所有妻子都在这里，没有操作
class CheckerBoard
{
public:
	explicit CheckerBoard(int gameSize);
	~CheckerBoard();

	void addBead(int x, int y, BeadColor color) const;

	Bead** array;

private:

	int size;
};
