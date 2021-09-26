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
    QBrush *brush = new QBrush();
    brush->setColor(Qt::GlobalColor::blue);

    p.setBrush(*brush);
    p.setPen(Qt::PenStyle::DotLine);

    p.translate(0,rect().bottom());
    p.drawPie(QRect(-35,-35,70,70),0,90*16);
    p.rotate(-ang);
    p.drawRect(QRect(33,-4,15,8));
    p.drawText(200,200,s);
}

QSizePolicy Cannon::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
