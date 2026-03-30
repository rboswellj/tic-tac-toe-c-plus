#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
private:
    bool validateInput(int move);
public:
    HumanPlayer(std::string name, char symbol);
    void makeMove(Board& board) override;
    
};

#endif