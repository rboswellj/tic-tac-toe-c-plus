#ifndef GAME2D_H
#define GAME2D_H

#include "Game.h"
#include "Board2D.h"

class Game2D : public Game {
private:
    Board2D board;

    void humanMove();
    void computerMove();

public:
    Game2D();
    void play() override;
};

#endif
