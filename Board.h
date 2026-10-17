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
        std::vector<std::vector<Point>> table;
        bool couldBePlaced(const Tetromino& t);
        void blockToBoard(const Tetromino& t);
        int ClearFullLines();
    private:
        int width;
        int height;
};


#endif //ASSIGNMENT3_BOARD_H
