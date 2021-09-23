#include "mywidget2.h"

MyWidget2::MyWidget2(QWidget *parent) : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit",this);
    quit->setFont(QFont("Times",15,QFont::Bold));
    quit->setGeometry(101,0,50,50);
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    QLCDNumber *lcd = new QLCDNumber(2,this);
    lcd->setGeometry(0,0,50,50);
    lcd->setDigitCount(4);

    QSlider *slider = new QSlider(Qt::Orientation::Horizontal,this);
    slider->setRange(0,9999);
    slider->setValue(0);
    slider->setGeometry(0,50,150,50);

    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->setGeometry(101,50,50,50);

    connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
    connect(spinBox,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
}
