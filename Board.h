#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char grid[3][3];

public:
    char getCell(int row, int col) const;
    void setCell(int row, int col, char value);
    bool checkWin(char symbol) const;
    bool checkDraw() const;
    bool isCellEmpty(int row, int col) const;
    Board();
    void display() const;
    bool placeMove(int row, int col, char symbol);
};

#endif