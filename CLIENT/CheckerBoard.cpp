#include "CheckerBoard.h"
#include<QColor>
#include<qdebug.h>
#include <QtCore>

CheckerBoard::CheckerBoard(int gameSize)
	: size(gameSize)
{
	//����ָ�붯̬����һ����ά����
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