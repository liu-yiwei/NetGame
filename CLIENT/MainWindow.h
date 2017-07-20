#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenuBar>
#include "GameController.h"


class GameView;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

private slots:

private:
	void createActions();
	void createMenus();

	QWidget* centralWidget;
	GameController* game;
	GameView* view;

	
	QAction* aboutAction;
};

#endif // MAINWINDOW_H
