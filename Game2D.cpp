#include <iostream>
#include <cstdlib>
#include <limits>
#include "Game2D.h"

Game2D::Game2D() : Game() {
}

void Game2D::humanMove() {
    int row, col;

    while (true) {
        row = getValidatedInput("Enter row (1-3): ", 1, 3);
        col = getValidatedInput("Enter column (1-3): ", 1, 3);

        row--;
        col--;

        if (!board.placeMove(row, col, humanSymbol)) {
            std::cout << "Illegal move. That cell is already occupied." << std::endl;
        }
        else {
            break;
        }
    }
}

void Game2D::computerMove() {
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(row, col));

    std::cout << "Computer chooses row " << (row + 1)
              << ", column " << (col + 1) << std::endl;

    board.placeMove(row, col, computerSymbol);
}

void Game2D::play() {
    board = Board2D();   // reset board
    decideFirstPlayer();

    std::cout << "\nStarting 2D Tic-Tac-Toe..." << std::endl;
    std::cout << (humanTurn ? "Human goes first!" : "Computer goes first!") << std::endl;

    board.display();

    while (true) {
        if (humanTurn) {
            humanMove();

            board.display();

            if (board.checkWin(humanSymbol)) {
                std::cout << "Human wins!" << std::endl;
                humanWins++;
                break;
            }
        }
        else {
            computerMove();

            board.display();

            if (board.checkWin(computerSymbol)) {
                std::cout << "Computer wins!" << std::endl;
                computerWins++;
                break;
            }
        }

        if (board.checkDraw()) {
            std::cout << "It's a draw!" << std::endl;
            draws++;
            break;
        }

        humanTurn = !humanTurn;
    }

    displayScore();
}