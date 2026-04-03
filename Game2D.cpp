#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game2D.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

Game2D::Game2D() {
    srand(time(0));

    player1 = new HumanPlayer("Player", 'X');
    player2 = new ComputerPlayer("Computer", 'O');

    // randomly choose who goes first
    if (rand() % 2 == 0) {
        currentPlayer = player1;
        cout << "Player goes first!" << endl;
    } else {
        currentPlayer = player2;
        cout << "Computer goes first!" << endl;
    }
}

Game2D::~Game2D() {
    delete player1;
    delete player2;
}

void Game2D::play() {
    board.display();

    while (true) {
        currentPlayer->makeMove(board);

        board.display();

        if (board.checkWin(currentPlayer->getSymbol())) {
            cout << currentPlayer->getName() << " wins!" << endl;
            break;
        }

        if (board.checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        // switch players
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }
}
