#include "gameview.h"
#include "Bead.h"

GameView::GameView(QGraphicsScene *scene, QWidget *parent)
	:QGraphicsView(scene, parent)
{

}

void
GameView::mousePressEvent(QMouseEvent *e) {
	this->scene()->addLine(e->x(), e->y(), e->x(), e->y());
	std::cout << e->x() << "\n";
	this->scene()->addItem(new Bead(e->x(), e->y()));
}
