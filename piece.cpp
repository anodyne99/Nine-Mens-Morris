#include "piece.h"

Piece::Piece(int x, int y, bool white) {
    rect = QRectF(x, y, 30, 30);
    setAcceptHoverEvents(true);
    whitePiece = white;
    hover = false;
    inPlay = false;
    inSpace = nullptr;
    selectEnabled = false;
    selected = false;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
/*Overloading function for appearance*/
    if (whitePiece) {
        painter->setBrush(Qt::white);
    } else {
        painter->setBrush(Qt::black);
    }
    if (selected)
        painter->setBrush(Qt::green);
    if (hover && selectEnabled) {
        painter->setPen(Qt::green);
    }
    painter->drawEllipse(rect);
}

QRectF Piece::boundingRect() const {
/*Overloading virtual function*/
    return rect;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
/*Action taken when piece clicked*/
    if (selectEnabled) {
        emit clicked(this);
    }
}

void Piece::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    hover = true;
    update();
}

void Piece::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    hover = false;
    update();
}

void Piece::moved(QRectF rect, Space *space) {
/*Slot to move piece when space clicked and signal turn taken*/
    if (inPlay) {
        inSpace->setOccupied(false);
    } else {
        inPlay = true;
    }
    inSpace = space;
    space->setOccupied(true);
    setPos(rect.x() / 2 - 2.5, rect.y() / 2 - 2.5);
    this->rect = QRectF(rect.x() / 2 - 2.5, rect.y() / 2 - 2.5, 30, 30);
    update();
    emit turnTaken(this);
}
