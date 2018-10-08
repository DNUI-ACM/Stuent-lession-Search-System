#include "main_window.h"
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    welcome     =  new origin_view();
    login_kuang =  new login_view();
    stu_mysql   =  new mysql();
	inpu        =  new input();

    stu_mysql->initsql();
    welcome->show();

    connect(welcome->log, SIGNAL(released()), this, SLOT(to_login()) );
    connect(welcome->aut, SIGNAL(released()), this, SLOT(to_author()));
    connect(welcome->qui, SIGNAL(released()), this, SLOT(to_quit()));

    connect(login_kuang->loging, SIGNAL(released()), this, SLOT(to_verify()));

    connect(login_kuang->admin, SIGNAL(returnPressed()), this, SLOT(to_verify() ));

    connect(inpu->prev, SIGNAL(released()), this, SLOT(to_input_lesson() ));
}

void MainWindow::to_input_lesson()
{
	inpu->input_lesson();
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

   //qWarning()<< "zhanghao " << log.toLatin1() << endl;
   //qWarning()<< "mima " << pwd.toLatin1() << endl;
   //qWarning()<< "mima after" << md5.toLatin1() << endl;
    if(stu_mysql->verify_user(log, md5) == 1)
    {
        QMessageBox::information(welcome,tr("congruations!"), tr("Verify successfully!"));
		login_kuang->setVisible(false);
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
}







