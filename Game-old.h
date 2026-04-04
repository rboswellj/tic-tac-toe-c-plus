#ifndef GAME_H
#define GAME_H

#include "Board2D.h"
#include "Player.h"

class Game {
private:
    Board2D board;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

public:
    Game();
    void play();
    ~Game();
};

#endif
