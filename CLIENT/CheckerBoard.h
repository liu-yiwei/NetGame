#pragma once
#include"contants.h"
#include "bead.h"

class QColor;


//ά��һ�����̣���������һ�����̵����ж������������Ӷ������û�в���
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
