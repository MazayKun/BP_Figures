#include <Rectangle.h>
#include <Representer.h>

Coordinates Rectangle::getDrawPoint() {
    return Coordinates(xCenter - width/2, yCenter - height/2);
}

Rectangle::Rectangle(int xCenter, int yCenter, int width, int height) {
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->width = width;
    this->height = height;
}

void Rectangle::drawFigure(Representer* representer) {
    representer->draw(this);
}

bool Rectangle::isPointInFigure(int x, int y) {
    return (x >= xCenter - width/2) && (x <= xCenter + width/2) && (y >= yCenter - height/2) && (y <= yCenter + height/2);
}
