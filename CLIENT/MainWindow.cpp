#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//todo:������������


#include "mainwindow.h"
#include"GameController.h"
#include "contants.h"
#include"GameView.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	centralWidget(new QWidget(this)),
	game(new GameController(this)),
	view(new GameView(game, centralWidget)),
	time(centralWidget)
{
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	setCentralWidget(centralWidget);
	setFixedSize(600, 600);
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
	QMenu* help = menuBar()->addMenu(QObject::trUtf8("&����"));
	help->addAction(aboutAction);
}

void
MainWindow::createActions()
{
	aboutAction = new QAction(QString::fromUtf8("&about"), this);
	aboutAction->setStatusTip("��ʾӦ����Ϣ");
	connect(aboutAction, &QAction::triggered, this, &MainWindow::close);
}
