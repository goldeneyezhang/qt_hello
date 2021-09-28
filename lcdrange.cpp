#include "lcdrange.h"

#include <QSlider>
#include <QLCDNumber>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>

LCDRange::LCDRange(QWidget *parent):QWidget(parent)
{
    init();
}

LCDRange::LCDRange(const char *s, QWidget *parent):QWidget(parent)
{
    init();
    setText(s);
}

void LCDRange::init()
{
    QLCDNumber *lcd = new QLCDNumber(2);
    slider = new QSlider(Qt::Horizontal);

    slider->setRange(0,99);
    slider->setValue(0);

    label = new QLabel( " " );
    label->setAlignment( Qt::AlignCenter );

    connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
    connect( slider, SIGNAL(valueChanged(int)),SIGNAL(valueChanged(int)));

    QVBoxLayout *l = new QVBoxLayout(this);
    l->addWidget(lcd,1);
    l->addWidget(slider);
    l->addWidget(label);
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

int LCDRange::value() const
{
    return slider->value();
}

const QString LCDRange::text() const
{
    return label->text();
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

void LCDRange::setText(const QString s)
{
    label->setText(s);
}
