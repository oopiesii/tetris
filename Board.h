//
// Created by Polina Stupak on 13.10.2026.
//

#ifndef ASSIGNMENT3_BOARD_H
#define ASSIGNMENT3_BOARD_H
#include <vector>
#include "Point.h"
#include "Tetromino.h"

class Board {
    public:
        Board(int width = 10, int height = 20);
        bool couldBePlaced(const Tetromino& t);
        void blockToBoard(const Tetromino& t);
        int ClearFullLines();
        bool isOccupied(int row, int col);
        Color getColor(int row, int col);
    private:
        std::vector<std::vector<Cell>> cells;
        int width = 0;
        int height = 0;
};

#endif //ASSIGNMENT3_BOARD_H
