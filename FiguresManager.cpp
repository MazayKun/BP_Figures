#include <FiguresManager.h>


enum eFigure {
    RECTANGLE,
    CIRCLE,
    FIG_NUMBER
};


FiguresManager::FiguresManager() {
    figures = new std::vector<Figure*>();
}

FiguresManager::~FiguresManager() {
    for (auto ptr : *figures) {
        delete ptr;
    }
    delete figures;
}


void FiguresManager::addNewFigure(int xCenter, int yCenter) {
    Figure* newFigure = generateFigure(xCenter, yCenter);
    figures->push_back(newFigure);
}

void FiguresManager::deleteFigure(int xClick, int yClick) {
    std::vector<Figure*>::iterator it;
    it = figures->begin();
    while(it != figures->end()) {
        Figure* i = *it;
        if(i->isPointInFigure(xClick, yClick)) {
            figures->erase(it);
        }else{
            ++it;
        }
    }
}

std::vector<Figure*>* FiguresManager::getFigures() {
    return figures;
}

Figure* FiguresManager::generateFigure(int xCenter, int yCenter) {
    int type = rand() % FIG_NUMBER;
    eFigure figure = static_cast<eFigure>(type);
    Figure* newFigure = nullptr;

    switch(figure) {
        case RECTANGLE : {
            int width = rand() % MAX_WIDTH;
            int height = rand() % MAX_HEIGHT;
            newFigure = new Rectangle(xCenter, yCenter, width, height);
            break;
        }
        case CIRCLE : {
            int radius = rand() % MAX_RADIUS;
            newFigure = Ellipse::createCircle(xCenter, yCenter, radius);
            break;
        }
        default :{
            throw "Bad figure type";
        }
    }
    return newFigure;
}
