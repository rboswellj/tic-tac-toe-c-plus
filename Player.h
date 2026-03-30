#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {
protected:
    std::string name;
    char symbol;

public:
    Player(std::string name, char symbol);
    virtual void makeMove(Board& board) = 0;

    std::string getName() const;
    char getSymbol() const;

    virtual ~Player() = default;
};

#endif