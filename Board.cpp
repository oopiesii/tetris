//
// Created by Polina Stupak on 13.10.2026.
//

#include "Board.h"
#include <iostream>

Board :: Board(int width, int height) : width(width), height(height), table(height, std::vector<Point>(width)){}
bool Board::couldBePlaced(const Tetromino& t) {
    for (const Point& p: t.getCells()) {
        int x = p.getX();
        int y = p.getY();
        if (x < 0 || x >= height || y < 0 || y >= width) {
            return false;
        }
        if (table[x][y].isOccupied()) {
            return false;
        }
    }
    return true;
}

void Board::blockToBoard(const Tetromino& t) {
    for (const Point& p: t.getCells()) {
        int x = p.getX();
        int y = p.getY();
        table[x][y].setFilled(true);
        table[x][y].color = t.getColor();
    }
}

int Board::ClearFullLines() {
    int quantity = 0;
    for (int i = height - 1; i >= 0;) {
        int lines = 0;
        for (Point& p: table[i]) {
            if (p.isOccupied()) {
                lines++;
            }
        }
        if (lines == width) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < width ; j++) {
                    table[k] = table[k - 1];
                }
            }
            table[0] = std::vector<Point>(width);         
            quantity++;
        }
        else {
            i--;
        }
    }
    return quantity;
}