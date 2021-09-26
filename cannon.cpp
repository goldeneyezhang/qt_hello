#include "cannon.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTimer>

#include <math.h>

CannonField::CannonField(QWidget *parent) : QWidget(parent)
{
    ang = 45;
    f = 0;
    timerCount=0;
    autoShootTimer=new QTimer(this);
    connect(autoShootTimer,SIGNAL(timeout()),this,SLOT(moveShot()));
    shoot_ang = 0;
    shoot_f = 0;

    setPalette(QPalette(QColor(250,250,200)));
    setAutoFillBackground(true);

}

void CannonField::setAngle(int degrees)
{
    if(degrees < 5)
        degrees = 5;
    if(degrees > 70)
        degrees = 70;
    if(ang == degrees)
        return;
    ang = degrees;
    repaint( cannonRect());
    emit angleChanged(ang);
}

void CannonField::setForce(int newton)
{
    if(newton < 0)
        newton = 0;
    if(f == newton)
        return;
    f = newton;
    emit forceChanged(f);
}

void CannonField::shoot()
{
    if(autoShootTimer->isActive())
        return;
    timerCount = 0;
    shoot_ang = ang;
    shoot_f = f;
    autoShootTimer->start(50);
}

void CannonField::moveShot()
{
    QRegion r(shotRect());
    timerCount++;

    QRect shotR = shotRect();

    if(shotR.x() > width() || shotR.y() > height())
        autoShootTimer->stop();
    else
        r = r.united(QRegion(shotR));
    repaint(r);
}
void CannonField::paintEvent(QPaintEvent *e)
{
   /*if(!e->rect().intersects(cannonRect()))
        return;*/


    QRect updateR = e->rect();
    QPainter p (this);

    if(updateR.intersects(cannonRect()))
        paintCannon(&p);
    if(autoShootTimer->isActive() && updateR.intersects(shotRect()))
        paintShot(&p);
}

void CannonField::paintShot(QPainter *p)
{
   p->setBrush(Qt::black);
   p->setPen(Qt::NoPen);
   p->drawRect(shotRect());
}

const QRect barrelRect(33,-4,15,8);

void CannonField::paintCannon(QPainter *p)
{
    QRect cr = cannonRect();
    QPixmap pix(cr.size());
    pix.fill(QColor(250,250,200));

    QPainter tmp(&pix);
    tmp.setBrush(Qt::blue);
    tmp.setPen(Qt::NoPen);

    tmp.translate(0,pix.height() - 1);
    tmp.drawPie(QRect(-35,-35,70,70),0,90*16);
    tmp.rotate(-ang);
    tmp.drawRect(barrelRect);
    tmp.end();

    p->drawPixmap(cr.topLeft(),pix);
}
QRect CannonField::cannonRect() const
{
    QRect r(0,0,50,50);
    r.moveBottomLeft(rect().bottomLeft());
    return r;
}

QRect CannonField::shotRect() const
{
    const double gravity =4;
    double time = timerCount / 4.0;
    double velocity = shoot_f;
    double radians = shoot_ang*3.14159265/180;

    double velx = velocity*cos(radians);
    double vely = velocity*sin(radians);
    double x0 = (barrelRect.right() + 5)*cos(radians);
    double y0 = (barrelRect.right() + 5)*sin(radians);
    double x = x0 + velx*time;
    double y = y0 + vely*time - 0.5*gravity*time*time;

    QRect r = QRect(0,0,6,6);
    r.moveCenter(QPoint(qRound(x),height() - 1 - qRound(y)));
    return r;
}
QSizePolicy CannonField::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
