#pragma once
#include"contants.h"
#include "bead.h"

class QColor;
#include<QGraphicsScene>


//ά��һ�����̣���������һ�����̵����ж������������Ӷ������û�в���
class CheckerBoard:public QGraphicsScene
{
public:
	explicit CheckerBoard(int gameSize, QObject* parent);
	~CheckerBoard();

	void addBead(int x, int y, BeadColor color) const;

	Bead*** array;//TODO������ǵÿ�����������û

private:

	int size;
};
