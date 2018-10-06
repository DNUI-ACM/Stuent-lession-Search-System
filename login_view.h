#ifndef __LOGIN_VIEW__
#define __LOGIN_VIEW__
#include <QLineEdit>
#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class login_view:public QMainWindow//QWidget
{
    Q_OBJECT
public:
    //explicit login_view(QWidget* parent=0);
    explicit login_view(QMainWindow* parent=0);
    ~login_view();
public:
    QPushButton *froget_pass;
    QPushButton *loging;
	QLineEdit* admin;
	QLineEdit* password;
};

#endif //__LOGIN_VIEW__

