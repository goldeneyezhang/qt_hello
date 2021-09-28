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
    bool gameOver() const {return gameEnded;}
    bool isShooting() const;


public slots:
    void setAngle(int degrees);
    void setForce(int newton);
    void shoot();
    void newTarget();
    void setGameOver();
    void restartGame();

private slots:
    void moveShot();
    void moveTarget();

signals:
    void hit();
    void missed();
    void angleChanged(int);
    void forceChanged(int);
    void canShoot(bool);

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

    bool gameEnded;
};

#endif // CANNON_H
