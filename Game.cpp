#include <iostream>
#include <limits>
#include <cstdlib>
#include "Game.h"

Game::Game()
    : humanWins(0), computerWins(0), draws(0),
      humanSymbol('X'), computerSymbol('O'),
      humanTurn(true) {
}

void Game::decideFirstPlayer() {
    // Randomize the opening turn so neither side always starts first.
    humanTurn = (rand() % 2 == 0);
}

void Game::displayScore() const {
    std::cout << "\nScore:" << std::endl;
    std::cout << "Human: " << humanWins << std::endl;
    std::cout << "Computer: " << computerWins << std::endl;
    std::cout << "Draws: " << draws << std::endl;
}

int Game::getValidatedInput(const std::string& prompt, int min, int max) {
    int value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            // Clear the failed state before asking again.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
        else if (value < min || value > max) {
            // Discard the rest of the line so the next prompt starts cleanly.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a value between "
                      << min << " and " << max << "." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
