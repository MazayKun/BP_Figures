#include <Ellipse.h>
#include <Representer.h>
#include <cmath>

Coordinates Ellipse::getDrawPoint() {
    return Coordinates(xCenter - width/2, yCenter - height/2);
}

Ellipse::Ellipse(int xCenter, int yCenter, int width, int height) {
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->width = width;
    this->height = height;
}

void Ellipse::drawFigure(Representer *representer) {
    representer->draw(this);
}

bool Ellipse::isPointInFigure(int x, int y) {
    return (pow((x-xCenter),2) + pow((y-yCenter),2)) <= pow(width/2, 2);
}

