## The Student Information Mangement System

## The fault of my coding
1. if use "Q_OBJECT" must be create two that file .h and .cpp, otherwise, It will be lead to a lots of bug.

2. Can't connect mysql
> Erro: QSqlDatabase: QMYSQL driver not loaded  
QSqlDatabase: available drivers: QSQLITE

```c++
 qWarning() << QSqlDatabase::drivers();
 qWarning() << QCoreApplication::libraryPaths();
//("QSQLITE")
//("/usr/lib64/qt5/plugins", "/home/joe/code/QT")
```
do:
```bash
$ sudo dnf install qt5-qtbase-mysql
```  
  
3. can't insert chinese charter 
do:
```
	1. update the charter set of your datebase;
	2. update the charter set of your tables
	1. update the charter set of you  mysql(maridb);
```
<br>
## Note
1. insert background to mainwindow
```c++
    log->setStyleSheet
	(
	"QPushButton{border-image:url(:/img/login_default)}"
	"QPushButton:hover{border-image:url(:/img/login_hover)}"
	"QPushButton:checked{border-image:url(:/img/login_press)}"
	);//未选中状态
```
2. how to using signal and slot
```c++
connect(log, SIGNAL(released()),  this, SLOT(login()) );
```
3. ABBET
> using mainwindows object to mange object
```c++
 class MainWindows;
 | class origin;
   | login()
	 | class login_view;
	 | class choose_option;
	   | class lession_output;
       | class score_output;
   | about_author()
   | quit()

```

4. how to connect some difference view???
> just remerber all the connect should diaoyong in main_win.cpp
```c++

```

## The design of database
accout(index_of_student12, password_of_student50)<br>
school(学校代码10, 学校名称10)<br>
teacher(教师号10， 教师名10)<br>
information_of_student(学生号12, 学生姓名10, 班级号6, 性别1,)<br>
department(系号2, 系名称10, 学校代码10)<br>
major(专业号10, 专业名10, 系号)<br>

class(班级号4, 班级名, 专业号)<br>
classroom(教室号，教室名）<br>
lession(课程号，课程名)<br>
level(年级号，年级名)<br>

apply_lession（课程号10，班号10，教师号10）<br>//这里上课时间只需要记 第几节

day(星期几int,    课程号, 上课时间10); //select from day where day=1;//查星期1的课
time( 上课时间10, 课程号, 星期几); //select form time where time=12;//查12节, 12 34 56 78 910

eg:
insert into accout(index_of_student, password_of_student) values('17180600305', md5('明文密码'));<br>
比对用 md5 后与数据库中对比
成绩表(学生号, 专业名, 成绩)



