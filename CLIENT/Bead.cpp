#include "bead.h"
#include "contants.h"

Bead::Bead()
	: state(BeadState::nothing),
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
	painter->setBrush(QColor( 155));
	painter->fillPath(shape(), QColor(strColor[this->color]));
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
}


//状态改变，在同类setter里面这个比较重要
void Bead::setState(BeadState direction)
{
	this->state = direction;
}
