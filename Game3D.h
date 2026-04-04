#ifndef GAME3D_H
#define GAME3D_H

#include "Game.h"
#include "Board3D.h"
#include "Player3D.h"

class Game3D : public Game {
private:
    Board3D board;
    Player3D* humanPlayer;
    Player3D* computerPlayer;

public:
    Game3D();
    void play() override;
    ~Game3D();
};

#endif