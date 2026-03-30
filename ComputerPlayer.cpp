#include <iostream>
#include <cstdlib>
#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(string name, char symbol)
    : Player(name, symbol) {
}

void ComputerPlayer::makeMove(Board& board) {
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(row, col));

    cout << name << " chooses row " << (row + 1)
         << ", column " << (col + 1) << endl;

    board.placeMove(row, col, symbol);
}