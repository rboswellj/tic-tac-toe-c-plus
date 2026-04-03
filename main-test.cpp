#include <iostream>
#include "Board3D.h"

void printResult(const std::string& testName, bool result, bool expected) {
    std::cout << testName << ": ";

    if (result == expected) {
        std::cout << "PASS";
    } else {
        std::cout << "FAIL";
    }

    std::cout << " (got " << (result ? "true" : "false")
              << ", expected " << (expected ? "true" : "false") << ")\n";
}

int main() {
    // Test 1: row win in layer 0
    {
        Board3D board;
        board.placeMove(0, 0, 0, 'X');
        board.placeMove(0, 0, 1, 'X');
        board.placeMove(0, 0, 2, 'X');

        printResult("Layer row win", board.checkWin('X'), true);
    }

    // Test 2: column win in layer 1
    {
        Board3D board;
        board.placeMove(1, 0, 2, 'X');
        board.placeMove(1, 1, 2, 'X');
        board.placeMove(1, 2, 2, 'X');

        printResult("Layer column win", board.checkWin('X'), true);
    }

    // Test 3: diagonal win in layer 2
    {
        Board3D board;
        board.placeMove(2, 0, 0, 'X');
        board.placeMove(2, 1, 1, 'X');
        board.placeMove(2, 2, 2, 'X');

        printResult("Layer diagonal win", board.checkWin('X'), true);
    }

    // Test 4: vertical win across layers
    {
        Board3D board;
        board.placeMove(0, 1, 1, 'X');
        board.placeMove(1, 1, 1, 'X');
        board.placeMove(2, 1, 1, 'X');

        printResult("Vertical across layers", board.checkWin('X'), true);
    }

    // Test 5: cross-layer diagonal with fixed row
    {
        Board3D board;
        board.placeMove(0, 2, 0, 'X');
        board.placeMove(1, 2, 1, 'X');
        board.placeMove(2, 2, 2, 'X');

        printResult("Cross-layer diagonal fixed row", board.checkWin('X'), true);
    }

    // Test 6: cross-layer diagonal with fixed column
    {
        Board3D board;
        board.placeMove(0, 0, 1, 'X');
        board.placeMove(1, 1, 1, 'X');
        board.placeMove(2, 2, 1, 'X');

        printResult("Cross-layer diagonal fixed column", board.checkWin('X'), true);
    }

    // Test 7: full 3D space diagonal
    {
        Board3D board;
        board.placeMove(0, 0, 0, 'X');
        board.placeMove(1, 1, 1, 'X');
        board.placeMove(2, 2, 2, 'X');

        printResult("Full space diagonal", board.checkWin('X'), true);
    }

    // Test 8: no win
    {
        Board3D board;
        board.placeMove(0, 0, 0, 'X');
        board.placeMove(0, 0, 1, 'X');
        board.placeMove(1, 1, 1, 'X');

        printResult("No win", board.checkWin('X'), false);
    }

    return 0;
}