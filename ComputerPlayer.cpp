#include <iostream>
#include <cstdlib>
#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(string name, char symbol)
    : Player(name, symbol) {
}

void ComputerPlayer::makeMove(Board& board) {
    int row, col;

    // 2. Try to block the human
    char humanSymbol = (symbol == 'X') ? 'O' : 'X';

    if (findWinningMove(board, humanSymbol, row, col)) {
        std::cout << name << " blocks at row " << (row + 1)
                  << ", column " << (col + 1) << std::endl;
        board.placeMove(row, col, symbol);
        return;
    }

    // 3. Otherwise choose random
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(row, col));

    std::cout << name << " chooses row " << (row + 1)
              << ", column " << (col + 1) << std::endl;

    board.placeMove(row, col, symbol);
}

bool ComputerPlayer::findWinningMove(Board& board, char testSymbol, int& row, int& col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.isCellEmpty(i, j)) {
                board.setCell(i, j, testSymbol);

                if (board.checkWin(testSymbol)) {
                    board.setCell(i, j, ' ');
                    row = i;
                    col = j;
                    return true;
                }

                board.setCell(i, j, ' ');
            }
        }
    }

    return false;
}