#ifndef PIECE_H
#define PIECE_H

#include "space.h"

#include <QGraphicsItem>
#include <QPainter>

class Piece : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    Piece(int x, int y, bool white = true);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    QRectF boundingRect() const;

    void setSelectable(bool value) { selectEnabled = value; }
    void setSelected(bool value) { selected = value; }
    bool isSelected() { return selected; }
    Space *getSpace() { return inSpace; }
private:
    QRectF rect;
    Space *inSpace;
    bool whitePiece;
    bool hover;
    bool inPlay;
    bool selectEnabled;
    bool selected;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked(Piece *piece);
    void turnTaken(Piece *piece);
private slots:
    void moved(QRectF rect, Space * space);
};

#endif // PIECE_H
