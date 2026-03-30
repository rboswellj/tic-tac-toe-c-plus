#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Board::display() const {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << " " << grid[i][0] << " | " << grid[i][1] << " | " << grid[i][2] << endl;
        if (i < 2) {
            cout << "---+---+---" << endl;
        }
    }
    cout << endl;
}

bool Board::placeMove(int row, int col, char symbol) {
    if (grid[row][col] != ' ') {
        return false;
    }

    grid[row][col] = symbol;
    return true;
}

bool Board::checkWin(char symbol) const {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
            return true;
        }
    }

    // check diagonals
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return true;
    }

    return false;
}

bool Board::checkDraw() const {
    // loop through rows
    for (int i = 0; i < 3; i++) {
        // loop through columns
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool Board::isCellEmpty(int row, int col) const {
    return grid[row][col] == ' ';
}