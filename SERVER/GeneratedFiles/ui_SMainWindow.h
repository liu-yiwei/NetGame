/********************************************************************************
** Form generated from reading UI file 'SMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMAINWINDOW_H
#define UI_SMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
	:public QMainWindow
{
public:
    QAction *actionAbout;
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QTableView *tableView;
    QTableView *tableView_2;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLabel *Label_2;
    QLineEdit *LineEdit_2;
    QLabel *Label_3;
    QLineEdit *LineEdit_3;
    QLabel *Label_4;
    QLineEdit *LineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

	Ui_MainWindow()
	{
		setupUi(this);
	}

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setFixedSize(761, 527);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(300, 30, 451, 251));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(10, 300, 741, 171));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 271, 171));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 241, 112));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QStringLiteral("Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        LineEdit = new QLineEdit(formLayoutWidget);
        LineEdit->setObjectName(QStringLiteral("LineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        LineEdit_2 = new QLineEdit(formLayoutWidget);
        LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

        Label_3 = new QLabel(formLayoutWidget);
        Label_3->setObjectName(QStringLiteral("Label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Label_3);

        LineEdit_3 = new QLineEdit(formLayoutWidget);
        LineEdit_3->setObjectName(QStringLiteral("LineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, LineEdit_3);

        Label_4 = new QLabel(formLayoutWidget);
        Label_4->setObjectName(QStringLiteral("Label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Label_4);

        LineEdit_4 = new QLineEdit(formLayoutWidget);
        LineEdit_4->setObjectName(QStringLiteral("LineEdit_4"));
        LineEdit_4->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, LineEdit_4);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 71, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 140, 71, 23));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 140, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        radioButton_2->setFont(font1);
        radioButton_2->setIconSize(QSize(13, 13));
        radioButton_2->setAutoRepeat(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 280, 54, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 10, 112, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(490, 10, 81, 20));
        label_3->setFont(font);
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(580, 10, 81, 21));
        radioButton->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(670, 10, 81, 20));
        comboBox->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 271, 81));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 20, 111, 23));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 50, 111, 23));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 50, 111, 23));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 20, 111, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 761, 23));
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
        menu->addAction(actionAbout);
        menu_2->addAction(action);
        menu_2->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        Label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        LineEdit->setText(QApplication::translate("MainWindow", "8888", Q_NULLPTR));
        Label_2->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        LineEdit_2->setText(QApplication::translate("MainWindow", "localhost", Q_NULLPTR));
        Label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        LineEdit_3->setText(QApplication::translate("MainWindow", "root", Q_NULLPTR));
        Label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        LineEdit_4->setText(QApplication::translate("MainWindow", "liuyiwei", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "\345\210\206\346\225\260\346\216\222\345\220\215", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\205\250\351\203\250", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\246\273\347\272\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\234\250\347\272\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\270\270\346\210\217\344\270\255", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\351\273\221\345\220\215\345\215\225", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMAINWINDOW_H
