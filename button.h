#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QIcon>
#include <QMouseEvent>
#include "mainwindow.h"
#include "square.h"
#include "board.h"



class MainWindow;
class Board;
class Square;

class Button : public QPushButton
{
    Q_OBJECT

private:
    Square * square;
    int x;
    int y;

public:
    static QIcon icon_flag;
    static QIcon icon_blank;

    static QIcon icon_check;
    static QIcon icon_check1;
    static QIcon icon_test;

    static MainWindow * mainwindow;
    static Board * board;
    Button (int x, int y, QWidget *parent = 0);
    ~Button();
    void mouseReleaseEvent(QMouseEvent *e);
    void setSquare(Square * square);

};

inline void Button::setSquare(Square * square)
{
    this->square = square;
}


#endif // BUTTON_H
