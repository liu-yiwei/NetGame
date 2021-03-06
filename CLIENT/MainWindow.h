#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenuBar>
#include "GameController.h"

#include<QLCDNumber>
class GameView;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
	void initUI();
	

protected:
	void createActions();
	
	void createMenus();

	QWidget* centralWidget;
	GameController* game;
	GameView* view;
	QGraphicsView * view2;


	QAction* aboutAction;
public:
	QLCDNumber* score;
};

#endif // MAINWINDOW_H
