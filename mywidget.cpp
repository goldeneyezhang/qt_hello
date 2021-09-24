#include "mywidget.h"
#include <QPushButton>
#include <qapplication.h>
#include <QVBoxLayout>
#include <lcdrange.h>
#include <cannon.h>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400,400);
    setMaximumSize(800,600);

    QPushButton *quit = new QPushButton("Quit",this);
    //quit->setGeometry(0,0,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    /*QGridLayout *grid = new QGridLayout(this);

    for(int r=0;r<4;r++)
        for(int c=0;c<4;c++){
            LCDRange *lcdRange = new LCDRange();
            grid->addLayout(lcdRange,r,c);
        }*/

    LCDRange *angle = new LCDRange();
    angle->setRange(5,70);

    Cannon *cannon = new Cannon();

    connect(angle,SIGNAL(valueChanged(int)),cannon,SLOT(setAngle(int)));
    connect(cannon,SIGNAL(angleChanged(int)),angle,SLOT(setValue(int)));

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(quit,0,0);
    grid->addLayout(angle,1,0,Qt::AlignRight);
    grid->addWidget(cannon,1,1);
    grid->setColumnStretch(1,10);

    angle->setValue(60);
    cannon->setAngle(20);
}
