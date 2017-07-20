#include "GameController.h"
#include "MainWindow.h"
#include"gameScene.h"
#include<iostream>
GameController::GameController(QObject* parent)
	: QObject(parent),
	  scene(new GameScene(parent)),
	  gameSize(9)
{
	scene->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
}

GameController::GameController(int gameSize, QObject* parent)
	: QObject(parent),
	  scene(new GameScene(parent)),
	  gameSize(gameSize)
{
	scene->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
}

void GameController::gameOver()
{
}



GameController::~GameController()
{
}
