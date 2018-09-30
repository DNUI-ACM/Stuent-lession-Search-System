#ifndef __ORIGIN_H__
#define __ORIGIN_H__
#include <QtGui>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>


class origin_view: public QMainWindow
{
	Q_OBJECT
private slots:
    void    login();
    void    author();
    void    quit();

private:
    QPushButton *aut ;
    QPushButton *qui ;
    QPushButton *log ;
public:
    explicit origin_view(QWidget* parent = 0);
    ~origin_view();
};

#endif //
