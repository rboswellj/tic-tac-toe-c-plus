#include "Player.h"

Player::Player(std::string name, char symbol)
    : name(std::move(name)), symbol(symbol) {
}

std::string Player::getName() const {
    return name;
}

char Player::getSymbol() const {
    return symbol;
}
