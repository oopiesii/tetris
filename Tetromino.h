//
// Created by Polina Stupak on 13.10.2026.
//

#ifndef ASSIGNMENT3_TETROMINO_H
#define ASSIGNMENT3_TETROMINO_H
#include <array>
#include "Point.h"

enum class TetrominoType {J, L, O, I, S, Z, T, Count};

class Tetromino {
    public:
        Tetromino(TetrominoType tetrominoType);
        void moveleft();
        void moveright();
        void movedown();
        void rotate();
        bool isEmpty(int row, int col) const;
        TetrominoType getType() const;
        Point getPosition() const;
        std::array<Point, 4> getCells() const;
        void setColor();
        Color getColor() const;
        bool fits(int x, int y);
        bool couldBePlaced(const Tetromino& t);

    private:
        std::array<Point, 4> cells;
        TetrominoType tetrominoType;
        int rotation;
        int shape[4][4]{};
        Point position;
        void rotate90();
        void rotate180();
        void rotate270();
        void clearShape();
        void setShape();
        Color color;

};
#endif //ASSIGNMENT3_TETROMINO_H
