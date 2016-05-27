#include "button.h"

QIcon Button::icon_flag;
QIcon Button::icon_blank;

QIcon Button::icon_check;
QIcon Button::icon_check1;
QIcon Button::icon_test;

MainWindow * Button::mainwindow;
Board * Button::board;


// detect mouse release
void Button::mouseReleaseEvent(QMouseEvent *e)
{
   // mainwindow->setClick();

   if (e->button() == Qt::LeftButton){
        board->leftClickSquare(x, y);
    }
}

Button::Button(int i, int j, QWidget *parent)
    : QPushButton(parent)
{
    x = i;
    y = j;
}

Button::~Button()
{
}
