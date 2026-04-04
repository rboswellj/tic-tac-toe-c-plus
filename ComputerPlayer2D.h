#ifndef COMPUTERPLAYER2D_H
#define COMPUTERPLAYER2D_H

#include "Player2D.h"

class ComputerPlayer2D : public Player2D {
private:
    bool findWinningMove(Board2D& board, char testSymbol, int& row, int& col);

public:
    ComputerPlayer2D(std::string name, char symbol);
    void makeMove(Board2D& board) override;
};

#endif