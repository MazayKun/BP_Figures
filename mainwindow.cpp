#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    representer = new Representer();
    figuresManager = new FiguresManager();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent* paint_event) {

    representer->representFigures(this, figuresManager->getFigures());

    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event) {
    if (mouse_event->button() == Qt::LeftButton) {
        figuresManager->addNewFigure(mouse_event->windowPos().x(), mouse_event->windowPos().y());
        repaint();
    }
    else if (mouse_event->button() == Qt::RightButton) {
        figuresManager->deleteFigure(mouse_event->windowPos().x(), mouse_event->windowPos().y());
        repaint();
    }

    QMainWindow::mousePressEvent(mouse_event);
}
