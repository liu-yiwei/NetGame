#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//todo:中文乱码问题
#include "ui_LoginDialog.h"

void
Ui_Dialog:: offlineGame(){
	accept();
	this->LineEdit->clear();
	this->LineEdit_2->clear();
	this->LineEdit_3->clear();
	this->LineEdit_4->clear();
}

void
Ui_Dialog::onlineGame() {
	this->reject();
}