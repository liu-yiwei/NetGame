#include "bead.h"
#include "contants.h"

Bead::Bead()
	: state(BeadState::nothing),
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
	painter->setBrush(QColor( 155));
	painter->fillPath(shape(), QColor(strColor[this->color]));
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

BeadState Bead::getState() const
{
	return state;
}

void Bead::setColor(BeadColor color)
{
	this->color = color;
}


//״̬�ı䣬��ͬ��setter��������Ƚ���Ҫ
void Bead::setState(BeadState direction)
{
	this->state = direction;
}
