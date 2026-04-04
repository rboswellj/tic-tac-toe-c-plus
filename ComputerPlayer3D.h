#ifndef COMPUTERPLAYER3D_H
#define COMPUTERPLAYER3D_H

#include "Player3D.h"

class ComputerPlayer3D : public Player3D {
private:
    bool findWinningMove(Board3D& board, char testSymbol, int& layer, int& row, int& col);

public:
    ComputerPlayer3D(std::string name, char symbol);
    void makeMove(Board3D& board) override;
};

#endif