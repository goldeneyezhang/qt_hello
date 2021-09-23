#include "lcdrange.h"

#include <QSlider>
#include <QLCDNumber>

LCDRange::LCDRange(QWidget *parent):QVBoxLayout(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    slider = new QSlider(Qt::Orientation::Horizontal);

    slider->setRange(0,99);
    slider->setValue(0);

    this->addWidget(lcd);
    this->addWidget(slider);

    connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
    connect(slider,SIGNAL(valueChanged(int)),SLOT(display(int)));
}


void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

int LCDRange::value() const
{
    return slider->value();
}
