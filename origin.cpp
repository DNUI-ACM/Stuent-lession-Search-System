#include "origin.h"
#include "main_window.h"
#include <QMessageBox>
#include <QHBoxLayout>


origin_view::origin_view(QWidget *parent):QMainWindow(parent)
{
    setWindowTitle(tr("Management Information of Student System"));
    resize(1000, 618);
	move(480, 240);
    setObjectName("origin_view");
    setStyleSheet("#origin_view{border-image:url(:/img/bg);}");
	setMinimumSize(1000, 618);  //最小尺寸

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


  //  connect(qui, &QPushButton::clicked, &QApplication::quit);

  //  QHBoxLayout *layout = new QHBoxLayout;
  //  layout->addWidget(log);
  //  layout->addWidget(aut);
  //  layout->addWidget(qui);
  //  layout->setStretchFactor(log, 2000);
  //  layout->setStretchFactor(aut, 2000);
  //  layout->setStretchFactor(qui, 2000);
  //  this->setLayout(layout);
}


origin_view::~origin_view()
{

}


