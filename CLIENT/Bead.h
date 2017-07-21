///////////////////////////////////////////
//������
//////////////////////////////////////////

#ifndef BEAD_H
#define BEAD_H

#include <QGraphicsObject>
#include<QPainter>

const QString strColor[9] = {"#FFFFFF","#FF3030","#4EEE94","#FF7F00","#4682B4","#FFFF00","#8B6969","#A0522D","#9400D3"};

////////////////////////////////////////
//ö������
enum BeadColor
{
	no ,//û�����ӣ�ʵ���Ϻ������nothing�غ�
	red,
	green,
	orange,
	blue,
	yellow,
	RosyBrown,
	Sienna,
	DarkViolet
};
enum BeadState//���Ӹ�״̬�ֽ�
{
	nothing,//ɶ����Ҳû�е�ʱ��
	choosed,//���ӱ�ѡ�е�ʱ��
	needToMove,//���ӱ�ѡ�в����Ѿ�ȷ��Ŀ�ĵص�ʱ��
	still,//���Ӿ�ֹ��û���κβ�����ʱ��
};

class Bead
	:public QGraphicsObject
{
public:
	//��������������Ŀ��ʼ����ʱ�����
	Bead();

	//��д��������ĺ���
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;
	QPainterPath shape() const override;

	//getter and setter

	//�й�������Ϊ�ĺ���������״̬��ת������������������


	//״̬�ı�




	//getter and setter
	BeadColor getColor() const;
	BeadState getState() const;
	void setColor(BeadColor color);
	void setState(BeadState state);
private:

	BeadColor color;
	BeadState state;
};

#endif
