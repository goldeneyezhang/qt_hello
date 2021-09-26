#ifndef CANNON_H
#define CANNON_H

#include <QWidget>

class CannonField : public QWidget
{
    Q_OBJECT
public:
    explicit CannonField(QWidget *parent = nullptr);

    QSizePolicy sizePolicy() const;

    int angle() const {return ang;}
    int force() const {return f;}


public slots:
    void setAngle(int degrees);
    void setForce(int newton);

signals:
    void angleChanged(int);
    void forceChanged(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    QRect cannonRect() const;

    int ang;
    int f;
};

#endif // CANNON_H
