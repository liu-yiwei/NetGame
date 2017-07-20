#include "bead.h"
#include "contants.h"

Bead::Bead()
	: direction(BeadDirection::nothing),
	  color(BeadColor::no)
{
	
	//set false 对应 nothing 和 no
	this->setVisible(false);//初始化棋子实际上看不见，其实刚开始就每个地方都有妻子了，不过他吗不显示而已
}

QRectF
Bead::boundingRect() const
{
	return QRectF(-TILE_SIZE, -TILE_SIZE,
	              TILE_SIZE * 2, TILE_SIZE * 2);
}

// 绘制 填充color
void
Bead::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->fillPath(shape(), QColor(Qt::red));
	painter->restore();
}

// 3/4大小的原型 
QPainterPath
Bead::shape() const
{
	QPainterPath p;
	p.addEllipse(QPointF(0, 0), TILE_SIZE / 8 * 3, TILE_SIZE / 8 * 3);
	return p;
}

BeadColor Bead::getColor() const
{
	return color;
}

BeadDirection Bead::getDirection() const
{
	return direction;
}

void Bead::set_color(BeadColor color)
{
	this->color = color;
}

void Bead::set_direction(BeadDirection direction)
{
	this->direction = direction;
}
