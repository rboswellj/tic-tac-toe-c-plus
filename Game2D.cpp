#include <iostream>
#include "Game2D.h"
#include "HumanPlayer2D.h"
#include "ComputerPlayer2D.h"

Game2D::Game2D() : Game() {
    humanPlayer = new HumanPlayer2D("Human", humanSymbol);
    computerPlayer = new ComputerPlayer2D("Computer", computerSymbol);
}

Game2D::~Game2D() {
    delete humanPlayer;
    delete computerPlayer;
}

void Game2D::play() {
    // Start each round with a fresh board while keeping the running score.
    board = Board2D();
    decideFirstPlayer();

    std::cout << "\nStarting 2D Tic-Tac-Toe...\n";
    std::cout << (humanTurn ? "Human goes first!\n" : "Computer goes first!\n");

    board.display();

    while (true) {
        if (humanTurn) {
            humanPlayer->makeMove(board);
            board.display();

            if (board.checkWin(humanPlayer->getSymbol())) {
                std::cout << humanPlayer->getName() << " wins!\n";
                humanWins++;
                break;
            }
        }
        else {
            computerPlayer->makeMove(board);
            board.display();

            if (board.checkWin(computerPlayer->getSymbol())) {
                std::cout << computerPlayer->getName() << " wins!\n";
                computerWins++;
                break;
            }
        }

        if (board.checkDraw()) {
            std::cout << "It's a draw!\n";
            draws++;
            break;
        }

        // Alternate turns after a round where no winner was found.
        humanTurn = !humanTurn;
    }

    displayScore();
}
