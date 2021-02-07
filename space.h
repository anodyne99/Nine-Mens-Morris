#ifndef SPACE_H
#define SPACE_H

#include <QGraphicsItem>
#include <QPainter>

class Space : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Space(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);

    bool check_occupied() {return occupied;}
    void set_occupied(bool val) {occupied = val;}
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
    bool hover;
    bool occupied;
    QRectF rect;
signals:
    void clicked(QRectF rect, Space * space);
};

#endif // SPACE_H
