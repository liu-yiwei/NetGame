/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H
#include <QMessageBox>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>


class Ui_Dialog
	:public QDialog
{
public:
	QPushButton pushButton;
	QGroupBox *groupBox;
	QWidget *formLayoutWidget;
	QFormLayout *formLayout;
	QLabel *Label;
	QLabel *Label_2;
	QLineEdit *LineEdit_2;
	QLineEdit *LineEdit;
	QLabel *Label_3;
	QLineEdit *LineEdit_3;
	QLabel *Label_4;
	QLineEdit *LineEdit_4;
	QPushButton *pushButton_2;
	QTextBrowser *textBrowser;
	Ui_Dialog()
		:pushButton(this)
	{
		setupUi(this);
		setupActions(this);
	}

	void setupUi(QDialog *Dialog)
	{
		if (Dialog->objectName().isEmpty())
			Dialog->setObjectName(QStringLiteral("Dialog"));
		Dialog->resize(170, 321);
		
		pushButton.setObjectName(QStringLiteral("pushButton"));
		pushButton.setGeometry(QRect(10, 10, 151, 23));
		groupBox = new QGroupBox(Dialog);
		groupBox->setObjectName(QStringLiteral("groupBox"));
		groupBox->setGeometry(QRect(0, 40, 171, 161));
		formLayoutWidget = new QWidget(groupBox);
		formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
		formLayoutWidget->setGeometry(QRect(10, 20, 151, 100));
		formLayout = new QFormLayout(formLayoutWidget);
		formLayout->setObjectName(QStringLiteral("formLayout"));
		formLayout->setContentsMargins(0, 0, 0, 0);
		Label = new QLabel(formLayoutWidget);
		Label->setObjectName(QStringLiteral("Label"));

		formLayout->setWidget(0, QFormLayout::LabelRole, Label);

		Label_2 = new QLabel(formLayoutWidget);
		Label_2->setObjectName(QStringLiteral("Label_2"));

		formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

		LineEdit_2 = new QLineEdit(formLayoutWidget);
		LineEdit_2->setObjectName(QStringLiteral("LineEdit_2"));

		formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit_2);

		LineEdit = new QLineEdit(formLayoutWidget);
		LineEdit->setObjectName(QStringLiteral("LineEdit"));

		formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

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

		formLayout->setWidget(3, QFormLayout::FieldRole, LineEdit_4);

		pushButton_2 = new QPushButton(groupBox);
		pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
		pushButton_2->setGeometry(QRect(10, 130, 151, 23));
		textBrowser = new QTextBrowser(Dialog);
		textBrowser->setObjectName(QStringLiteral("textBrowser"));
		textBrowser->setGeometry(QRect(0, 210, 171, 111));

		retranslateUi(Dialog);

		QMetaObject::connectSlotsByName(Dialog);
	} // setupUi

	void retranslateUi(QDialog *Dialog)
	{
		Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
		pushButton.setText(QApplication::translate("Dialog", "\345\215\225\346\234\272\346\270\270\346\210\217", Q_NULLPTR));
		groupBox->setTitle(QApplication::translate("Dialog", "\350\201\224\346\234\272", Q_NULLPTR));
		Label->setText(QApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\357\274\232", Q_NULLPTR));
		Label_2->setText(QApplication::translate("Dialog", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
		LineEdit_2->setText(QApplication::translate("Dialog", "666", Q_NULLPTR));
		LineEdit->setText(QApplication::translate("Dialog", "127.0.0.1", Q_NULLPTR));
		Label_3->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
		Label_4->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
		pushButton_2->setText(QApplication::translate("Dialog", "\350\201\224\346\234\272\346\270\270\346\210\217", Q_NULLPTR));
		textBrowser->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
			"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
			"p, li { white-space: pre-wrap; }\n"
			"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
			"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#55aa7f;\">\344\272\224\345\275\251\350\277\236\347\217\240\345\242\236\345\274\272\347\211\210</span></p>\n"
			"<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#55aa7f;\">\345\256\236\347\216\260\344\272\206\347\273\217\345\205\270\347\232\204\344\272\224\345\275\251\350\277\236\347\217\240\346\270\270\346\210\217\345\271\266\345\212\240\345\205\245\344\272\206\350\201\224\346\234\272\345\257\271\346\210\230</"
			"span></p>\n"
			"<p align=\"center\" dir='rtl' style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#55aa7f;\"><br /></p></body></html>", Q_NULLPTR));
	} // retranslateUi

public:
	void setupActions(QDialog *Dialog) {
		connect(&pushButton, &QPushButton::clicked, this, &Ui_Dialog::offlineGame);
		connect(pushButton_2, &QPushButton::clicked, this, &Ui_Dialog::onlineGame);
	}

public slots:
	void offlineGame();
	void onlineGame();

};

#endif // UI_LOGINDIALOG_H