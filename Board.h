#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char grid[3][3];

public:
    bool checkWin(char symbol) const;
    bool checkDraw() const;
    bool isCellEmpty(int row, int col) const;
    Board();
    void display() const;
    bool placeMove(int row, int col, char symbol);
};

#endif