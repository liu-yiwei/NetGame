#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include<QGraphicsItem>
#include<QMessageBox>
#include<QGraphicsView>
#include<QMouseEvent>
#include<iostream>


class GameView :public QGraphicsView
{
public:
	GameView(QGraphicsScene *scene, QWidget *parent);

protected:
	void mousePressEvent(QMouseEvent *e);
};

#endif // GAMEVIEW_H
#pragma once
