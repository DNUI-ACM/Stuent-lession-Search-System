//只写接口
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "origin.h"

class MainWindow:public QMainWindow
{
	Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();
private:
		origin_view* welcome;
};

#endif //MAINWINDOW_H





