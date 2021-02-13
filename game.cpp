#include "game.h"

Game::Game(QGraphicsScene * scene) {
    whiteTurn = true;
    turnNumber = 0;
    phaseOneComplete = false;
    whiteFlying = false;
    blackFlying = false;
    unsigned int i;

    //Adding board widget to scene
    scene->addWidget(new Board);

    //Adding spaces
    spaceList.push_back(new Space(90,640));  //Space A1
    spaceList.push_back(new Space(90,340));  //Space A4
    spaceList.push_back(new Space(90,40));   //Space A7
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
    spaceList.push_back(new Space(390,40));  //Space D7
    spaceList.push_back(new Space(490,440)); //Space E3
    spaceList.push_back(new Space(490,340)); //Space E4
    spaceList.push_back(new Space(490,240)); //Space E5
    spaceList.push_back(new Space(590,540)); //Space F2
    spaceList.push_back(new Space(590,340)); //Space F4
    spaceList.push_back(new Space(590,140)); //Space F6
    spaceList.push_back(new Space(690,640)); //Space G1
    spaceList.push_back(new Space(690,340)); //Space G4
    spaceList.push_back(new Space(690,40));  //Space G7

    for (i = 0; i < spaceList.size(); i++) {
        spaceList[i]->setZValue(90);
        scene->addItem(spaceList[i]);
    }

    //Vector with indices of adjacent spaces
    adjacentList = { {1,9}, {0,2,4}, {1,14}, {4,10}, {1,3,5,7}, {4,13},
                     {7,11}, {4,6,8}, {7,12}, {0,10,21}, {3,9,11,18}, {6,10,15},
                     {8,13,17}, {5,12,14,20}, {2,13,23}, {11,16}, {15,17,19}, {12,16},
                     {10,19}, {16,18,20,22}, {13,19}, {9,22}, {19,21,23}, {14,22} };

    //Adding white pieces
    whitePieces.push_back(new Piece(100, 720));
    whitePieces.push_back(new Piece(150, 720));
    whitePieces.push_back(new Piece(200, 720));
    whitePieces.push_back(new Piece(250, 720));
    whitePieces.push_back(new Piece(300, 720));
    whitePieces.push_back(new Piece(125, 760));
    whitePieces.push_back(new Piece(175, 760));
    whitePieces.push_back(new Piece(225, 760));
    whitePieces.push_back(new Piece(275, 760));
    for (i = 0; i < whitePieces.size(); i++) {
        whitePieces[i]->setZValue(100);
        scene->addItem(whitePieces[i]);
    }

    //Adding black pieces
    blackPieces.push_back(new Piece(475, 720, false));
    blackPieces.push_back(new Piece(525, 720, false));
    blackPieces.push_back(new Piece(575, 720, false));
    blackPieces.push_back(new Piece(625, 720, false));
    blackPieces.push_back(new Piece(675, 720, false));
    blackPieces.push_back(new Piece(500, 760, false));
    blackPieces.push_back(new Piece(550, 760, false));
    blackPieces.push_back(new Piece(600, 760, false));
    blackPieces.push_back(new Piece(650, 760, false));
    for (i = 0; i < blackPieces.size(); i++) {
        blackPieces[i]->setZValue(100);
        scene->addItem(blackPieces[i]);
    }

    //Selecting first piece
    selectPiece(whitePieces[0]);

}

int Game::getSpaceIndex(Space *space) {
/*Returns index of given space in list of spaces*/
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        if (spaceList[i] == space)
            return i;
    }
    return -1;
}

void Game::setAdjacentSpaces(Piece *piece, bool value) {
/*Sets adjacent spaces to piece as valid or invalid move*/
    unsigned int i;
    int index = getSpaceIndex(piece->getSpace());
    for (i = 0; i < adjacentList[index].size(); i++) {
        spaceList[adjacentList[index][i]]->setValid(value);
    }
}

void Game::setAllSpaceValidity(bool value) {
/*Sets all spaces as valid or invalid move*/
    unsigned int i;
    for (i = 0; i < spaceList.size(); i++) {
        spaceList[i]->setValid(value);
    }
}

void Game::selectPiece(Piece *piece) {
/*Selects a piece*/
    unsigned int i;
    connect(piece, SIGNAL(turnTaken(Piece*)), this, SLOT(nextTurn(Piece*)));
    for (i = 0; i < spaceList.size(); i++) {
        connect(spaceList[i], SIGNAL(clicked(Space*)), piece, SLOT(moved(Space*)));
    }
    piece->setSelected(true);
    piece->update();
}

void Game::deselectPiece(Piece *piece) {
/*Deselects a piece*/
    unsigned int i;
    disconnect(piece, SIGNAL(turnTaken(Piece*)), this, SLOT(nextTurn(Piece*)));
    for (i = 0; i < spaceList.size(); i++) {
        disconnect(spaceList[i], SIGNAL(clicked(Space*)), piece, SLOT(moved(Space*)));
    }
    piece->setSelected(false);
    piece->update();
}

void Game::enableSelectPiece() {
/*Allows one side's pieces to be selected*/
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            connect(whitePieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            whitePieces[i]->setSelectable(true);
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            connect(blackPieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            blackPieces[i]->setSelectable(true);
        }
    }
}

void Game::disableSelectPiece() {
/*Disables piece selection for a side*/
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            disconnect(whitePieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            whitePieces[i]->setSelectable(false);
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            disconnect(blackPieces[i], SIGNAL(clickSelect(Piece*)), this, SLOT(pieceSelectAction(Piece*)));
            blackPieces[i]->setSelectable(false);
        }
    }
}

void Game::pieceSelectAction(Piece *piece) {
/*Slot for action taken when selectable piece clicked*/
    unsigned int i;
    if (whiteTurn) {
        for (i = 0; i < whitePieces.size(); i++) {
            if (whitePieces[i]->isSelected()) {
                deselectPiece(whitePieces[i]);
                setAdjacentSpaces(whitePieces[i], false);
            }
        }
    } else {
        for (i = 0; i < blackPieces.size(); i++) {
            if (blackPieces[i]->isSelected()) {
                deselectPiece(blackPieces[i]);
                setAdjacentSpaces(blackPieces[i], false);
            }
        }
    }
    selectPiece(piece);
    setAdjacentSpaces(piece, true);
}

void Game::nextTurn(Piece *piece) {
/*Slot to change the player turn after a move*/
    deselectPiece(piece);
    //PHASE ONE: Placing pieces
    if (!phaseOneComplete) {
        if (!whiteTurn)
            turnNumber++;
        whiteTurn = !whiteTurn;
        if (turnNumber < 9) {
            if (whiteTurn) {
                selectPiece(whitePieces[turnNumber]);
            } else {
                selectPiece(blackPieces[turnNumber]);
            }
        } else {
            phaseOneComplete = true;
            setAllSpaceValidity(false);
            enableSelectPiece();
        }
    //PHASE TWO: Moving pieces
    } else {
        setAdjacentSpaces(piece, false);
        disableSelectPiece();
        if (!whiteTurn)
            turnNumber++;
        whiteTurn = !whiteTurn;
        enableSelectPiece();
    }
}
