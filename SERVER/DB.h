#pragma once

#include<QSqlDatabase>
#include <QObject>
class DB:
	public QSqlDatabase
{
public:
	DB(QObject * parent = 0);
	~DB();
protected:
private:
};