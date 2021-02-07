#include "piece.h"

Piece::Piece(int x, int y, bool white)
{
    rect = QRectF(x, y, 30, 30);
    whitepc = white;
    inPlay = false;
    inSpace = nullptr;
}

void Piece::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
/*Overloading function for appearance*/
{
    if (whitepc) {
        painter->setBrush(Qt::white);
    }
    else {
        painter->setBrush(Qt::black);
    }
    painter->drawEllipse(rect);
}

QRectF Piece::boundingRect() const
/*Overloading virtual function*/
{
    return rect;
}

void Piece::moved(QRectF rect, Space * space)
/*Slot to move piece when space clicked and signal turn taken*/
{
    if (inPlay) {
        inSpace->set_occupied(false);
    }
    else {
        inPlay = true;
    }
    inSpace = space;
    space->set_occupied(true);
    setPos(rect.x() / 2 - 2.5, rect.y() / 2 - 2.5);
    this->rect = QRectF(rect.x() / 2 - 2.5, rect.y() / 2 - 2.5, 30, 30);
    update();
    emit turnTaken();
}
