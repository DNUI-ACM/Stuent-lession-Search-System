#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlError>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
//#include "main_window.h"

class mysql
{
	//Q_OBJECT
	public:
		mysql()=default;
		QSqlError initsql(); //初始化链接数据库
		int verify_user(QString log, QString pass);//will return 0, 1, 2

		void create_table();//建表 索引 触发器
		bool forgot_password();//建表 索引 触发器
		bool delete_stu();	
		bool insert_stu();	
		bool update_stu();	

	private:
		QSqlQuery *query;

//	public slots:
//		bool to_verify();
};

#endif //MYSQL_H

