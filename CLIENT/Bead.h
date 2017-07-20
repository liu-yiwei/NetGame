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
	no,//û�����ӣ�ʵ���Ϻ������nothing�غ�
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
	//��������������Ŀ��ʼ����ʱ�����
	Bead();

	//��д��������ĺ���
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;
	QPainterPath shape() const override;

	//getter and setter
	
	//�й�������Ϊ�ĺ���

	BeadColor getColor() const;
	BeadDirection getDirection() const;
	void set_color(BeadColor color);
	void set_direction(BeadDirection direction);
private:

	BeadColor color;
	BeadDirection direction;
};

#endif
