#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsItem>
#include <QPainter>

class Piece : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Piece(int x, int y, bool white = true, bool movable = true);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    QRectF boundingRect() const;
private:
    QRectF rect;
    bool whitepc;
signals:
    void turnTaken();
private slots:
    void moved(QRectF rect);
};

#endif // PIECE_H
