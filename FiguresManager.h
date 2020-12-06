#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

#include <Representer.h>
#include <Figure.h>
#include <Ellipse.h>
#include <Rectangle.h>
#include <cstdlib>
#include <iostream>


class FiguresManager {
public:
    FiguresManager();
    ~FiguresManager();

    void addNewFigure(int xCenter, int yCenter);

    void deleteFigure(int xClick, int yClick);

    std::vector<Figure*>* getFigures();

private:
    int MAX_WIDTH = 200;
    int MAX_HEIGHT = 200;
    int MAX_RADIUS = 200;

    std::vector<Figure*> *figures;

    Figure* generateFigure(int xCenter, int yCenter);
};

#endif // CLICKHANDLER_H
