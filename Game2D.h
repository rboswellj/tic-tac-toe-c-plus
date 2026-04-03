#ifndef GAME2D_H
#define GAME2D_H

#include "Board2D.h"
#include "Player.h"

class Game2D {
private:
    Board2D board;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

public:
    Game2D();
    void play();
    ~Game2D();
};

#endif
