//#!/usr/bin/env bash
//# **********************************************************
//# Author       : Joe_Yang
//# Last modified: 2018-10-06 14:56
//# Email        : 1514784049@qq.com || 1514784049yz@gmail.com
//# Weblog       : https://blog.csdn.net/pursue_my_life/
//# Filename     : mysql.cpp
//# Description  :
//# **********************************************************
#include "mysql.h"
#include <QCoreApplication>

QSqlError mysql::initsql()
{
    qWarning() << QSqlDatabase::drivers();
    qWarning() << QCoreApplication::libraryPaths();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    //db.setPort(3306);  //设置端口
    //db.setHostName("localhost");
    db.setUserName("yang_zhao");
    db.setPassword("123");
    db.setDatabaseName("student_lesson");
    if(db.open())
    {
        qWarning()<< "database connected successfully!!!";
        create_table();
        return db.lastError();
    }
    else
    {
        qWarning()<<"Database connected failed!";
        qWarning()<< db.lastError();
        return db.lastError();
    }
}

void mysql::create_table()
{
    query = new QSqlQuery;
    //// 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
// 使数据库支持中文
    //query->exec("SET NAMES 'Latin1'");
// 创建 course 表
//    query->exec("create table accout (index_of_student varchar(12), " "password_of_student varchar(20)");
    //query->exec("insert into course values(0, '数学', '刘老师')");
    //query->exec("insert into course values(1, '英语', '张老师')");
    //query->exec("insert into course values(2, '计算机', '李老师')");
}

bool mysql::insert_stu()
{
    //query new QSqlQuery;
    return true;
}

int mysql::verify_user(QString log, QString pass)
{
    query = new QSqlQuery;
    QString str=QString("select password_of_student from accout where index_of_student= '%1'").arg(log);
    bool success = query->exec(str);
    //bool success = query->exec("select password_of_student from accout where index_of_student= '17180600305'");
    if(!success)
    {
        qWarning() << "查询user失败" << endl;
    }

    //	qWarning()<< "str " << str << endl;
    //qWarning()<< "pass " << pass.toLatin1() << endl;
    // qWarning()<< "log " << log<< endl;

    //query->seek(-1);
    if( false == query->next() )
    {
        return 0;
    }

    QString name = query->value(0).toString();
    if( name == pass )
        return 1;
    query->next();

    while(query->next())
    {
        QString name = query->value(0).toString();
        if( name == pass )
            return 1;
    }
    return -1;

//第一次调用next()函数就可以把这个QSqlQuery定位到结果集中的第一条记录。随后的next调用都会把记录指针后移一条记录，直至到达结尾时next才返回false。如果结果集为空（或查询失败），那么next第一次调用将返回false。value()函数把字段值做为QVariant返回，字段是按照SELECT语句中给定的顺序从编号0开始的（千万不要弄错顺序）。
}

bool mysql::forgot_password()//建表 索引 触发器
{
    return true;

}

bool mysql::delete_stu()
{

    return true;
}

bool mysql::update_stu()
{

    return true;
}













