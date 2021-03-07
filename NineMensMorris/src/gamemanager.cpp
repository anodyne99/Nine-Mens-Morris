#include "include/gamemanager.h"

GameManager::GameManager(){
    /*setting up the menu scene*/
    Menu menu(&menuScene);

    view.resize(800,800);
    view.setScene(&menuScene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    connect(menu.returnPushButton(),SIGNAL(clicked()),this,SLOT(switchTwoPlayerMode()));
}

void GameManager::switchTwoPlayerMode()
{
    /* instantiating the game class and scene*/
    game = new Game(&gameScene);
    view.setScene(&gameScene);
}
