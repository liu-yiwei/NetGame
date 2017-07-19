#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//todo:中文乱码问题


#include "mainwindow.h"
#include"GameController.h"
#include "contants.h"
#include "GameScene.h"
#include"GameView.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	centralWidget(new QWidget(this)),
	scene(new GameScene(centralWidget)),
	view (new GameView(scene, centralWidget))
{
	setCentralWidget(centralWidget);
	setFixedSize(600, 600);

	createActions();
	createMenus();
	initScene();
	initSceneBG();
}

MainWindow::~MainWindow()
{
	delete this->game;
}


void
MainWindow::createMenus()
{
	QMenu* help = menuBar()->addMenu(QObject::trUtf8("&帮助"));
	help->addAction(aboutAction);
}

void
MainWindow::createActions()
{
	aboutAction = new QAction(QString::fromUtf8("&about"), this);
	aboutAction->setStatusTip("显示应用信息");
	connect(aboutAction, &QAction::triggered, this, &MainWindow::close);
}

void
MainWindow::initScene()
{
	scene->setSceneRect(0, 0, TILE_SIZE * 9, TILE_SIZE * 9);
}

void
MainWindow::initSceneBG()
{
	QPixmap bg(TILE_SIZE, TILE_SIZE);
	QPainter p(&bg);
	p.setBrush(QBrush(Qt::white));
	p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

	view->setBackgroundBrush(QBrush(bg));
}

void
MainWindow::mousePressEvent(QMouseEvent* e)
{
}
