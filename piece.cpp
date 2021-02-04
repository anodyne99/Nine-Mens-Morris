#include "piece.h"

Piece::Piece(int x, int y, bool white, bool movable)
{
    rect = QRectF(x, y, 25, 25);
    setFlag(QGraphicsItem::ItemIsMovable, movable);
    whitepc = white;
}

void Piece::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
{
    return rect;
}
