///////////////////////////////////////////
//棋子类
//////////////////////////////////////////

#ifndef BEAD_H
#define BEAD_H

#include <QGraphicsItem>
#include<QPainter>

////////////////////////////////////////
//枚举生命
enum BeadColor
{
	red,
	green,
	black,
	blue,
	yellow
};

enum BeadDirection//棋子各状态分解
{
	nothing,//啥东西也没有的时候
	choosed,//棋子被选中的时候
	needToMove,//棋子被选中并且已经确定目的地的时候
	still,//棋子静止，没有任何操作的时候
};

class Bead
	:public QGraphicsItem
{
public:

	


	Bead(int x, int y, QColor color);


	//重写的最基本的函数
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	QPainterPath shape() const override;

private:

	BeadColor color;
	BeadDirection direction;
};

#endif
