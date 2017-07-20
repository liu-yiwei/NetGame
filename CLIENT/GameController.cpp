#include "GameController.h"
#include "MainWindow.h"
#include<iostream>
#include"CheckerBoard.h"

GameController::GameController(QObject* parent)
	: QObject(parent),
	  gameSize(9),
	  checkerboard(new CheckerBoard(gameSize,parent))
{

}

GameController::GameController(int gameSize, QObject* parent)
	: QObject(parent),
	  gameSize(gameSize),
	checkerboard(new CheckerBoard(gameSize,parent))
{
	checkerboard->setSceneRect(0, 0, gameSize * 40, gameSize * 40);
}

void GameController::gameOver()
{
}

void GameController::generateBeads(int x, int y, BeadColor color)
{
	checkerboard->addBead(x, y, color);
}

GameController::~GameController()
{
}
