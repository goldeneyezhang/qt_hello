#ifndef CANNON_H
#define CANNON_H

#include <QWidget>

class CannonField : public QWidget
{
    Q_OBJECT
public:
    CannonField(QWidget *parent = nullptr);

    QSizePolicy sizePolicy() const;

    int angle() const {return ang;}
    int force() const {return f;}


public slots:
    void setAngle(int degrees);
    void setForce(int newton);
    void shoot();
    void newTarget();

private slots:
    void moveShot();
    void moveTarget();

signals:
    void hit();
    void missed();
    void angleChanged(int);
    void forceChanged(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    void paintShot(QPainter *);
    void paintTarget(QPainter *);
    void paintCannon(QPainter *,Qt::GlobalColor color);
    QRect cannonRect() const;
    QRect shotRect() const;
    QRect targetRect() const;

    int ang;
    int f;

    int timerCount;
    int targetCount;
    int start;

    QTimer *autoShootTimer;
    QTimer *autoMoveTimer;
    float shoot_ang;
    float shoot_f;

    QPoint target;
};

#endif // CANNON_H
