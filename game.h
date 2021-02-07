#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "piece.h"
#include "board.h"

#include <vector>
#include <QObject>
#include <QGraphicsScene>

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QGraphicsScene * scene);

    std::vector<Space*> spaceList;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;

    bool whiteTurn;
    int turnNumber;

    void selectPiece(int pieceNumber, bool white);
    void deselectPiece(int pieceNumber, bool white);

signals:

private slots:
    void nextTurn();

};

#endif // GAME_H
