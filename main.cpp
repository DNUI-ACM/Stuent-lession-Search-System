#include "main_window.h"  //包含的是窗口的源文件
#include <QtGui>

//#include <QWidget>
//要求, main函数只能用来实例化类
int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //初始化
	MainWindow win;
    return app.exec();
}






















//QSpinBox *spinBox = new QSpinBox(&window);
//QSlider *slider = new QSlider(Qt::Horizontal, &window);
//spinBox->setRange(0, 130);
//slider->setRange(0, 130);

//QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
//void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
//QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
//spinBox->setValue(35);

//QHBoxLayout *layout = new QHBoxLayout;
//layout->addWidget(spinBox);
//layout->addWidget(slider);
//window.setLayout(layout);


