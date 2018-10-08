#include "mysql.h"
#include <QCoreApplication>
#include <QTextCodec>

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
    db.setDatabaseName("student_lesson");
    if(db.open())
    {
        qWarning()<< "database connected successfully!!!";
        create_table();
        update_stu();
        insert_stu();
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
    //query = new QSqlQuery;
    //// 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
// 使数据库支持中文
    //query->exec("SET NAMES 'Latin1'");
// 创建 course 表
//    query->exec("create table accout (index_of_student varchar(12), " "password_of_student varchar(20)");
    //query->exec("insert into course values(0, '数学', '刘老师')");
    //query->exec("insert into course values(1, '英语', '张老师')");
    //query->exec("insert into course values(2, '计算机', '李老师')");
}

bool mysql::insert_stu()
{
    query = new QSqlQuery;
    //accout
    //query->exec( "insert into accout(index_of_student, password_of_student) values('17180600305', md5(123))");//插入用户信息
    //query->exec( "insert into accout(index_of_student, password_of_student) values('17180600302', md5(123))");//插入用户信息

    //query->exec("SET NAMES 'Latin1'");
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //插入课程信息 lession
    //query->exec("SET NAMES  'Utf8_bin'");
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('0', '数据库原理与技术' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('1', '大学英语3' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('2', 'Java面向对象程序设计' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('3', '概率论与数理统计' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('4', '体育三 足球' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('5', '大数据技术及应用' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('6', 'c++程序设计1' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('7', '中国近代史' )" );
    //query->exec("insert into lession(index_of_lession, name_of_lession) values('8', '物理实验' )" );

    //teacher
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('0', '周绍斌' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('1', '付天宇' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('3', '刘洋' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('4', '刘振宇' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('5', '褚娜' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('6', '宗磊' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('7', '王欣' )" );
    //query->exec("insert into teacher(index_of_teacher, name_of_teacher) values('8', '李乔敏' )" );

    //query->exec("insert into school(index_of_school, name_of_school) values('0', '大连东软信息学院' )" );

    //information_of_student
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600301', '温秦政', '17003', '男' )" );
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600302', '李星', '17003', '男' )" );
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600303', '孔朝功', '17003', '男' )" );
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600305', '杨兆', '17003', '男' )" );
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600326', '刘英明', '17003', '男' )" );
    // query->exec("insert into information_of_student(index_of_student, name_of_student, index_of_class, sex) values('17180600328', '杨蕊', '17003', '女' )" );

	//department
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('0', '计算机与软件学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('1', '信息与商务管理学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('2', '智能与电子工程学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('3', '数字艺术与设计学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('4', '外国语学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('5', '创新创业学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('6', '基础教育学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('7', '研究生部', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('8', '国际教育学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('9', '教育学院', '0' )" );
    // query->exec("insert into department(index_of_department, name_of_department, index_of_school) values('10', '高等职业技术学院', '0' )" );

	//major
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('0', '软件工程', '0' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('01', '计算机科学技术', '0' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('02', '物联网工程', '0' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('03', '数据科学与大数据', '0' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('04', '信息系统专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('05', '电子商务专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('06', '人力资源管理专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('07', '市场营销专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('08', '财务管理专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('09', '工程管理专业', '1' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('10', '智能科学与技术', '2' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('11', '通信工程', '2' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('12', '电子信息工程', '2' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('13', '集成电路设计与集成系统', '2' )" );
    //query->exec("insert into major(index_of_major, name_of_major, index_of_department) values('14', '微电子科学与工程', '2' )" );
	
	//apply_lession
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('0', '数据库原理与技术', '3' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('1', '大学英语3 ', '1' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('2', 'Java面向对象程序设计', '0' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('3', '概率论与数理统计', '7' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('4', '体育三 足球', '6' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('5', '大数据技术及应用', '5' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('6', 'c++程序设计1', '4' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('7', '中国近代史', '7' )" );
	query->exec("insert into apply_lession(index_of_lession, index_of_class, index_of_teacher, index_of_lession) values('8', '物理实验', '8' )" );
	
    qWarning() << query->lastError() <<endl;
    return true;
}

int mysql::verify_user(QString log, QString pass)
{
    query = new QSqlQuery;
    QString str=QString("select password_of_student from accout where index_of_student= '%1'").arg(log);
    bool success = query->exec(str);
    //bool success = query->exec("select password_of_student from accout where index_of_student= '17180600305'");
    if(!success)
    {
        qWarning() << "查询user失败" << endl;
    }

    //	qWarning()<< "str " << str << endl;
    //qWarning()<< "pass " << pass.toLatin1() << endl;
    // qWarning()<< "log " << log<< endl;

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
    query = new QSqlQuery;
    // 由于初次设计的数据库存在缺陷，因此不断的调用此函数修改
    // accout
    //query->exec( "alter table accout change index_of_student index_of_student varchar(12) PRIMARY KEY not null");//将accout 中 学号 设置为 primary key 且 not null
    //query->exec( "alter table accout change password_of_student password_of_student varchar(50) not null");//将accout 中 password_of_student 设置为 not null

    //lession
    //	query->exec( "alter table lession change index_of_lession index_of_lession varchar(4) PRIMARY KEY not null");
    //	query->exec( "alter table lession change name_of_lession name_of_lession varchar(50) not null");//for table lession

    //teacher
//	query->exec( "alter table teacher change idnex_of_teacher index_of_teacher varchar(10) PRIMARY KEY not null");//for table lession
//	query->exec( "alter table teacher change name_of_teacher name_of_teacher varchar(10) not null");//for table lession

    //school
//query->exec( "alter table school change index_of_school index_of_school varchar(10) PRIMARY KEY not null");//for table lession
//query->exec( "alter table school change name_of_school name_of_school varchar(10) not null");//for table lession

    //information_of_student
    //query->exec( "alter table information_of_student change index_of_student index_of_student varchar(12) RIMARY KEY not null");
    // query->exec( "alter table information_of_student change name_of_student name_of_student varchar(10)  not null");
    // query->exec( "alter table information_of_student change index_of_class index_of_class varchar(6)  not null");
    // query->exec( "alter table information_of_student change sex sex varchar(1)  not null");

	//department
	//query->exec( "alter table department change index_of_department index_of_department varchar(2) PRIMARY KEY not null");
	//query->exec( "alter table department change name_of_department  name_of_department varchar(10) not null");
	//query->exec( "alter table department change index_of_school index_of_school varchar(10) not null");
	
	//major
//	query->exec( "alter table major change index_of_major index_of_major varchar(10) PRIMARY KEY not null");
//	query->exec( "alter table major change name_of_major name_of_major varchar(13)  not null");
//	query->exec( "alter table major change index_of_department index_of_department varchar(2) not null");

	//apply_lession
	query->exec( "alter table  apply_lession change idnex_of_lession index_of_lession varchar(4) not null");
    qWarning() << query->lastError() << endl;
    return true;
}












