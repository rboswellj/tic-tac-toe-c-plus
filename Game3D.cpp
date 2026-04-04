#include <iostream>
#include <cstdlib>
#include <limits>
#include "Game3D.h"

Game3D::Game3D() : Game() {
}

void Game3D::humanMove() {
    int layer, row, col;

    while (true) {
        layer = getValidatedInput("Enter board (1-3): ", 1, 3);
        row = getValidatedInput("Enter row (1-3): ", 1, 3);
        col = getValidatedInput("Enter column (1-3): ", 1, 3);

        layer--;
        row--;
        col--;

        if (!board.placeMove(layer, row, col, humanSymbol)) {
            std::cout << "Illegal move. That cell is already occupied." << std::endl;
        }
        else {
            break;
        }
    }
}

void Game3D::computerMove() {
    int layer, row, col;

    do {
        layer = rand() % 3;
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(layer, row, col));

    std::cout << "Computer chooses board " << (layer + 1)
              << ", row " << (row + 1)
              << ", column " << (col + 1) << std::endl;

    board.placeMove(layer, row, col, computerSymbol);
}

void Game3D::play() {
    board = Board3D();
    decideFirstPlayer();

    std::cout << "\nStarting 3D Tic-Tac-Toe...\n";
    std::cout << (humanTurn ? "Human goes first!\n" : "Computer goes first!\n");

    board.display();

    while (true) {
        if (humanTurn) {
            humanMove();
            board.display();

            if (board.checkWin(humanSymbol)) {
                std::cout << "Human wins!\n";
                humanWins++;
                break;
            }
        }
        else {
            computerMove();
            board.display();

            if (board.checkWin(computerSymbol)) {
                std::cout << "Computer wins!\n";
                computerWins++;
                break;
            }
        }

        if (board.checkDraw()) {
            std::cout << "It's a draw!\n";
            draws++;
            break;
        }

        humanTurn = !humanTurn;
    }

    displayScore();
}