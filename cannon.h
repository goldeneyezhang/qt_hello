#ifndef CANNON_H
#define CANNON_H

#include <QWidget>

class Cannon : public QWidget
{
    Q_OBJECT
public:
    explicit Cannon(QWidget *parent = nullptr);

    int angle() const {return ang;}
    QSizePolicy sizePolicy() const;

public slots:
    void setAngle(int degrees);

signals:
    void angleChanged(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    int ang;
};

#endif // CANNON_H
