#include "bead.h"
#include "contants.h"

Bead::Bead()
	: state(BeadState::nothing),
	  color(BeadColor::no)
{

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
	painter->fillPath(shape(), QColor(strColor[this->color]));
	setScale(this->state == BeadState::choosed ? 1.3 : 1);
	this->setVisible(!this->state == BeadState::nothing);
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

BeadState Bead::getState() const
{
	return state;
}

void Bead::setColor(BeadColor color)
{
	this->color = color;
	update();
}


//状态改变，在同类setter里面这个比较重要
void Bead::setState(BeadState direction)
{
	if (direction != nothing)
		this->setVisible(true);
	this->state = direction;
	update();//改变了状态就更新
}
