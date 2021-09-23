#ifndef MYWIDGET2_H
#define MYWIDGET2_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QFont>
#include <QVBoxLayout>
#include <QApplication>
#include <QSpinBox>
class MyWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget2(QWidget *parent = nullptr);

signals:

};

#endif // MYWIDGET2_H
