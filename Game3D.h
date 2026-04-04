#ifndef GAME3D_H
#define GAME3D_H

#include "Game.h"
#include "Board3D.h"

class Game3D : public Game {
private:
    Board3D board;

    void humanMove();
    void computerMove();

public:
    Game3D();
    void play() override;
};

#endif