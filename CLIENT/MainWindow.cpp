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
	view(new GameView(game,this, centralWidget)),
	view2(new QGraphicsView(game,centralWidget))
{
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	
	
	setCentralWidget(centralWidget);
	setFixedSize(480, 387);

	

	
	initUI();
	createActions();
	createMenus();
}

MainWindow::~MainWindow()
{
	delete this->game;
}


void
MainWindow::initUI() {

	this->score->setGeometry(361, 1, 120, 40);
	score->display(0);
	view2->setGeometry(361, 121, 120, 40);
	QPixmap bg(40, 40);
	QPainter p(&bg);
	p.setBrush(QBrush("#AEEEEE"));
	p.drawRect(0, 0, 40, 40);

	view2->setBackgroundBrush(QBrush(bg));
	view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view2->setSceneRect(320, 120, 120, 40);
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
