#ifndef SQUARE_H
#define SQUARE_H
#include "button.h"
#include<QLabel>

class Button;

class Square{
private:
    Button * mb;
    QLabel *text;
public:
    Square();
    bool isObstacle;
    bool isFlipped;     // Is it flipped?
   // int cost;
    void flip();
    void setButton(Button * mb);
    Button *getButton();
    void showMine();
};

inline void Square::setButton(Button *mb)
{
    this->mb = mb;
}

#endif // SQUARE_H
