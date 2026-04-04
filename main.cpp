#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Game3D.h"
#include "Game2D.h"

int menu() {
    std::cout << "Welcome to the Game Hub!" << std::endl;
    std::cout << "1. Play 2D Tic-Tac-Toe" << std::endl;
    std::cout << "2. Play 3D Tic-Tac-Toe (Work in Progress)" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int choice;
    do {
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;
        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice < 1 || choice > 3);

    return choice;
}

int main() {
    std::srand(std::time(0));
    while (true) {
        int choice = menu();
        if (choice == 3) {
            std::cout << "Thank you for playing! Goodbye!" << std::endl;
            break;
        }

        // Use the shared Game interface so the menu can launch either mode.
        Game* game = nullptr;
        if (choice == 1) {
            game = new Game2D();
        } else if (choice == 2) {
            game = new Game3D();
        }

        if (game) {
            game->play();
            delete game;
        }
    }
}
