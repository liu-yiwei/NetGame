#include "gameview.h"
#include "Bead.h"
#include "contants.h"
#include<GameController.h>

GameView::GameView(GameController* controller, QWidget* parent)
	: controller(controller),
	  QGraphicsView(controller->checkerboard, parent)
{
	initBG();
	setRenderHint(QPainter::Antialiasing);
}


//这里就已经完成了坐标的转换，以后再也不会出现跟限速值有关的东西
void
GameView::mousePressEvent(QMouseEvent* e)
{

	this->controller->handleBead(e->x() / 40, e->y() / 40);
}


void GameView::initBG()
{
	{
		QPixmap bg(TILE_SIZE, TILE_SIZE);
		QPainter p(&bg);
		p.setBrush(QBrush(Qt::white));
		p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

		setBackgroundBrush(QBrush(bg));
	}
}
