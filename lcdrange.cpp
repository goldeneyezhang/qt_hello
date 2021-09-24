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
    connect( slider, SIGNAL(valueChanged(int)),SIGNAL(valueChanged(int)) );

}


void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setRange(int minVal,int maxVal)
{
    if(minVal <0 || maxVal > 99 || minVal > maxVal){
        qWarning( "LCDRange::setRange(%d,%d)\n"
                     "\tRange must be 0..99\n"
                     "\tand minVal must not be greater than maxVal",
                     minVal, maxVal );
            return;
    }
    slider->setRange(minVal,maxVal);
}
