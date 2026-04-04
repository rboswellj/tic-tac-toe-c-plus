#ifndef PLAYER2D_H
#define PLAYER2D_H

#include "Player.h"
#include "Board2D.h"

class Player2D : public Player {
public:
    Player2D(std::string name, char symbol);
    virtual void makeMove(Board2D& board) = 0;
    virtual ~Player2D() = default;
};

#endif