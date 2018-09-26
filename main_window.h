//只写接口
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QString>

class MainWindow: public QMainWindow
{
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
private:
	//origin_view* welcome;
};

#endif //MAINWINDOW_H


