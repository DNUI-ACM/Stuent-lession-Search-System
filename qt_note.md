# qt的学习
## Qt为什么要分 main.cpp mainwindow.h mainwindow.cpp三个文件呢??
关于 .h 与 .cpp 的区别不多讨论,这里只讨论 mainwindow 的意义。 
#### 1. maiwindow
```c++

```
## 常见的类 和 函数
### 1. QWidget类
常见函数:

**show()**  展示窗口用的  
**resize()**  设置尺寸用的

### 2. QSpinBox类
> QSpinBox就是只能输入数字的输入框  

**setRange()**函数设置其范围  

### 3. QSpinBox类
QSlider则是带有滑块的滑竿

### 4. QDialog类
对话窗口更多的用这个类

### 5.QLabel标签类  
提供文本或者对象的显示

### 6.QPushButton按钮类  
提供了命令按钮的一种

### 7.QImage按钮类  
图像类

<br>
## QT信号和槽
>  信号(signal )与槽(slot) ， 按钮检测到自己被点击了一下，它就会发出一个信号（signal）。这种发出是没有目的的，类似广播。如果有对象对这个信号感兴趣，它就会使用连接（connect）函数，意思是，用自己的一个函数（成为槽（slot））来处理这个信号。也就是说，当信号发出时，被连接的槽函数会自动被回调。这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发。

请记住 **QObject::connect( 按钮名1, 对1的行为, 接受者, 接受者的行为)** 这个函数, 在QT中有五种重载
```c++
connect(sender, signal, receiver, slot);
QMetaObject::Connection connect(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType);
QMetaObject::Connection connect(const QObject *, const char *, const char *, Qt::ConnectionType) const;
QMetaObject::Connection connect(const QObject *, PointerToMemberFunction, const QObject *, PointerToMemberFunction, Qt::ConnectionType)
QMetaObject::Connection connect(const QObject *, PointerToMemberFunction, Functor);//Functor ——> static函数，全局函数，lambda表达式
//最常用形式
QMetaObject::Connection connect(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &, Qt::ConnectionType);
```

<br>
例子
```c++
// !!! Qt 5
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Quit");
    QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    button.show();

    return app.exec();
}
```
**注**:slot 的参数不能多于 singal 的信号  

## 自定义信号和槽
> Qt最大的贡献是让程序员可以用 c++ 写出低耦合的代码

## QT添加动作 
> 要用到 QAction 这个类作为动作, 当用户点击这个菜单项， 对用户的点击作出响应

## QT添加资源文件
> 将图标，翻译文件的等等全部放在里面等

1. 新建文件夹及文件 **img/xx.qrc**
2. 输入内容
```
<RCC>
 <qresource prefix="/img">
     <file alias="start">start.png</file>
 </qresource>
</RCC>
```
改别名操作也在里面, 自行阅读
3. 在 .pro文件中添加
```
RESOURCE += (路径)文件
```


## QT布局管理
> 不要通过绝对定位去写GUI，这是非常愚蠢的。一旦最大化，所有一切都将被拉的变形。
这个时候有两种做法。 一. 禁止拉伸 二. 使用布局机制

## Qt事件
> 信号与槽是即刻处理的，但事件不是. 信号由具体的对象发出，然后会马上交给由connect()函数连接的槽进行处理；而对于事件，Qt 使用一个事件队列对所有发出的事件进行维护，当新的事件产生时，会被追加到事件队列的尾部。前一个事件完成后，取出后面的事件进行处理。但是，必要的时候，Qt 的事件也可以不进入事件队列，而是直接处理。信号一旦发出，对应的槽函数一定会被执行。但是，事件则可以使用“事件过滤器”进行过滤，对于有些事件进行额外的处理，另外的事件则不关心。
> Qt 程序需要在main()函数创建一个QCoreApplication对象，然后调用它的exec()函数。这个函数就是开始 Qt 的事件循环。在执行exec()函数之后，程序将进入事件循环来监听应用程序的事件。当事件发生时，Qt 将创建一个事件对象。Qt 中所有事件类都继承于QEvent。在事件对象创建完毕后，Qt 将这个事件对象传递给QObject的event()函数。event()函数并不直接处理事件，而是按照事件对象的类型分派给特定的事件处理函数（event handler）。关于这一点，我们会在以后的章节中详细说明。

