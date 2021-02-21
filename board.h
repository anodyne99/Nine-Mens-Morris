#ifndef BOARD_H
#define BOARD_H

#include <QPainter>
#include <QMainWindow>

class Board : public QWidget {

public:
    Board();
    virtual void paintEvent(QPaintEvent * event);

};
#endif // BOARD_H
