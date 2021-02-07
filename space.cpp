#include "space.h"

Space::Space(int x, int y)
{
    rect = QRectF(x,y,20,20);
    setAcceptHoverEvents(true);
    hover = false;
    occupied = false;
}

QRectF Space::boundingRect() const
/*Overloading virtual function*/
{
    return rect;
}

void Space::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
/*Overloading function to implement appearance*/
{
    if (hover) {
        painter->setBrush(Qt::green);
    }
    painter->drawEllipse(rect);
}

void Space::mousePressEvent(QGraphicsSceneMouseEvent *event)
/*Signals mouse clicked on space*/
{
    if (!occupied) {
        emit clicked(rect, this);
    }
}

void Space::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
/*Changes appearance when mouse enters rect*/
{
    hover = true;
    update();
}

void Space::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
/*Reverts appearance when mouse leaves rect*/
{
    hover = false;
    update();
}
