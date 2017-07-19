///////////////////////////////////////////
//Æå×ÓÀà
//////////////////////////////////////////

#ifndef BEAD_H
#define BEAD_H

#include <QGraphicsItem>
#include<QPainter>

class Bead
	:public QGraphicsItem
{
public:
	Bead(int x, int y);

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	QPainterPath shape() const override;

private:
	Qt::GlobalColor color;
};

#endif
