#ifndef BOARD3D_H
#define BOARD3D_H

class Board3D {
private:
    char grid[3][3][3];

public:
    Board3D();
    void display() const;
    bool isCellEmpty(int layer, int row, int col) const;
    bool placeMove(int layer, int row, int col, char symbol);
    bool checkDraw() const;
    bool checkWin(char symbol) const;
};

#endif