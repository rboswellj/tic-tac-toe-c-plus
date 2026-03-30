#include <iostream>
#include <string>
#include "Board.h"

using namespace std;


int main() {
    Board b;
    int row, col;
    

    b.display();

    b.placeMove(0, 0, 'X');
    b.placeMove(1, 1, 'O');

    b.display();

    return 0;
}

