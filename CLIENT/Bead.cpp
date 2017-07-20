#include "bead.h"
#include "contants.h"

Bead::Bead()
	: direction(BeadDirection::nothing),
	  color(BeadColor::no)
{
	
	//set false ��Ӧ nothing �� no
	this->setVisible(false);//��ʼ������ʵ���Ͽ���������ʵ�տ�ʼ��ÿ���ط����������ˣ�����������ʾ����
}

QRectF
Bead::boundingRect() const
{
	return QRectF(-TILE_SIZE, -TILE_SIZE,
	              TILE_SIZE * 2, TILE_SIZE * 2);
}

// ���� ���color
void
Bead::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->fillPath(shape(), QColor(Qt::red));
	painter->restore();
}

// 3/4��С��ԭ�� 
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
