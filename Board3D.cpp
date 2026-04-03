#include <iostream>
#include "Board3D.h"

Board3D::Board3D() {
    for (int layer = 0; layer < 3; layer++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                grid[layer][row][col] = ' ';
            }
        }
    }
}

bool Board3D::isCellEmpty(int layer, int row, int col) const {
    return grid[layer][row][col] == ' ';
}

bool Board3D::placeMove(int layer, int row, int col, char symbol) {
    if (!isCellEmpty(layer, row, col)) {
        return false;
    }

    grid[layer][row][col] = symbol;
    return true;
}

void Board3D::display() const {
    for (int layer = 0; layer < 3; layer++) {
        std::cout << "Board " << (layer + 1) << ":" << std::endl;

        for (int row = 0; row < 3; row++) {
            std::cout << " " << grid[layer][row][0]
                      << " | " << grid[layer][row][1]
                      << " | " << grid[layer][row][2] << std::endl;

            if (row < 2) {
                std::cout << "---+---+---" << std::endl;
            }
        }

        std::cout << std::endl;
    }
}

bool Board3D::checkDraw() const {
    for (int layer = 0; layer < 3; layer++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (grid[layer][row][col] == ' ') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board3D::checkWin(char symbol) const {
    // Check rows, columns, and diagonals in each layer
    for (int layer = 0; layer < 3; layer++) {
        for (int i = 0; i < 3; i++) {
            if (grid[layer][i][0] == symbol &&
                grid[layer][i][1] == symbol &&
                grid[layer][i][2] == symbol) {
                return true;
            }

            if (grid[layer][0][i] == symbol &&
                grid[layer][1][i] == symbol &&
                grid[layer][2][i] == symbol) {
                return true;
            }
        }

        if (grid[layer][0][0] == symbol &&
            grid[layer][1][1] == symbol &&
            grid[layer][2][2] == symbol) {
            return true;
        }

        if (grid[layer][0][2] == symbol &&
            grid[layer][1][1] == symbol &&
            grid[layer][2][0] == symbol) {
            return true;
        }
    }

    // Check vertical lines across layers
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[0][row][col] == symbol &&
                grid[1][row][col] == symbol &&
                grid[2][row][col] == symbol) {
                return true;
            }
        }
    }

    // Check diagonals across layers with fixed row
    for (int row = 0; row < 3; row++) {
        if (grid[0][row][0] == symbol &&
            grid[1][row][1] == symbol &&
            grid[2][row][2] == symbol) {
            return true;
        }

        if (grid[0][row][2] == symbol &&
            grid[1][row][1] == symbol &&
            grid[2][row][0] == symbol) {
            return true;
        }
    }

    // Check diagonals across layers with fixed column
    for (int col = 0; col < 3; col++) {
        if (grid[0][0][col] == symbol &&
            grid[1][1][col] == symbol &&
            grid[2][2][col] == symbol) {
            return true;
        }

        if (grid[0][2][col] == symbol &&
            grid[1][1][col] == symbol &&
            grid[2][0][col] == symbol) {
            return true;
        }
    }

    // Check full 3D space diagonals
    if (grid[0][0][0] == symbol &&
        grid[1][1][1] == symbol &&
        grid[2][2][2] == symbol) {
        return true;
    }

    if (grid[0][0][2] == symbol &&
        grid[1][1][1] == symbol &&
        grid[2][2][0] == symbol) {
        return true;
    }

    if (grid[0][2][0] == symbol &&
        grid[1][1][1] == symbol &&
        grid[2][0][2] == symbol) {
        return true;
    }

    if (grid[0][2][2] == symbol &&
        grid[1][1][1] == symbol &&
        grid[2][0][0] == symbol) {
        return true;
    }

    return false;
}