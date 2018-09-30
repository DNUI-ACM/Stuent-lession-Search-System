#include "main_window.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	welcome = new origin_view();
	welcome->show();
}


MainWindow::~MainWindow()
{
}







