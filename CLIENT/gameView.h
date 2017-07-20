#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QMouseEvent>

#include"GameController.h"
#include "contants.h"

class GameView :public QGraphicsView
{
public:
	explicit GameView(GameController *controller,QWidget* parent);

protected:
	void mousePressEvent(QMouseEvent* e) override;

private:
	void initBG();

	
	GameController* controller;
	
};

#endif // GAMEVIEW_H
#pragma once
