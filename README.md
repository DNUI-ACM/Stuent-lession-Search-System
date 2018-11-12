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

<<<<<<< HEAD
accout(student_ID(PRI), password_of_student50)<br>
school(school_ID(PRI), stu_name)<br>
teacher(teacher_ID(PRI)， teacher_name)<br>
information_of_student(stu_ID(PRI), stu_name, class_ID, sex,)<br>
department(department_ID(PRI), department_name, school_ID)<br>
major(major_ID(PRI), major_name, department_ID)<br>
lession(lession_ID，lession_name)<br>
apply_lession（lession_ID，class_ID，teacher_ID, lession_ID, class_ID）<br>
//这里上课时间只需要记 第几节  针对必修
=======
accout(index_of_student12, password_of_student50)<br>
school(学校代码10, 学校名称10)<br>
teacher(教师号10， 教师名10)<br>
information_of_student(学生号12, 学生姓名10, 班级号6, 性别1,)<br>
department(系号2, 系名称10, 学校代码10)<br>
major(专业号10, 专业名10, 系号)<br>
class(班级号4, 班级名, 专业号)<br>
classroom(教室号，教室名）<br>
lession(课程号，课程名)<br>
apply_lession（课程号10，班号10，教师号10）<br>//这里上课时间只需要记 第几节  针对必修



day(星期几int,    课程, 上课时间10); //select from day where day=1;//查星期1的课
time( 上课时间10, 课程号, 星期几); //select form time where time=12;//查12节, 12 34 56 78 910
>>>>>>> 2f4c084b8835b802b1b0bf30eb5dc0b8f8d55fac

eg:
insert into accout(index_of_student, password_of_student) values('17180600305', md5('明文密码'));<br>
比对用 md5 后与数据库中对比
成绩表(学生号, 专业名, 成绩)

假设：每个人的课表都不一样,如何保证 能应对每个人的查课需求呢
//n to n must create a table
//n to 1 索取外键

一个时间段可以有多门 课，
一门课 对应很多个班的学生,
时间地点确定的， 只有一节课

teacher(teacher_ID(PRI)， teacher_name)<br>
apply_lesson(lesson_ID, teacher_ID);
lesson(lesson_ID(PRI)，lesson_name)<br>
site(time_of_lesson(PRI), classroom(PRI));
student(stu_ID(PRI), password, major_ID(UML), stu_name, class_ID, sex);
major(major_ID(PRI), major_name, department_ID);
department(department_ID(PRI), department_name, school_ID(UML));
school(shcool_ID(PRI), school_name );
choose_lesson(stu_ID(PRI), lesson_ID(PRI));


create table teacher
(
 teacher_ID varchar(10) PRIMARY KEY not null,
 teacher_name varchar(10) not null
);

create table apply_lesson
(
 lesson_ID   varchar(4)  not null,
 teacher_ID  varchar(10)  not null,
 foreign key(lesson_ID)  references lesson(teacher_ID)     on delete cascade on update cascade,
 foreign key(teacher_ID) references teacher(teacher_ID)     on delete cascade on update cascade
);

create table lesson
(
 lesson_ID   varchar(4) PRIMARY KEY not null,
 lesson_name varchar(50) not null,
 foreign key(teacher_ID) reference teacher(teacher_ID)on delete cascade on update cascade
);

create table site
(
	time_of_lesson varchar(5) not null,
	classroom varchar(10) not null,
	PRIMARY KEY(time_of_lesson, classroom),
	foreign key(lesson_ID) reference lesson(lesson_ID)on delete cascade on update cascade
);

create table choose_lesson
(
stu_ID    not null,(uml)
lesson_ID not null,(uml)

foreign key(stu_ID)    reference lesson(stu_ID)on delete cascade on update cascade
foreign key(lesson_ID) reference lesson(lesson_ID)on delete cascade on update cascade
PRIMARY KEY(stu_ID, lesson_ID)
);


create table student
(
 stu_ID varchar(12) PRIMARY KEY not null,
 password varchar(50) not null,
 foreign key(major_ID) reference major(major_ID)on delete cascade on update cascade
 stu_name varchar(10) not null,
 sex      varchar(1)  not null
);

create table major
(
 major_ID   varchar(10) PRIMARY KEY not null,
 major_name varchar(13) not null,
 foreign key(department_ID) reference department(department_ID)on delete cascade on update cascade
);

create tbale department
(
department_ID   varchar(2) PRIMARY KEY not null, 
department_name varchar(10) not null,
school_ID foreign key() reference outTable(id)
foreign key(school_ID) reference school(school_ID)on delete cascade on update cascade
);

create table school
(
shcool_ID PRIMARY KEY not null, 
school_name varchar(10) not null
);


SET FOREIGN_KEY_CHECKS=0;//close check foregin key
...drop table....
SET FOREIGN_KEY_CHECKS=1;


// lof of table insert, must be create a function to do it;
// lack of a factor function









