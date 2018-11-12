#include "input.h"

input::input(QMainWindow* parent):QMainWindow(parent)
{
    setWindowTitle(tr("Management Information of Student System"));
    resize(1000, 618);
    move(480, 240);
    setObjectName("input");
    setStyleSheet("#input{border-image:url(:/img/bg);}");
    setMinimumSize(1000, 618);  //最小尺寸

    prev = new QPushButton( this);
    prev ->resize(50,50);//设置控件大小，一般情况下设置为图片大小
    prev ->move(50,30);//设置按钮的位置，左上角为原点
    prev ->setCheckable(true);//设置按钮可以被点击（选中）,少了这句按钮不能点，点了也没反应
    //loging->setIconSize(QSize(50, 50));

    prev->setStyleSheet("QPushButton{border-image:url(:/img/prev_default)}""QPushButton:hover{border-image:url(:/img/prev_hover)}""QPushButton:checked{border-image:url(:/img/prev_default)}");//未选中状态

    QStringList hang, lie;
	hang << " 星期一 " << " 星期二 " << " 星期三 " << " 星期四 " << " 星期五 ";
	lie << " 1~2节 " << " 3~4节 " << " 5~6节 " << " 7~8节 " << " 9~10节 ";



		//mysql->query = new QSqlQuery;


    lession = new QTableWidget(5, 5, this);
    lession->setHorizontalHeaderLabels(hang);
    lession->setVerticalHeaderLabels(lie);
	//lession->setItem(2, 3, new QTableWidgetItem(QString(tr("asdf"))));
    //lession->setItem(1, 0, new QTableWidgetItem(QString(tr("0002"))));
	lession->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lession->move(100, 130);
    lession->resize(800, 430);

    lession->setColumnWidth(0,147);
    lession->setColumnWidth(1,146);
    lession->setColumnWidth(2,146);
    lession->setColumnWidth(3,146);
    lession->setColumnWidth(4,147);
	lession->setRowHeight(0,80);
	lession->setRowHeight(1,80);
	lession->setRowHeight(2,80);
	lession->setRowHeight(3,80);
	lession->setRowHeight(4,80);
//    lession->show();


    QStringList date;
	date << "学号" << "姓名" << "专业" << "性别";
	infor = new QTableWidget(1, 4, this);
    infor->setHorizontalHeaderLabels(date);
	infor->resize(440, 65);
	infor->move(150, 50);

    infor->setColumnWidth(0,120);//行宽
	infor->setRowHeight(0,35);//列高
//	infor->show();
}

void input::input_lesson()
{

};

void input::input_score()
{

}

