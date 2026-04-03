#ifndef BOARD2D_H
#define BOARD2D_H

class Board2D {
private:
    char grid[3][3];

public:
    char getCell(int row, int col) const;
    void setCell(int row, int col, char value);
    bool checkWin(char symbol) const;
    bool checkDraw() const;
    bool isCellEmpty(int row, int col) const;
    Board2D();
    void display() const;
    bool placeMove(int row, int col, char symbol);
};

#endif
