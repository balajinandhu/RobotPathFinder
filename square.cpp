#include "square.h"
#include <qpainter.h>
#include <qpixmap.h>


Square::Square()
{
    isFlipped = false;
}

// This method will flip the square.

void Square::flip()
{
    isFlipped = true;
    Button::icon_test = QIcon(QPixmap(":/res/image/num0.png"));
    Button::icon_test.addPixmap(QPixmap(":/res/image/num0.png"),QIcon::Disabled);
    mb->setIcon(Button::icon_test);

}


Button* Square::getButton(){
    return mb;
}

