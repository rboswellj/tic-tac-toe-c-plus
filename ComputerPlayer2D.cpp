#include <iostream>
#include <cstdlib>
#include "ComputerPlayer2D.h"

ComputerPlayer2D::ComputerPlayer2D(std::string name, char symbol)
    : Player2D(name, symbol) {
}

bool ComputerPlayer2D::findWinningMove(Board2D& board, char testSymbol, int& row, int& col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.isCellEmpty(i, j)) {
                // Test the move on a copy so the real board stays unchanged.
                Board2D tempBoard = board;

                tempBoard.placeMove(i, j, testSymbol);

                if (tempBoard.checkWin(testSymbol)) {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
    }

    return false;
}

void ComputerPlayer2D::makeMove(Board2D& board) {
    int row, col;

    // Take a winning move immediately when one is available.
    if (findWinningMove(board, symbol, row, col)) {
        std::cout << name << " wins at row " << (row + 1)
                  << ", column " << (col + 1) << std::endl;
        board.placeMove(row, col, symbol);
        return;
    }

    // Otherwise, block the opponent's winning move.
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';

    if (findWinningMove(board, opponentSymbol, row, col)) {
        std::cout << name << " blocks at row " << (row + 1)
                  << ", column " << (col + 1) << std::endl;
        board.placeMove(row, col, symbol);
        return;
    }

    // Fall back to a random empty cell when no tactical move exists.
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(row, col));

    std::cout << name << " chooses row " << (row + 1)
              << ", column " << (col + 1) << std::endl;

    board.placeMove(row, col, symbol);
}
