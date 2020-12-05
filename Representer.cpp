#include <Representer.h>

Representer::Representer(){

}

void Representer::representFigures(QWidget* widget, std::vector<Figure*> *figures) {
    painter = new QPainter(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(QBrush(QColor(0, 206, 209)));
    painter->setPen(QPen(Qt::black));
    for(auto fig : *figures) {
        fig->draw(this);
    }
    painter->end();
}

void  Representer::draw(Ellipse* ellipse){
    Coordinates center = ellipse->getDrawPoint();
    painter->drawEllipse(center.first, center.second, ellipse->getWidth(), ellipse->getHeight());
}

void  Representer::draw(Rectangle* rectangle){
    Coordinates left_top = rectangle->getDrawPoint();
    painter->drawRect(left_top.first, left_top.second, rectangle->getWidth(), rectangle->getHeight());
}



void Representer::RepresentLine(const Coordinates& first_point, const Coordinates& last_point) {
    painter->drawLine(first_point.first, first_point.second, last_point.first, last_point.second);
}

void Representer::RepresentCircle(const Coordinates& center, unsigned int radius) {
    painter->drawEllipse(center.first - radius, center.second - radius, 2*radius, 2*radius);
}

void Representer::RepresentRectangle(const Coordinates &left_top, unsigned int width, unsigned int height) {
    painter->drawRect(left_top.first, left_top.second, width, height);
}
