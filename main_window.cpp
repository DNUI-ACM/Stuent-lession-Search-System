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

void MainWindow::to_input_lesson(QString log)
{
//accout(index_of_student12, password_of_student50)<br>
//school(学校代码10, 学校名称10)<br>
//teacher(教师号10， 教师名10)<br>
//information_of_student(学生号12, 学生姓名10, 班级号6, 性别1,)<br>
//department(系号2, 系名称10, 学校代码10)<br>
//major(专业号10, 专业名10, 系号)<br>

//class(班级号4, 班级名, 专业号)<br>
//classroom(教室号，教室名）<br>
//lession(课程号，课程名)<br>

//apply_lession（课程号10，班号10，教师号10, 上课时间, 教室号）<br>//这里上课时间只需要记 第几节  针对必修 1012 1034 1056 1078 10910

//day(星期几int,    课程, 上课时间10); //select from day where day=1;//查星期1的课
//time( 上课时间10, 课程号, 星期几); //select form time where time=12;//查12节, 12 34 56 78 910


    //逻辑:
    //1. 时间段——>查到所有课程——>据学号查到是17003班的 <-305
    // select index_of_class from
    stu_mysql->cha() = new QSqlQuery;
    //QString log="17180600305";

    QString str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='1012' ) )").arg(log);
	stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _0_0 = stu_mysql->cha()->value(0).toString();
    qWarning() << _0_0 << endl;

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='2012' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _0_1 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='3012' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _0_2 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='4012' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _0_3 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='5012' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _0_4 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='1034' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _1_0 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='2034' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _1_1 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='3034' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _1_2  = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='4034' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _1_3 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='5034' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _1_4 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='1056' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _2_0 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='2056' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _2_1 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='3056' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _2_2 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='4056' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _2_3 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='5056' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _2_4 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='1078' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _3_0 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='2078' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _3_1 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='3078' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _3_2 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='4078' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _3_3 = stu_mysql->cha()->value(0).toString();

    str = QString("select name_of_lession from lession where index_of_lession in (select index_of_lession from apply_lession where (index_of_class in (select index_of_class from information_of_student where index_of_student='%1') AND time_of_lession='5078' ) )").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString _3_4 = stu_mysql->cha()->value(0).toString();



    //qWarning() << ans << endl;
    //qWarning() << stu_mysql->cha()->lastError() << endl;

    str = QString("select name_of_student from information_of_student where index_of_student='%1' ").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString name = stu_mysql->cha()->value(0).toString();

    str = QString("select index_of_class from information_of_student where index_of_student='%1' ").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString classs = stu_mysql->cha()->value(0).toString();


    str = QString("select sex from information_of_student where index_of_student='%1' ").arg(log);
    stu_mysql->cha()->exec(str);
    stu_mysql->cha()->next();
    QString sex = stu_mysql->cha()->value(0).toString();

    inpu->infor->setItem(0, 0, new QTableWidgetItem(log));
    inpu->infor->setItem(0, 1, new QTableWidgetItem(name));
    inpu->infor->setItem(0, 2, new QTableWidgetItem(classs));
    inpu->infor->setItem(0, 3, new QTableWidgetItem(sex));



    //inpu->input_lesson();
    inpu->lession->setItem(0, 0, new QTableWidgetItem(_0_0));
    inpu->lession->setItem(0, 1, new QTableWidgetItem(_0_1));
    inpu->lession->setItem(0, 2, new QTableWidgetItem(_0_2));
    inpu->lession->setItem(0, 3, new QTableWidgetItem(_0_3));
    inpu->lession->setItem(0, 4, new QTableWidgetItem(_0_4));


    inpu->lession->setItem(1, 0, new QTableWidgetItem(_1_0));
    inpu->lession->setItem(1, 1, new QTableWidgetItem(_1_1));
    inpu->lession->setItem(1, 2, new QTableWidgetItem(_1_2));
    inpu->lession->setItem(1, 3, new QTableWidgetItem(_1_3));
    inpu->lession->setItem(1, 4, new QTableWidgetItem(_1_4));

    inpu->lession->setItem(2, 0, new QTableWidgetItem(_2_0));
    inpu->lession->setItem(2, 1, new QTableWidgetItem(_2_1));
    inpu->lession->setItem(2, 2, new QTableWidgetItem(_2_2));
    inpu->lession->setItem(2, 3, new QTableWidgetItem(_2_3));
    inpu->lession->setItem(2, 4, new QTableWidgetItem(_2_4));

    inpu->lession->setItem(3, 0, new QTableWidgetItem(_3_0));
    inpu->lession->setItem(3, 1, new QTableWidgetItem(_3_1));
    inpu->lession->setItem(3, 2, new QTableWidgetItem(_3_2));
    inpu->lession->setItem(3, 3, new QTableWidgetItem(_3_3));
    inpu->lession->setItem(3, 4, new QTableWidgetItem(_3_4));

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







