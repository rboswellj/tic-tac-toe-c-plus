#ifndef GAME2D_H
#define GAME2D_H

#include "Game.h"
#include "Board2D.h"
#include "Player2D.h"

class Game2D : public Game {
private:
    Board2D board;
    Player2D* humanPlayer;
    Player2D* computerPlayer;

public:
    Game2D();
    void play() override;
    ~Game2D();
};

#endif