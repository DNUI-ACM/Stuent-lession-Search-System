#include "main_window.h"
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QString s = "Jack";
    qDebug() << "My name is " << s << ", nice to meet you!" << endl;
    qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
}


MainWindow::~MainWindow()
{

}






