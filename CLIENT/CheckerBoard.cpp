#include "CheckerBoard.h"
#include<QColor>
#include<qdebug.h>
#include <QtCore>

CheckerBoard::CheckerBoard(int gameSize, QObject* parent)
	: QGraphicsScene(parent),
	  size(gameSize)
{
	setSceneRect(0, 0, gameSize * 40, gameSize * 40);
	//����ָ�붯̬����һ����ά����//
	array = new Bead**[size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = new Bead*[size];
		for (int j = 0; j < size; j++)
		{
			array[i][j] = new Bead();//who care
			this->addItem(array[i][j]);
			array[i][j]->setPos(i * 40 + 20, j * 40 + 20);
		}
	}
}

CheckerBoard::~CheckerBoard()
{
	delete array;
}

	