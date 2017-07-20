#include "GameController.h"
#include "MainWindow.h"
#include"gameScene.h"
#include<iostream>

GameController::GameController(QObject* parent)
	: QObject(parent),
	  scene(new GameScene(parent)),
	  gameSize(9),
	  checkerboard(new CheckerBoard(gameSize))
{
	scene->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
}

GameController::GameController(int gameSize, QObject* parent)
	: QObject(parent),
	  scene(new GameScene(parent)),
	  gameSize(gameSize),
	checkerboard(new CheckerBoard(gameSize))
{
	scene->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
}

void GameController::gameOver()
{
}

void GameController::generateBeads(int x, int y, colors color)
{
	checkerboard->addBead(x, y, color);
}


GameController::~GameController()
{
}
