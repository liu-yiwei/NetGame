#include "gameview.h"
#include "Bead.h"


GameView::GameView(GameController* controller, QWidget* parent)
	: controller(controller),
	  QGraphicsView(controller->scene, parent)
{
	initBG();
	setRenderHint(QPainter::Antialiasing);
	//fitInView(controller->scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
	
}

void
GameView::mousePressEvent(QMouseEvent* e)
{
	this->scene()->addItem(new Bead(e->x(), e->y()));
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
