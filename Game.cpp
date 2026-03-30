#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

Game::Game() {
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

Game::~Game() {
    delete player1;
    delete player2;
}

void Game::play() {
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