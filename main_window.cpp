#include "main_window.h"
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringListModel>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    welcome     =  new origin_view();
    login_kuang =  new login_view();
    stu_mysql   =  new mysql();
    inpu        =  new input();

    stu_mysql->initsql();
    welcome->show();
    //inpu->show();
    connect(welcome->log, SIGNAL(released()), this, SLOT(to_login()) );
    connect(welcome->aut, SIGNAL(released()), this, SLOT(to_author()));
    connect(welcome->qui, SIGNAL(released()), this, SLOT(to_quit()));

    connect(login_kuang->loging, SIGNAL(released()), this, SLOT(to_verify()));

    connect(login_kuang->admin, SIGNAL(returnPressed()), this, SLOT(to_verify() ));

    //connect(inpu->prev, SIGNAL(released()), this, SLOT(to_input_lesson() ));
}

QString&  MainWindow::search(QString& str, QString log, QString time)
{
    stu_mysql->cha() = new QSqlQuery;

//    str = QString(" select lesson_name from  lesson where lesson_id in ( select choose_lesson.lesson_id from choose_lesson, site where choose_lesson.lesson_id = site.lesson_id and  choose_lesson.stu_id  = '%1' and  site.time_of_lesson = '%2')").arg(log, time);
//
//    stu_mysql->cha()->exec(str);
//    stu_mysql->cha()->next();
//    QString tmp = stu_mysql->cha()->value(0).toString();
//	qWarning() << tmp << endl;
//
//	str = QString("select classroom from choose_lesson, site where choose_lesson.lesson_id = site.lesson_id  and  choose_lesson.stu_id  = '%1'  and  site.time_of_lesson = '%2'").arg(log, time);
//
//    stu_mysql->cha()->exec(str);
//    stu_mysql->cha()->next();
//    tmp += ' ' + stu_mysql->cha()->value(0).toString();
//	qWarning() << tmp << endl;

	str = QString("select lesson.lesson_name, site.classroom, teacher.teacher_name from  lesson inner join choose_lesson on choose_lesson.lesson_id = lesson.lesson_id and choose_lesson.stu_ID = '%1' inner join site  on site.lesson_id = choose_lesson.lesson_id and site.time_of_lesson = '%2' inner join apply_lesson on apply_lesson.lesson_ID = lesson.lesson_id inner join teacher on teacher.teacher_ID = apply_lesson.teacher_ID").arg(log, time);

    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();

	QString tmp;
	for(int i = 0; i < 3; ++i)
		tmp += stu_mysql->cha()->value(i).toString() + '\n';

	qWarning() << tmp << endl;
	return str = tmp;
}



void MainWindow::to_input_lesson(QString log)
{
    stu_mysql->cha() = new QSqlQuery;

    QString str = QString("select stu_name from student where stu_ID='%1' ").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString name = stu_mysql->cha()->value(0).toString();

    str = QString("select major_name from major where major_ID=(select major_ID from student where stu_ID='%1' )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString classs = stu_mysql->cha()->value(0).toString();


    str = QString("select sex from student where stu_ID='%1' ").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString sex = stu_mysql->cha()->value(0).toString();

    inpu->infor->setItem(0, 0, new QTableWidgetItem(log));
    inpu->infor->setItem(0, 1, new QTableWidgetItem(name));
    inpu->infor->setItem(0, 2, new QTableWidgetItem(classs));
    inpu->infor->setItem(0, 3, new QTableWidgetItem(sex));

    //inpu->input_lesson();
	inpu->lession->setItem(0, 0, new QTableWidgetItem(search( str, log, "1012" )));
    inpu->lession->setItem(0, 1, new QTableWidgetItem(search( str, log, "2012" )));
    inpu->lession->setItem(0, 2, new QTableWidgetItem(search( str, log, "3012" )));
    inpu->lession->setItem(0, 3, new QTableWidgetItem(search( str, log, "4012" )));
    inpu->lession->setItem(0, 4, new QTableWidgetItem(search( str, log, "5012" )));
                                                                               
    inpu->lession->setItem(1, 0, new QTableWidgetItem(search( str, log, "1034" )));
    inpu->lession->setItem(1, 1, new QTableWidgetItem(search( str, log, "2034" )));
    inpu->lession->setItem(1, 2, new QTableWidgetItem(search( str, log, "3034" )));
    inpu->lession->setItem(1, 3, new QTableWidgetItem(search( str, log, "4034" )));
    inpu->lession->setItem(1, 4, new QTableWidgetItem(search( str, log, "5034" )));
                                                                               
    inpu->lession->setItem(2, 0, new QTableWidgetItem(search( str, log, "1056" )));
    inpu->lession->setItem(2, 1, new QTableWidgetItem(search( str, log, "2056" )));
    inpu->lession->setItem(2, 2, new QTableWidgetItem(search( str, log, "3056" )));
    inpu->lession->setItem(2, 3, new QTableWidgetItem(search( str, log, "4056" )));
    inpu->lession->setItem(2, 4, new QTableWidgetItem(search( str, log, "5056" )));
                                                                               
    inpu->lession->setItem(3, 0, new QTableWidgetItem(search( str, log, "1078" )));
    inpu->lession->setItem(3, 1, new QTableWidgetItem(search( str, log, "2078" )));
    inpu->lession->setItem(3, 2, new QTableWidgetItem(search( str, log, "3078" )));
    inpu->lession->setItem(3, 3, new QTableWidgetItem(search( str, log, "4078" )));
    inpu->lession->setItem(3, 4, new QTableWidgetItem(search( str, log, "5078" )));

    inpu->lession->show();
    inpu->infor->show();
}

void MainWindow::to_verify()
{
    //mysql 会传过来一个 md5密码 再与 比对login_kuang->admin->text来对比
    QString md5;
    QString log = login_kuang->admin->text();
    QString pwd = login_kuang->password->text();
    QByteArray ba, bb;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(pwd);
    md.addData(ba);
    bb = md.result();
    md5.append(bb.toHex());
//现在 md5 是用户输入的密码经过md5转换后的 密码

    if(stu_mysql->verify_user(log, md5) == 1)
    {
        QMessageBox::information(welcome,tr("congruations!"), tr("Verify successfully!"));
        login_kuang->setVisible(false);
        this->to_input_lesson(log);
        inpu->show();
    }
    else if(stu_mysql->verify_user(log, md5) == 0)
    {
        QMessageBox::information(welcome,tr("Warrning"), tr("accout number is wrong!"));
    }
    else if(stu_mysql->verify_user(log, md5) == -1)
    {
        QMessageBox::information(welcome,tr("Warrning"), tr("password is wrong!"));
    }

    //if(log == && pwd == )
}

void MainWindow::to_login()
{
    welcome->log->resize(60,60);
    QMessageBox::information(welcome, tr("Information"), tr("Open"));
    welcome->setVisible(false);
    login_kuang->show();
}

void MainWindow::to_author()
{
    QMessageBox::information(welcome, tr("Power By Joe_yang"), tr("Welcome to clicked www.joeyang.cn"));
}

void MainWindow::to_quit()
{
    QMessageBox::information(welcome, tr("Bye"), tr("Welcome using again"));
    QApplication::quit();
}


MainWindow::~MainWindow()
{
    delete welcome;
    delete login_kuang;
    delete inpu;
    delete stu_mysql;
}







