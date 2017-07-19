#include "GameController.h"




GameController::GameController(QGraphicsScene& scene, QObject* parent)
	: QObject(parent),
	  scene(scene), gameSize(0)
{
	timer.start(1000/33);
}

void GameController::gameOver()
{
}

bool GameController::eventFilter(QObject* object, QEvent* event)
{
	return false;
}

GameController::~GameController()
{
}
