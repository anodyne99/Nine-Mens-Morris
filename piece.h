#ifndef PIECE_H
#define PIECE_H

#include "space.h"

#include <QGraphicsItem>
#include <QPainter>

class Piece : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Piece(int x, int y, bool white = true);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    QRectF boundingRect() const;
private:
    QRectF rect;
    Space * inSpace;
    bool whitepc;
    bool inPlay;
signals:
    void turnTaken();
private slots:
    void moved(QRectF rect, Space * space);
};

#endif // PIECE_H
