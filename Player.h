#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    char symbol;

public:
    Player(std::string name, char symbol);
    std::string getName() const;
    char getSymbol() const;
    virtual ~Player() = default;
};

#endif