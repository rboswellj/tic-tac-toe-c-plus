#include <iostream>
#include <limits>
#include "HumanPlayer3D.h"

HumanPlayer3D::HumanPlayer3D(std::string name, char symbol)
    : Player3D(name, symbol) {
}

void HumanPlayer3D::makeMove(Board3D& board) {
    int layer, row, col;

    while (true) {
        // Keep asking until we get a valid board number.
        while (true) {
            std::cout << name << ", enter board (1-3): ";
            std::cin >> layer;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            }
            else if (layer < 1 || layer > 3) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a value between 1 and 3." << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        // Keep asking until we get a valid row number.
        while (true) {
            std::cout << name << ", enter row (1-3): ";
            std::cin >> row;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            }
            else if (row < 1 || row > 3) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a value between 1 and 3." << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        // Keep asking until we get a valid column number.
        while (true) {
            std::cout << name << ", enter column (1-3): ";
            std::cin >> col;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            }
            else if (col < 1 || col > 3) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a value between 1 and 3." << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        layer--;
        row--;
        col--;

        // Reject the move if another piece is already there.
        if (!board.placeMove(layer, row, col, symbol)) {
            std::cout << "Illegal move. That cell is already occupied." << std::endl;
        }
        else {
            break;
        }
    }
}
