#ifndef MYSQL_H
#define MYSQL_H

#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"

class mysql
{
	public:
		mysql();
		void initsql(); //初始化链接数据库
		void createtable();
	private:
		QSqlQuery *query;

};

#endif //MYSQL_H
