#pragma once

///////////////////////////////////////////
//棋子类,和小旗子有关的一切行为都在这里
//////////////////////////////////////////

#include <QGraphicsObject>
#include<QPainter>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

const QString strColor[9] = { "#FFFFFF","#FF3030","#4EEE94","#FF7F00","#4682B4","#FFFF00","#8B6969","#A0522D","#9400D3" };

////////////////////////////////////////
enum BeadColor
{
	no,//没有棋子，实际上和下面的nothing重合
	red,
	green,
	orange,
	blue,
	yellow,
	RosyBrown,
	Sienna,
	DarkViolet
};
enum BeadState//棋子各状态分解
{
	nothing,//啥东西也没有的时候
	choosed,//棋子被选中的时候
	needToMove,//棋子被选中并且已经确定目的地的时候
	still,//棋子静止，没有任何操作的时候
};

class Bead
	:public QGraphicsObject
{
public:
	//重写的最基本的函数
	Bead();//初始化一个看不见的棋子
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;
	QPainterPath shape() const override;
	QPainterPath shadow() const;


	//有关棋子行为的函数，就是状态的转换，由其他类来调用

	//getter and setter
	BeadColor getColor() const;
	BeadState getState() const;
	void setColor(BeadColor color);
	void setState(BeadState state);
	static BeadColor getColorByInt(int x);

	//棋子选中状态的改变
	void toChoosed();
	void toNoChoosed();

private:
	BeadColor color;
	BeadState state;
};