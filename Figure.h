#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using Coordinates = std::pair<int, int>;

class Representer;

class Figure {
public:
    Figure() {}

    ~Figure() {}

    virtual Coordinates getDrawPoint()=0;

    virtual void drawFigure(Representer* representer)=0;

    virtual bool isPointInFigure(int x, int y)=0;

    int getHeight() {
        return height;
    }

    int getWidth() {
         return width;
    }

protected:
    int xCenter;
    int yCenter;
    int width;
    int height;
};

#endif // FIGURE_H
