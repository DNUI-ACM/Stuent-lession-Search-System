#ifndef __input__
#define __input__

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

class input:public QMainWindow//QWidget
{
    //Q_OBJECT
public:
    explicit input(QMainWindow* parent=0);

public slots:
    void input_lesson();
    void input_score();
public:
	QPushButton* prev;
};

#endif //__input__
