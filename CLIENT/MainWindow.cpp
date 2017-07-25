#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//todo:中文乱码问题


#include "mainwindow.h"
#include"GameController.h"
#include "contants.h"
#include"GameView.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	centralWidget(new QWidget(this)),
	score(new QLCDNumber( centralWidget)),
	game(new GameController(this)),//奇特的架构
	view(new GameView(game,this, centralWidget))
{
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	setCentralWidget(centralWidget);
	setFixedSize(600, 390);
	createActions();
	createMenus();
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
