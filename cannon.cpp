#include "cannon.h"
#include <QPainter>

Cannon::Cannon(QWidget *parent) : QWidget(parent)
{
    ang = 45;
    setPalette(QPalette(QColor(75,250,200)));
}

void Cannon::setAngle(int degrees)
{
    if(degrees < 5)
        degrees = 5;
    if(degrees > 70)
        degrees = 70;
    if(ang == degrees)
        return;
    ang = degrees;
    repaint();
    emit angleChanged(ang);
}

void Cannon::paintEvent(QPaintEvent *)
{
    QString s = "Angle = "+QString::number(ang);
    QPainter p(this);
    p.drawText(200,200,s);
}

QSizePolicy Cannon::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
