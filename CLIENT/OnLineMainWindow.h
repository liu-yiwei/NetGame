/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef A_H
#define A_H

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

QT_BEGIN_NAMESPACE

class Ui_MainWindow: public QMainWindow
{
public:
	QAction *action;
	QAction *action_2;
	QWidget *centralwidget;
	QGraphicsView *graphicsView;
	QWidget *formLayoutWidget;
	QFormLayout *formLayout;
	QLabel *Label;
	QLineEdit *LineEdit;
	QLabel *iPLabel;
	QLineEdit *iPLineEdit;
	QLabel *Label_2;
	QLCDNumber *lcdNumber;
	QLabel *label;
	QLCDNumber *lcdNumber_2;
	QLabel *Label_3;
	QLineEdit *LineEdit_2;
	QPushButton *pushButton;
	QTextBrowser *textBrowser;
	QLineEdit *lineEdit;
	QPushButton *pushButton_2;
	QMenuBar *menubar;
	QMenu *menu;
	QMenu *menu_2;
	QStatusBar *statusbar;

public:Ui_MainWindow() {
	setupUi(this);
}

	void setupUi(QMainWindow *MainWindow)
	{
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QStringLiteral("MainWindow"));
		MainWindow->resize(602, 421);
		action = new QAction(MainWindow);
		action->setObjectName(QStringLiteral("action"));
		action_2 = new QAction(MainWindow);
		action_2->setObjectName(QStringLiteral("action_2"));
		centralwidget = new QWidget(MainWindow);
		centralwidget->setObjectName(QStringLiteral("centralwidget"));
		graphicsView = new QGraphicsView(centralwidget);
		graphicsView->setObjectName(QStringLiteral("graphicsView"));
		graphicsView->setGeometry(QRect(10, 10, 360, 360));
		formLayoutWidget = new QWidget(centralwidget);
		formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
		formLayoutWidget->setGeometry(QRect(380, 10, 211, 141));
		formLayout = new QFormLayout(formLayoutWidget);
		formLayout->setObjectName(QStringLiteral("formLayout"));
		formLayout->setContentsMargins(0, 0, 0, 0);
		Label = new QLabel(formLayoutWidget);
		Label->setObjectName(QStringLiteral("Label"));

		formLayout->setWidget(2, QFormLayout::LabelRole, Label);

		LineEdit = new QLineEdit(formLayoutWidget);
		LineEdit->setObjectName(QStringLiteral("LineEdit"));

		formLayout->setWidget(2, QFormLayout::FieldRole, LineEdit);

		iPLabel = new QLabel(formLayoutWidget);
		iPLabel->setObjectName(QStringLiteral("iPLabel"));

		formLayout->setWidget(3, QFormLayout::LabelRole, iPLabel);

		iPLineEdit = new QLineEdit(formLayoutWidget);
		iPLineEdit->setObjectName(QStringLiteral("iPLineEdit"));

		formLayout->setWidget(3, QFormLayout::FieldRole, iPLineEdit);

		Label_2 = new QLabel(formLayoutWidget);
		Label_2->setObjectName(QStringLiteral("Label_2"));

		formLayout->setWidget(4, QFormLayout::LabelRole, Label_2);

		lcdNumber = new QLCDNumber(formLayoutWidget);
		lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

		formLayout->setWidget(1, QFormLayout::FieldRole, lcdNumber);

		label = new QLabel(formLayoutWidget);
		label->setObjectName(QStringLiteral("label"));

		formLayout->setWidget(1, QFormLayout::LabelRole, label);

		lcdNumber_2 = new QLCDNumber(formLayoutWidget);
		lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

		formLayout->setWidget(4, QFormLayout::FieldRole, lcdNumber_2);

		Label_3 = new QLabel(formLayoutWidget);
		Label_3->setObjectName(QStringLiteral("Label_3"));

		formLayout->setWidget(0, QFormLayout::LabelRole, Label_3);

		LineEdit_2 = new QLineEdit(formLayoutWidget);
		LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));

		formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit_2);

		pushButton = new QPushButton(centralwidget);
		pushButton->setObjectName(QStringLiteral("pushButton"));
		pushButton->setGeometry(QRect(380, 340, 101, 23));
		textBrowser = new QTextBrowser(centralwidget);
		textBrowser->setObjectName(QStringLiteral("textBrowser"));
		textBrowser->setGeometry(QRect(380, 160, 211, 141));
		lineEdit = new QLineEdit(centralwidget);
		lineEdit->setObjectName(QStringLiteral("lineEdit"));
		lineEdit->setGeometry(QRect(380, 310, 211, 21));
		pushButton_2 = new QPushButton(centralwidget);
		pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
		pushButton_2->setGeometry(QRect(490, 340, 101, 23));
		MainWindow->setCentralWidget(centralwidget);
		menubar = new QMenuBar(MainWindow);
		menubar->setObjectName(QStringLiteral("menubar"));
		menubar->setGeometry(QRect(0, 0, 602, 23));
		menu = new QMenu(menubar);
		menu->setObjectName(QStringLiteral("menu"));
		menu_2 = new QMenu(menubar);
		menu_2->setObjectName(QStringLiteral("menu_2"));
		MainWindow->setMenuBar(menubar);
		statusbar = new QStatusBar(MainWindow);
		statusbar->setObjectName(QStringLiteral("statusbar"));
		MainWindow->setStatusBar(statusbar);

		menubar->addAction(menu_2->menuAction());
		menubar->addAction(menu->menuAction());
		menu->addAction(action);
		menu->addAction(action_2);

		retranslateUi(MainWindow);

		QMetaObject::connectSlotsByName(MainWindow);
	} // setupUi

	void retranslateUi(QMainWindow *MainWindow)
	{
		MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
		action->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
		action_2->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
		Label->setText(QApplication::translate("MainWindow", "\345\257\271\346\211\213\346\230\265\347\247\260\357\274\232", Q_NULLPTR));
		iPLabel->setText(QApplication::translate("MainWindow", "\345\257\271\346\211\213\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
		Label_2->setText(QApplication::translate("MainWindow", "\345\257\271\346\226\271\345\210\206\346\225\260\357\274\232", Q_NULLPTR));
		label->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\210\206\346\225\260\357\274\232", Q_NULLPTR));
		Label_3->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\346\230\265\347\247\260\357\274\232", Q_NULLPTR));
		pushButton->setText(QApplication::translate("MainWindow", "\346\212\225\351\231\215", Q_NULLPTR));
		pushButton_2->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
		menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
		menu_2->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // A_H
