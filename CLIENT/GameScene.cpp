#include "gamescene.h"
GameScene::GameScene(QWidget *parent)
	:QGraphicsScene(parent) {

}

void
GameScene::mousePressEvent(QMouseEvent *event) {
	//QMessageBox::warning(this, "warning", "This Position has Already had chess!", QMessageBox::Ok);
}