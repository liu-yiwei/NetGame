#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include<QGraphicsView>
#include<QMouseEvent>
#include <QMainWindow>
#include"GameController.h"

class GameView :public QGraphicsView
{
public:
	GameView(GameController* controller,QMainWindow* mainWindow, QWidget* parent);


protected:
	void mousePressEvent(QMouseEvent* e) override;

private:
	void initBG();


	GameController* controller;

};

#endif // GAMEVIEW_H
#pragma once
