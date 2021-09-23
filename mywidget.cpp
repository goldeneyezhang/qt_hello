#include "mywidget.h"
#include <QPushButton>
#include <qapplication.h>
#include <QVBoxLayout>
#include <lcdrange.h>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400,400);
    setMaximumSize(800,600);

    QPushButton *quit = new QPushButton("Quit",this);
    quit->setGeometry(0,0,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));

    QGridLayout *grid = new QGridLayout(this);

    for(int r=0;r<4;r++)
        for(int c=0;c<4;c++){
            LCDRange *lcdRange = new LCDRange();
            grid->addLayout(lcdRange,r,c);
        }

    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));

}
