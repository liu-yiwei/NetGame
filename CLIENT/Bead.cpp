#include "bead.h"
#include "contants.h"

Bead::Bead(int x, int y)
{
	setPos(x / TILE_SIZE * TILE_SIZE + 20, y / TILE_SIZE * TILE_SIZE + 20);
}

QRectF
Bead::boundingRect() const
{
	return QRectF(-TILE_SIZE, -TILE_SIZE,
	              TILE_SIZE * 2, TILE_SIZE * 2);
}

void
Bead::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->fillPath(shape(), Qt::red);
	painter->restore();
}

QPainterPath
Bead::shape() const
{
	QPainterPath p;
	p.addEllipse(QPointF(0, 0), TILE_SIZE / 8 * 3, TILE_SIZE / 8 * 3);
	return p;
}
