#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QFont>

#include <mywidget.h>
#include <lcdrange.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    //QVBoxLayout *layout = new QVBoxLayout(window);
    //layout->addWidget(button1);
    //layout->addWidget(button2);
    //layout->addWidget(button3);
    //layout->addWidget(button4);
    //layout->addWidget(button5);

    //window->show();

    MyWidget *w = new MyWidget(window);
    //w->show();
    w->setGeometry(100,100,500,355);
    window->show();
    return a.exec();
}
