#include <ClickHandler.h>
#include <QMessageLogger>


enum eFigure {
    RECTANGLE,
    CIRCLE,
    FIG_NUMBER
};


FiguresManager::FiguresManager() {
    figures = new std::vector<Figure*>();
}

void FiguresManager::addNewFigure(int xCenter, int yCenter) {
    int type = rand() % FIG_NUMBER;
    eFigure figure = static_cast<eFigure>(type);
    Figure* newFigure = nullptr;
    switch(figure) {
    case RECTANGLE : {
        newFigure = new Rectangle(xCenter, yCenter, rand() % MAX_WIDTH, rand() % MAX_HEIGHT);
        break;
    }
    case CIRCLE : {
        int radius = rand() % MAX_RADIUS;
        newFigure = new Ellipse(xCenter, yCenter, radius*2, radius*2);
        break;
    }
    default :{
        throw std::exception();
    }
    }

    figures->push_back(newFigure);
}

void FiguresManager::deleteFigure(int xClick, int yClick) {
    QMessageLogger* logger = new QMessageLogger();
    std::vector<Figure*>::iterator it;
    it = figures->begin();
    while(it != figures->end()) {
        Figure* i = *it;
        if(i->isPointInFigure(xClick, yClick)) {
            figures->erase(it);
            logger->debug("del");
        }else{
            ++it;
        }
    }
    logger->debug("------");
}

std::vector<Figure*>* FiguresManager::getFigures() {
    return figures;
}
