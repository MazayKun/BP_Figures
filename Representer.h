#ifndef REPRESENTER_H
#define REPRESENTER_H

#include <QPainter>
#include <Figure.h>
#include <Rectangle.h>
#include <Ellipse.h>
#include <vector>
#include <QtWidgets/QWidget>
#include <iostream>

using Coordinates = std::pair<int, int>;

class Representer {
public:
    Representer();

    ~Representer();

    void representFigures(QWidget* widget, std::vector<Figure*> *figures);

    void draw(Ellipse* ellipse);

    void draw(Rectangle* rectangle);

    void RepresentLine(const Coordinates& first_point, const Coordinates& last_point);

    void RepresentCircle(const Coordinates& center, unsigned int radius);

    void RepresentRectangle(const Coordinates &left_top, unsigned int width, unsigned int height);

private:
    QPainter* painter;
};



#endif // REPRESENTER_H
