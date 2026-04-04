#ifndef HUMANPLAYER3D_H
#define HUMANPLAYER3D_H

#include "Player3D.h"

class HumanPlayer3D : public Player3D {
public:
    HumanPlayer3D(std::string name, char symbol);
    void makeMove(Board3D& board) override;
};

#endif