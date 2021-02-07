#include "game.h"

Game::Game(QGraphicsScene * scene)
{
    whiteTurn = true;
    turnNumber = 0;
    unsigned int i;

    //Adding board widget to scene
    scene->addWidget(new Board);

    //Adding spaces
    spaceList.push_back(new Space(90,640)); //Space A1
    spaceList.push_back(new Space(90,340)); //Space A4
    spaceList.push_back(new Space(90,40)); //Space A7
    spaceList.push_back(new Space(190,540)); //Space B2
    spaceList.push_back(new Space(190,340)); //Space B4
    spaceList.push_back(new Space(190,140)); //Space B6
    spaceList.push_back(new Space(290,440)); //Space C3
    spaceList.push_back(new Space(290,340)); //Space C4
    spaceList.push_back(new Space(290,240)); //Space C5
    spaceList.push_back(new Space(390,640)); //Space D1
    spaceList.push_back(new Space(390,540)); //Space D2
    spaceList.push_back(new Space(390,440)); //Space D3
    spaceList.push_back(new Space(390,240)); //Space D5
    spaceList.push_back(new Space(390,140)); //Space D6
    spaceList.push_back(new Space(390,40)); //Space D7
    spaceList.push_back(new Space(490,440)); //Space E3
    spaceList.push_back(new Space(490,340)); //Space E4
    spaceList.push_back(new Space(490,240)); //Space E5
    spaceList.push_back(new Space(590,540)); //Space F2
    spaceList.push_back(new Space(590,340)); //Space F4
    spaceList.push_back(new Space(590,140)); //Space F6
    spaceList.push_back(new Space(690,640)); //Space G1
    spaceList.push_back(new Space(690,340)); //Space G4
    spaceList.push_back(new Space(690,40)); //Space G7

    for (i = 0; i < spaceList.size(); i++) {
        spaceList[i]->setZValue(90);
        scene->addItem(spaceList[i]);
    }

    //Adding white pieces
    whitePieces.push_back(new Piece(100, 750));
    whitePieces.push_back(new Piece(150, 750));
    whitePieces.push_back(new Piece(200, 750));
    whitePieces.push_back(new Piece(250, 750));
    whitePieces.push_back(new Piece(300, 750));
    for (i = 0; i < whitePieces.size(); i++) {
        whitePieces[i]->setZValue(100);
        scene->addItem(whitePieces[i]);
    }

    //Adding black pieces
    blackPieces.push_back(new Piece(475,750, false));
    blackPieces.push_back(new Piece(525,750, false));
    blackPieces.push_back(new Piece(575,750, false));
    blackPieces.push_back(new Piece(625,750, false));
    blackPieces.push_back(new Piece(675,750, false));
    for (i = 0; i < blackPieces.size(); i++) {
        blackPieces[i]->setZValue(100);
        scene->addItem(blackPieces[i]);
    }

    //Selecting first piece
    selectPiece(turnNumber, whiteTurn);

}

void Game::selectPiece(int pieceNumber, bool white)
/*Select a piece*/
{
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        if (white) {
            connect(spaceList[i], SIGNAL(clicked(QRectF, Space*)), whitePieces[pieceNumber], SLOT(moved(QRectF, Space*)));
            connect(whitePieces[pieceNumber], SIGNAL(turnTaken()), this, SLOT(nextTurn()));
        }
        else {
            connect(spaceList[i], SIGNAL(clicked(QRectF, Space*)), blackPieces[pieceNumber], SLOT(moved(QRectF, Space*)));
            connect(blackPieces[pieceNumber], SIGNAL(turnTaken()), this, SLOT(nextTurn()));
        }
    }
}

void Game::deselectPiece(int pieceNumber, bool white)
/*Deselect a piece*/
{
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        if (white) {
            disconnect(spaceList[i], SIGNAL(clicked(QRectF, Space*)), whitePieces[pieceNumber], SLOT(moved(QRectF, Space*)));
            disconnect(whitePieces[pieceNumber], SIGNAL(turnTaken()), this, SLOT(nextTurn()));
        }
        else {
            disconnect(spaceList[i], SIGNAL(clicked(QRectF, Space*)), blackPieces[pieceNumber], SLOT(moved(QRectF, Space *)));
            disconnect(blackPieces[pieceNumber], SIGNAL(turnTaken()), this, SLOT(nextTurn()));
        }
    }
}

void Game::nextTurn()
/*Slot to change the player turn after a move*/
{
    deselectPiece(turnNumber, whiteTurn);
    if (!whiteTurn) {
        turnNumber = (turnNumber + 1) % 5; //Will need to change for number of pieces
    }
    whiteTurn = !whiteTurn;
    selectPiece(turnNumber, whiteTurn);
}
