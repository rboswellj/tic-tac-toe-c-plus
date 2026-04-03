#include <iostream>
#include <limits>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(string name, char symbol)
    : Player(name, symbol) {
}

void HumanPlayer::makeMove(Board2D& board) {
    int row, col;

    while (true) {
        while (true) {
            cout << name << ", enter row (1-3): ";
            cin >> row;
            if (validateInput(row)) {
                break;
            }
        }

        while (true) {
            cout << name << ", enter column (1-3): ";
            cin >> col;
            if (validateInput(col)) {
                break;
            }    
        }

        row--;
        col--;

        if (!board.isCellEmpty(row, col)) {
            cout << "Illegal move. That cell is already occupied." << endl;
        }
        else {
            board.placeMove(row, col, symbol);
            break;
        }
    }
}

bool HumanPlayer::validateInput(int move){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return false;
    }
    else if (move < 1 || move > 3) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a value between 1 and 3." << endl;
        return false;
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
}
