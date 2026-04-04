#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
protected:
    int humanWins;
    int computerWins;
    int draws;

    char humanSymbol;
    char computerSymbol;

    bool humanTurn;

    void decideFirstPlayer();
    int getValidatedInput(const std::string& prompt, int min, int max);

public:
    Game();
    virtual void play() = 0;
    void displayScore() const;
    virtual ~Game() = default;
};

#endif