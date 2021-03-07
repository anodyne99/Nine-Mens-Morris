#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include "include/game.h"
#include "include/button.h"

class Menu : public QObject{
    Q_OBJECT
private:
    Button* twoPlayers;
    QPushButton* twoPlayerButton;
public:
    QGraphicsScene* scene;
    Menu(QGraphicsScene *scene);
    void mainMenuScreen();
    QPushButton *returnPushButton() {return twoPlayerButton;}
protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void buttonClicked();

};

#endif // MENU_H
