#pragma once
#include"contants.h"
#include "bead.h"

class QColor;
#include<QGraphicsScene>


//ά��һ�����̣���������һ�����̵����ж������������Ӷ������û�в���
class CheckerBoard:public QGraphicsScene
{
public:
	CheckerBoard(int gameSize, QObject* parent);
	~CheckerBoard();

	void addBead(int x, int y, BeadColor color) const;
	void moveBeadTo(int sx, int sy, int dx, int dy);
	void chooseBead(int x, int y);

	Bead*** array;//TODO������ǵÿ�����������û

private:

	int size;
};
