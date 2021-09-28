#ifndef GAMEBRD_H
#define GAMEBRD_H

class QPushButton;
class LCDRange;
class QLCDNumber;
class CannonField;

#include "lcdrange.h"
#include "cannon.h"

#include <QWidget>

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    GameBoard(QWidget *parent = nullptr);

protected slots:
    void fire();
    void hit();
    void missed();
    void newGame();

private:
    QLCDNumber *hits;
    QLCDNumber *shotsLeft;
    CannonField *cannonField;
};

#endif // GAMEBRD_H
