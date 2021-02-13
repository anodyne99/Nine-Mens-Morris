#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "piece.h"
#include "board.h"

#include <vector>
#include <QObject>
#include <QGraphicsScene>

class Game : public QObject {
    Q_OBJECT
public:
    Game(QGraphicsScene * scene);

    std::vector<Space*> spaceList;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;

    int getSpaceIndex(Space *space);
    void setAdjacentSpaces(Piece *piece, bool value);
    void setAllSpaceValidity(bool value);

    void selectPiece(Piece * piece);
    void deselectPiece(Piece * piece);
    void enableSelectPiece();
    void disableSelectPiece();

private:
    bool whiteTurn;
    int turnNumber;

    bool phaseOneComplete;
    bool whiteFlying;
    bool blackFlying;

    std::vector<std::vector<int>> adjacentList;

signals:

private slots:
    void pieceSelectAction(Piece *piece);
    void nextTurn(Piece *piece);

};

#endif // GAME_H
