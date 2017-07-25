#include "DB.h"
#include <qsql>
DB::DB(QObject * parent)
	:QSqlDatabase("QMYSQL")
{
	this->setHostName("localhost");
	this->setPort(3306);
	this->setDatabaseName("netgame");
	this->setUserName("root");
	this->setPassword("liuyiwei");

	if (this->open())
	{

	}

}