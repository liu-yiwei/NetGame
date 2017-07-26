

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <QTcpSocket>

#include "MainWindow.h"

class Ui_MainWindow : public MainWindow
{
public:
	QLCDNumber * score2;
	QTextBrowser * chatRecard;
	QPushButton * but_lose;
	QPushButton* but_send;
	QLineEdit * edit_info;
	QLineEdit* playerInfo;
	Ui_MainWindow();

	void initUI();

private:
	QTcpSocket * tcpsocket;



};