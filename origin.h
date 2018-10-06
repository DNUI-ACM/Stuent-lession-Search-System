#ifndef __ORIGIN_H__
#define __ORIGIN_H__
#include <QtGui>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>


class origin_view: public QMainWindow
{
	Q_OBJECT
public:
    QPushButton *aut ;
    QPushButton *qui ;
    QPushButton *log ;
public:
    explicit origin_view(QWidget* parent = 0);
    ~origin_view();
};

#endif //
