#ifndef HUMANPLAYER2D_H
#define HUMANPLAYER2D_H

#include "Player2D.h"

class HumanPlayer2D : public Player2D {
public:
    HumanPlayer2D(std::string name, char symbol);
    void makeMove(Board2D& board) override;
};

#endif