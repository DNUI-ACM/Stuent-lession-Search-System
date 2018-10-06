#include "login_view.h"
#include <QLineEdit>
#include <QPushButton>

login_view::login_view(QMainWindow* parent/*QWidget* parent*/):/*QWidget(parent)*/QMainWindow(parent)
{

    setWindowTitle(tr("Management Information of Student System"));
    resize(490, 300);
    move(720, 370);
    setObjectName("login_view");
    setStyleSheet("#login_view{border-image:url(:/img/bg);}");
    setMinimumSize(400, 250);  //最小尺寸

    loging = new QPushButton( this);
    loging->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    loging->move(250,200);//设置按钮的位置，左上角为原点
    loging->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    //loging->setIconSize(QSize(50, 50));

    loging->setStyleSheet("QPushButton{border-image:url(:/img/admin_default)}""QPushButton:hover{border-image:url(:/img/admin_hover)}""QPushButton:checked{border-image:url(:/img/admin_hover)}");//未选中状态


    froget_pass = new QPushButton( this);
    froget_pass->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    froget_pass->move(320,200);//设置按钮的位置，左上角为原点
    froget_pass->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    froget_pass->setIconSize(QSize(80, 40));

    froget_pass->setStyleSheet("QPushButton{border-image:url(:/img/forgot_hover)}""QPushButton:hover{border-image:url(:/img/forgot_default)}""QPushButton:checked{border-image:url(:/img/forgot_hover)}");//未选中状态

    admin = new QLineEdit(this);
    admin->move(130, 100);
    admin->resize(250, 40);
    admin->setClearButtonEnabled(true);
    admin->show();

    password = new QLineEdit(this);
    password->move(130, 150);
    password->resize(250, 40);
    password->show();
    password->setEchoMode(QLineEdit::Password);
    password->setClearButtonEnabled(true);
    password->setAcceptDrops(true);//文本不能被拖拽进来
	//password->setContextMenuPolicy(Qt::NoContextMenu). //该行编辑框内不会出现菜单
    //暗注释;
	admin->setPlaceholderText("学号"); 
    password->setPlaceholderText("密码");

}

login_view::~login_view()
{
}





