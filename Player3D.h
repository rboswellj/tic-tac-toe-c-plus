#ifndef PLAYER3D_H
#define PLAYER3D_H

#include "Player.h"
#include "Board3D.h"

class Player3D : public Player {
public:
    Player3D(std::string name, char symbol);
    virtual void makeMove(Board3D& board) = 0;
};

#endif