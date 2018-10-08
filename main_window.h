//只写接口
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "origin.h"
#include "mysql.h"
#include "login_view.h"
#include "input.h"

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();

private:
    origin_view* welcome;
    login_view*  login_kuang;
	mysql*  stu_mysql;
	input*  inpu;

public slots:
    void to_login();
    void to_author();
    void to_quit();

    void to_verify();

	void to_input_lesson();
};

#endif //MAINWINDOW_H





