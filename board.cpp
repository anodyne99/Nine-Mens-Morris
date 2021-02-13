#include "board.h"


Board::Board() {
    resize(800,800);
}

void Board::paintEvent(QPaintEvent *event) {
/*Overloading virtual function to implement board appearance*/
    QPainter painter(this);

    painter.setBrush(QColor(200,200,115));
    painter.drawRect(QRect(50, 0, 700, 700));
    painter.drawRect(QRect(100, 50, 600, 600));
    painter.drawRect(QRect(200, 150, 400, 400));
    painter.drawRect(QRect(300, 250, 200, 200));
    painter.drawLine(100,350,300,350);
    painter.drawLine(500,350,700,350);
    painter.drawLine(400,50,400,250);
    painter.drawLine(400,450,400,650);

}



