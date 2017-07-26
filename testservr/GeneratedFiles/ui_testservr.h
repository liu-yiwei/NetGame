/********************************************************************************
** Form generated from reading UI file 'testservr.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSERVR_H
#define UI_TESTSERVR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testservrClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testservrClass)
    {
        if (testservrClass->objectName().isEmpty())
            testservrClass->setObjectName(QStringLiteral("testservrClass"));
        testservrClass->resize(177, 145);
        centralWidget = new QWidget(testservrClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 10, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 50, 111, 23));
        testservrClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testservrClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 177, 23));
        testservrClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testservrClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testservrClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testservrClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testservrClass->setStatusBar(statusBar);

        retranslateUi(testservrClass);

        QMetaObject::connectSlotsByName(testservrClass);
    } // setupUi

    void retranslateUi(QMainWindow *testservrClass)
    {
        testservrClass->setWindowTitle(QApplication::translate("testservrClass", "testservr", Q_NULLPTR));
        pushButton->setText(QApplication::translate("testservrClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testservrClass: public Ui_testservrClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSERVR_H
