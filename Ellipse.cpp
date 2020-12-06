#include <Ellipse.h>
#include <Representer.h>
#include <cmath>


Ellipse::Ellipse(int xCenter, int yCenter, int width, int height) {
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->width = width;
    this->height = height;
}

Ellipse* Ellipse::createCircle(int xCenter, int yCenter, int radius) {
    Ellipse* newEllipse = new Ellipse(xCenter, yCenter, radius*2, radius*2);
    return newEllipse;
}

void Ellipse::drawFigure(Representer *representer) {
    representer->draw(this);
}

Coordinates Ellipse::getDrawPoint() {
    return Coordinates(xCenter - width/2, yCenter - height/2);
}

bool Ellipse::isPointInFigure(int x, int y) {
    // Хотел использовать каноническое уравнение эллипса, но
    // оно не будет работать с int
    return (pow((x-xCenter),2) + pow((y-yCenter),2)) <= pow(width/2, 2);
}

