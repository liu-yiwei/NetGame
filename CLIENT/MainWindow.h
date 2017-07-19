#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenuBar>


class GameScene;
class GameView;

class GameController;

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
	void initScene();
	void initSceneBG();

	QWidget* centralWidget;
	GameScene* scene;
	GameView* view;

	GameController* game;
	QAction* aboutAction;


	void mousePressEvent(QMouseEvent* e);
};

#endif // MAINWINDOW_H
