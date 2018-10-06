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
school(学校代码, 学校名称)
department(系号, 系名称,学校代码)
major(专业号, 专业名, 系号)
class(班级号10, 班级名, 专业号)
information_of_student(学生编号, 学生姓名, 班级号12, 性别,)
teacher()教师号，教师名)
classroom(教室号，教室名）
息表(课程号，课程名)
level(年级号，年级名)

apply_lession（课程号，班号，教师号，上课时间）

accout(idnex_of_student, password_of_student)
eg:
insert into accout(index_of_student, password_of_student) values('17180600305', md5('明文密码'));
比对用 md5 后与数据库中对比
成绩表(学生号, 专业名, 成绩)



