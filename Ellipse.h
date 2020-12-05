#ifndef CIRCLE_H
#define CIRCLE_H

#include <Figure.h>

using Coordinates = std::pair<int, int>;

class Representer;

class Ellipse : public Figure {
public:
    Ellipse(int xCenter, int yCenter, int width, int height);

    Coordinates getDrawPoint();

    void drawFigure(Representer *representer);

    bool isPointInFigure(int x, int y);

};

#endif // CIRCLE_H
