#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Figure.h>

using Coordinates = std::pair<int, int>;

class Representer;

class Rectangle : public Figure {
public:

    Rectangle(int xCenter, int yCenter, int width, int height);

    Coordinates getDrawPoint();

    void drawFigure(Representer* representer);

    bool isPointInFigure(int x, int y);
};

#endif // RECTANGLE_H
