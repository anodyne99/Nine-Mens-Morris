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
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
    bool hover;
    QRectF rect;
signals:
    void clicked(QRectF rect);
};

#endif // SPACE_H
