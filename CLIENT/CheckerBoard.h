#pragma once
#include"contants.h"
#include "bead.h"

class QColor;
#include<QGraphicsScene>


//ά��һ�����̣���������һ�����̵����ж���
//����ฺ��ִ�о���Ĳ���
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


	//�������Ӷ�������
	Bead*** array;//TODO������ǵÿ�����������û

private:
	int size;
};
