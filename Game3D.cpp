#include <iostream>
#include "Game3D.h"
#include "HumanPlayer3D.h"
#include "ComputerPlayer3D.h"

Game3D::Game3D() : Game() {
    humanPlayer = new HumanPlayer3D("Human", humanSymbol);
    computerPlayer = new ComputerPlayer3D("Computer", computerSymbol);
}

Game3D::~Game3D() {
    delete humanPlayer;
    delete computerPlayer;
}

void Game3D::play() {
    // Start each round with a fresh board while keeping the running score.
    board = Board3D();
    decideFirstPlayer();

    std::cout << "\nStarting 3D Tic-Tac-Toe...\n";
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
