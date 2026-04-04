#include <iostream>
#include <cstdlib>
#include "ComputerPlayer3D.h"

ComputerPlayer3D::ComputerPlayer3D(std::string name, char symbol)
    : Player3D(name, symbol) {
}

bool ComputerPlayer3D::findWinningMove(Board3D& board, char testSymbol, int& layer, int& row, int& col) {
    for (int l = 0; l < 3; l++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board.isCellEmpty(l, r, c)) {
                    // Test the move on a copy so the real board stays unchanged.
                    Board3D tempBoard = board;

                    tempBoard.placeMove(l, r, c, testSymbol);

                    if (tempBoard.checkWin(testSymbol)) {
                        layer = l;
                        row = r;
                        col = c;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void ComputerPlayer3D::makeMove(Board3D& board) {
    int layer, row, col;

    // Take a winning move immediately when one is available.
    if (findWinningMove(board, symbol, layer, row, col)) {
        std::cout << name << " wins at board " << (layer + 1)
                  << ", row " << (row + 1)
                  << ", column " << (col + 1) << std::endl;

        board.placeMove(layer, row, col, symbol);
        return;
    }

    // Otherwise, block the opponent's winning move.
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';

    if (findWinningMove(board, opponentSymbol, layer, row, col)) {
        std::cout << name << " blocks at board " << (layer + 1)
                  << ", row " << (row + 1)
                  << ", column " << (col + 1) << std::endl;

        board.placeMove(layer, row, col, symbol);
        return;
    }

    // Fall back to a random empty cell when no tactical move exists.
    do {
        layer = rand() % 3;
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.isCellEmpty(layer, row, col));

    std::cout << name << " chooses board " << (layer + 1)
              << ", row " << (row + 1)
              << ", column " << (col + 1) << std::endl;

    board.placeMove(layer, row, col, symbol);
}
