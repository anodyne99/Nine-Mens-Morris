#include "board.h"
#include "piece.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view;
    Board w;

    //Create pieces
    Piece white1(100,750);
    Piece white2(150,750);
    Piece white3(200,750);
    Piece white4(250,750);
    Piece white5(300,750);

    Piece black1(475,750, false);
    Piece black2(525,750, false);
    Piece black3(575,750, false);
    Piece black4(625,750, false);
    Piece black5(675,750, false);

    //Add board and pieces to scene
    scene.addWidget(&w);

    scene.addItem(&white1);
    scene.addItem(&white2);
    scene.addItem(&white3);
    scene.addItem(&white4);
    scene.addItem(&white5);

    scene.addItem(&black1);
    scene.addItem(&black2);
    scene.addItem(&black3);
    scene.addItem(&black4);
    scene.addItem(&black5);

    view.resize(800,800);
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view.show();
    return a.exec();
}
