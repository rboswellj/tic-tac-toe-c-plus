#include <iostream>
#include <limits>
#include "HumanPlayer2D.h"

HumanPlayer2D::HumanPlayer2D(std::string name, char symbol)
    : Player2D(name, symbol) {
}

void HumanPlayer2D::makeMove(Board2D& board) {
    int row, col;

    while (true) {
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

        row--;
        col--;

        // Reject the move if another piece is already there.
        if (!board.placeMove(row, col, symbol)) {
            std::cout << "Illegal move. That cell is already occupied." << std::endl;
        }
        else {
            break;
        }
    }
}
