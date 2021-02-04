#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsItem>
#include <QPainter>

class Piece : public QGraphicsItem
{
public:
    Piece(int x, int y, bool white = true, bool movable = true);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    QRectF boundingRect() const;
private:
    QRectF rect;
    bool whitepc;
};

#endif // PIECE_H
