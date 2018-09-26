//#!/usr/bin/env bash
//# **********************************************************
//# Author       : Joe_Yang
//# Last modified: 2018-09-27 00:00
//# Email        : 1514784049@qq.com || 1514784049yz@gmail.com
//# Weblog       : https://blog.csdn.net/pursue_my_life/
//# Filename     : origin.cpp
//# Description  :
//# **********************************************************
//#!/usr/bin/env bash
//# **********************************************************
//# Author       : Joe_Yang
//# Last modified: 2018-09-26 23:58
//# Email        : 1514784049@qq.com || 1514784049yz@gmail.com
//# Weblog       : https://blog.csdn.net/pursue_my_life/
//# Filename     : origin.cpp
//# Description  :
//# **********************************************************
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>

class origin_view: public QMainWindow
{
public slots:
    void    login();
    void    author();
    void    quit();

private:
    QPushButton *aut ;
    QPushButton *qui ;
    QPushButton *log ;
public:
    explicit origin_view(QWidget* parent = 0);
    ~origin_view();
	void reflection();
};

void origin_view::login()
{
    log->resize(60,60);
    QMessageBox::information(this, tr("Information"), tr("Open"));
}

void origin_view::author()
{
    QMessageBox::information(this, tr("Power by Joe_yang"), tr("Welcome to clicked www.joeyang.cn"));
}

void origin_view::quit()
{
    QMessageBox::information(this, tr("Bye"), tr("Welcome using again"));
    QApplication::quit();
}

void origin_view::reflection()
{
	//connect(log, SIGNAL(released()),  this->login() );
    connect(aut, SIGNAL(released()), this, SLOT(author()));
    //connect(qui, SIGNAL(released()), this, SLOT(quit()));
    connect(qui, &QPushButton::clicked, &QApplication::quit);
}

origin_view::origin_view(QWidget *parent):QMainWindow(parent)
{
    setWindowTitle(tr("Management Information of Student System"));
    resize(1000, 618);
    setObjectName("welcome");
    setStyleSheet("#welcome{border-image:url(:/img/bg);}");

    log = new QPushButton( this);
    log->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    log->move(250,400);//设置按钮的位置，左上角为原点
    log->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    log->setIconSize(QSize(80, 80));
    log->setStyleSheet("QPushButton{border-image:url(:/img/login_default)}""QPushButton:hover{border-image:url(:/img/login_hover)}""QPushButton:checked{border-image:url(:/img/login_press)}");//未选中状态

    aut = new QPushButton (this);
    aut->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    aut->move(500,400);//设置按钮的位置，左上角为原点
    aut->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    aut->setIconSize(QSize(80, 80));
    aut->setStyleSheet("QPushButton{border-image:url(:/img/about_default)}""QPushButton:hover{border-image:url(:/img/about_hover)}""QPushButton:checked{border-image:url(:/img/about_press)}");//未选中状态

    qui = new QPushButton( this);
    qui->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    qui->move(750,400);//设置按钮的位置，左上角为原点
    qui->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    qui->setIconSize(QSize(80, 80));
    qui->setStyleSheet("QPushButton{border-image:url(:/img/quit_default)}""QPushButton:hover{border-image:url(:/img/quit_hover)}""QPushButton:checked{border-image:url(:/img/quit_press)}");//未选中状态


   // QHBoxLayout *layout = new QHBoxLayout;
   // layout->addWidget(log);
   // layout->addWidget(aut);
   // layout->addWidget(qui);
   // this->setLayout(layout);
}


origin_view::~origin_view()
{

}


