#ifndef LCDRANGE_H
#define LCDRANGE_H


#include <QWidget>
class QSlider;
class QLabel;

class LCDRange:public QWidget
{
    Q_OBJECT
public:
    LCDRange(QWidget *parent=0);
    LCDRange(const char *s,QWidget *parent=0);

    int value() const;
    const QString text() const;

public slots:
    void setValue(int);
    void setRange(int minVal,int maxVal);
    void setText(const QString);

signals:
    void valueChanged(int);

private:
    void init();

    QSlider *slider;
    QLabel *label;
};

#endif // LCDRANGE_H
