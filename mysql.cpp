#include "mysql.h"
#include <QCoreApplication>
#include <QTextCodec>
QSqlQuery*& mysql::cha()
{
    return query;
}

QSqlError mysql::initsql()
{

    qWarning() << QSqlDatabase::drivers();
    qWarning() << QCoreApplication::libraryPaths();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);  //设置端口
    //db.setHostName("localhost");
    db.setUserName("yang_zhao");
    db.setPassword("123");
    //db.setDatabaseName("student_lesson");
    db.setDatabaseName("lesson");
    if(db.open())
    {
		qWarning()<< "database connected successfully!!!";
        create_table();
        //update_stu();
        return db.lastError();
    }
    else
    {
        qWarning()<<"Database connected failed!";
        qWarning()<< db.lastError();
        return db.lastError();
    }

}

void mysql::create_table()
{
    query = new QSqlQuery;
	//apply_lesson(lesson_ID(MUL), teacher_ID(MUL));
	//choose_lesson(stu_ID(MUL), lesson_ID(MUL));
	//department(department_ID(PRI), department_name, school_ID(MUL));
	//teacher(teacher_ID(PRI)， teacher_name)
	//lesson(lesson_ID(PRI)，lesson_name)
	//school(shcool_ID(PRI), school_name );
	//student(stu_ID(PRI), password, major_ID(MUL), stu_name, sex);
	//major(major_ID(PRI), major_name, department_ID(MUL));
	//site(time_of_lesson(PRI), classroom(PRI), lesson_ID(MUL));


	// 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
	//query->exec("create table teacher( teacher_ID varchar(10) PRIMARY KEY not null, teacher_name varchar(10) not null)");


	//query->exec("create table lesson( lesson_ID  varchar(4) PRIMARY KEY not null, lesson_name varchar(50) not null)");

	//query->exec("create table site ( time_of_lesson varchar(5) not null, classroom varchar(10) not null, PRIMARY KEY(time_of_lesson, classroom), lesson_ID  varchar(4) not null, foreign key(lesson_ID) references lesson(lesson_ID) on delete cascade on update cascade); ");

	//query->exec("create table school (school_ID int PRIMARY KEY not null, school_name varchar(10) not null)");

	//query->exec("create table department ( department_ID   varchar(2) PRIMARY KEY not null, department_name varchar(10) not null, school_ID int not null, foreign key(school_ID) references school(school_ID) on delete cascade on update cascade)");

	//query->exec("create table major ( major_ID  varchar(10) PRIMARY KEY not null, major_name varchar(13) not null, department_ID   varchar(2) not null, foreign key(department_ID) references department(department_ID) on delete cascade on update cascade)");

	//query->exec("create table student ( stu_ID varchar(12) PRIMARY KEY not null, password varchar(50) not null, major_ID  varchar(10) not null, foreign key(major_ID) references major(major_ID) on delete cascade on update cascade, stu_name varchar(10) not null, sex      varchar(1)  not null)");

//	query->exec("create table choose_lesson ( stu_ID varchar(12)  not null, foreign key(stu_ID) references student(stu_ID) on delete cascade on update cascade, lesson_ID  varchar(4) not null, foreign key(lesson_ID) references lesson(lesson_ID) on delete cascade on update cascade)");

//	query->exec("create table apply_lesson (  lesson_ID  varchar(4) not null, foreign key(lesson_ID) references  lesson(lesson_ID) on delete cascade on update cascade, teacher_ID varchar(10) not null, foreign key(teacher_ID) references teacher(teacher_ID) on delete cascade on update cascade)");

	
	//    qWarning() << query->lastError() <<endl;


	// school
	//query->exec("insert into school(school_ID, school_name) values('0', '大连东软信息学院' )" );
	//    qWarning() << query->lastError() <<endl;

	//department
	//query->exec("insert into department(department_ID, department_name, school_ID) values('0', '计算机与软件学院',   '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('1', '信息与商务管理学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('2', '智能与电子工程学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('3', '数字艺术与设计学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('4', '外国语学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('5', '创新创业学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('6', '基础教育学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('7', '研究生部', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('8', '国际教育学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('9', '教育学院', '0' )" );
	//query->exec("insert into department(department_ID, department_name, school_ID) values('10', '高等职业技术学院', '0' )" );
	//qWarning() << query->lastError() <<endl;

	//major
	//query->exec("insert into major(major_ID, major_name, department_ID) values('0', '软件工程', '0' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('01', '计算机科学技术', '0' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('02', '物联网工程', '0' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('03', '数据科学与大数据', '0' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('04', '信息系统专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('05', '电子商务专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('06', '人力资源管理专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('07', '市场营销专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('08', '财务管理专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('09', '工程管理专业', '1' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('10', '智能科学与技术', '2' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('11', '通信工程', '2' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('12', '电子信息工程', '2' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('13', '集成电路设计与集成系统', '2' )" );
	//query->exec("insert into major(major_ID, major_name, department_ID) values('14', '微电子科学与工程', '2' )" );
	//qWarning() << query->lastError() <<endl;

	//student
	//query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600302', md5(123), '0', '李星',    '男' ) ");
	//query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600303', md5(123), '0', '孔朝功',  '男' ) ");
    //query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600304', md5(123), '0', '刘子奇',  '男' ) ");
    //query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600305', md5(123), '0', '杨兆',    '男' ) ");
    //query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600326', md5(123), '0', '刘英明',  '男' ) ");
    //query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('17180600328', md5(123), '0', '杨蕊',    '女' ) ");
    //qWarning() << query->lastError() <<endl;

	//insert into  teacher
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('0', '周绍斌' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('1', '付天宇' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('2', '史纲要' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('3', '刘洋' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('4', '刘振宇' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('5', '褚娜' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('6', '宗磊' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('7', '王欣' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('8', '李乔敏' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('9',   '美女' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('10',  '崔岩' )" );
	//query->exec("insert into teacher(teacher_ID, teacher_name) values('11',  '闫海妮' )" );
//11 11	
	qWarning() << query->lastError() <<endl;

	 //apply_lession
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('0', '3') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('1', '1') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('2', '0') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('3', '7') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('4', '6') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('5', '5') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('6', '4') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('7', '2') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('8', '8') " );

	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('9', '9') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('10', '10') " );
	//query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('11', '11') " );

	//lesson	                                                                                            
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('0', '数据库原理与技术' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('1', '大学英语3' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('2', 'Java面向对象程序设计' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('3', '概率论与数理统计' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('4', '体育三 足球' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('5', '大数据技术及应用' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('6', 'c++程序设计1' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('7', '中国近代史' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('8', '物理实验' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('9',  '音乐赏析' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('10', '大学英语3' )" );
	//query->exec("insert into lesson(lesson_ID, lesson_name) values('11', '数据库原理与技术' )" );
    //qWarning() << query->lastError() <<endl;

	//choose_lesson  insert_only_once!!! because
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '0' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '1' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '2' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '3' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '4' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '5' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '6' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '7' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600305', '8' )" );
	
	////wen qin zheng
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '2' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '3' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '4' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '5' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '7' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '8' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '9' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '10' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '11' )" );
	//query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '8' )" );
	

	//site                                                                        time    site    lesson_ID
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('1078', 'A7-106', '0'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('3078', 'A7-106', '0'  ) " );
//	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('5034', 'A6-402', '1'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('2012', 'A6-402', '1'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('2034', 'A7-101', '2'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('5012', 'A7-101', '2'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('4012', 'A7-106', '3'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('2078', 'A3-309', '5'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('5078', 'A3-309', '5'  ) " );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('4034', '三期体育场', '4') " );
	
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('4078', 'A12', '8') " );

	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('2012', 'A7-221', '10')" );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('5034', 'A7-221', '10')" );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('1078', 'A5-203', '9' )" );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('1012', 'A7-313', '11' )" );
	//query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('3034', 'A5-313', '11' )" );

		//QSqlError("1062", "QMYSQL: Unable to execute query", "Duplicate entry '10' for key 'PRIMARY'") 

//department       
//major            
//school           
//student          
//lesson           
//choose_lesson    
//apply_lesson     
//teacher

}                                                                                      

bool mysql::insert_stu()
{
//	query->exec("insert into student(stu_ID, password, major_ID, stu_name, sex) values('%1', md5(%2), '%3', '%4',  '%5') ").arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//
//	query->exec("insert into major(major_ID, major_name, department_ID) values('%3', '集成电路设计与集成系统', '2' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//
//	query->exec("insert into site(time_of_lesson, classroom, lesson_ID) values('5034', 'A7-221', '10')" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	query->exec("insert into choose_lesson(stu_ID, lesson_ID) values('17180600301', '8' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	query->exec("insert into lesson(lesson_ID, lesson_name) values('8', '物理实验' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	query->exec("insert into apply_lesson(lesson_ID, teacher_ID) values('10', '10') " )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	query->exec("insert into teacher(teacher_ID, teacher_name) values('10',  '崔岩' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	 //school
//	query->exec("insert into school(school_ID, school_name) values('0', '大连东软信息学院' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	    qWarning() << query->lastError() <<endl;
//
//	//department
//	query->exec("insert into department(department_ID, department_name, school_ID) values('0', '计算机与软件学院',   '0' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);
//	
//	    query->exec("insert into lesson(lesson_ID, lesson_name) values('0', '数据库原理与技术' )" )arg(stu_ID, password, major_ID, major_name, stu_name, sex);

	return true;
}

int mysql::verify_user(QString log, QString pass)
{
    query = new QSqlQuery;
    QString str=QString("select password from student where stu_ID='%1'").arg(log);
    bool success = query->exec(str);
    if(!success)
    {
        qWarning() << "查询user失败" << endl;
    }

    //qWarning()<< "str " << str << endl;
    //qWarning()  << "pass" << pass.toLatin1() << endl;
    //qWarning() << "log " << log<< endl;

    //query->seek(-1);
    if( false == query->next() )
    {
        return 0;
    }

    QString name = query->value(0).toString();
    if( name == pass )
        return 1;
    query->next();

    while(query->next())
    {
        QString name = query->value(0).toString();
        if( name == pass )
            return 1;
    }
    return -1;

//第一次调用next()函数就可以把这个QSqlQuery定位到结果集中的第一条记录。随后的next调用都会把记录指针后移一条记录，直至到达结尾时next才返回false。如果结果集为空（或查询失败），那么next第一次调用将返回false。value()函数把字段值做为QVariant返回，字段是按照SELECT语句中给定的顺序从编号0开始的（千万不要弄错顺序）。
}

bool mysql::forgot_password()//建表 索引 触发器
{
    return true;

}

bool mysql::delete_stu()
{

    return true;
}

bool mysql::update_stu()
{
    // 由于初次设计的数据库存在缺陷，因此不断的调用此函数修改

    return true;
}












