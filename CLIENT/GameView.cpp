#include "gameview.h"
#include "Bead.h"
#include "contants.h"

GameView::GameView(GameController* controller, QWidget* parent)
	: controller(controller),
	  QGraphicsView(controller->scene, parent)
{
	initBG();
	setRenderHint(QPainter::Antialiasing);
}

void
GameView::mousePressEvent(QMouseEvent* e)
{
	this->controller->generateBeads(e->x() / 40, e->y() / 40, colors::blue);
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
