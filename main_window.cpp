#include "main_window.h"
#include "origin.cpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	origin_view* welcome = new origin_view();
	welcome->reflection();
	welcome->show();
}


MainWindow::~MainWindow()
{
}







