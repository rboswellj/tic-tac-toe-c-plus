#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::string name, char symbol);
    void makeMove(Board& board) override;
private:
    bool findWinningMove(Board& board, char testSymbol, int& row, int& col);
};

#endif