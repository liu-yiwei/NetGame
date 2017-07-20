#include "CheckerBoard.h"
#include<QColor>
#include<qdebug.h>
#include <QtCore>

CheckerBoard::CheckerBoard(int gameSize)
	: size(gameSize)
{
	//利用指针动态分配一个二维数组
	array = new Bead*[size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			array[i][j] = 0;
		}
	}
}

CheckerBoard::~CheckerBoard()
{
}

void 
CheckerBoard::addBead(int x, int y, BeadColor color) const
{
}