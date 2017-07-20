///////////////////////////////////////////
//������
//////////////////////////////////////////

#ifndef BEAD_H
#define BEAD_H

#include <QGraphicsItem>
#include<QPainter>

////////////////////////////////////////
//ö������
enum BeadColor
{
	red,
	green,
	black,
	blue,
	yellow
};

enum BeadDirection//���Ӹ�״̬�ֽ�
{
	nothing,//ɶ����Ҳû�е�ʱ��
	choosed,//���ӱ�ѡ�е�ʱ��
	needToMove,//���ӱ�ѡ�в����Ѿ�ȷ��Ŀ�ĵص�ʱ��
	still,//���Ӿ�ֹ��û���κβ�����ʱ��
};

class Bead
	:public QGraphicsItem
{
public:

	


	Bead(int x, int y, QColor color);


	//��д��������ĺ���
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

	QPainterPath shape() const override;

private:

	BeadColor color;
	BeadDirection direction;
};

#endif
