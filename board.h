#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QPainter>

class Board : public QWidget
{
    Q_OBJECT

public:
    Board();
    virtual void paintEvent(QPaintEvent * event);


};
#endif // BOARD_H
