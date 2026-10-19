//
// Created by Polina Stupak on 13.10.2026.
//

#include "Board.h"
#include <iostream>

Board :: Board(int width, int height) : width(width), height(height), cells(height, std::vector<Cell>(width, Cell(Color::None))){}
bool Board::couldBePlaced(const Tetromino& t) {
    for (const Point& p: t.getCells()) {
        int x = p.getX();
        int y = p.getY();
        if (x < 0 || x >= height || y < 0 || y >= width) {
            return false;
        }
        if (cells[x][y].getColor() == Color::None) {
            return false;
        }
    }
    return true;
}

void Board::blockToBoard(const Tetromino& t) {
    for (const Point& p: t.getCells()) {
        int x = p.getX();
        int y = p.getY();
        // cells[x][y].setFilled(true);
        cells[x][y].setColor(t.getColor());
    }
}

int Board::ClearFullLines() {
    int quantity = 0;
    for (int i = height - 1; i >= 0;) {
        int lines = 0;
        for (Cell& c: cells[i]) {
            if (c.getColor() != Color::None) {
                lines++;
            }
        }
        if (lines == width) {
            for (int k = i; k > 0; k--) {
                cells[k] = cells[k - 1];
            }
            cells[0] = std::vector<Cell>(width, Cell(Color::None));
            quantity++;
        }
        else {
            i--;
        }
    }
    return quantity;
}

bool Board::isOccupied(int row, int col)  {
    if (cells[row][col].getColor() == Color::None) {return false;}
    if (cells[row][col].getColor() != Color::None) {return true;}
}

Color Board::getColor(int row, int col)  {
    return cells[row][col].getColor();
}