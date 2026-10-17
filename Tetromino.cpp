//
// Created by Polina Stupak on 13.10.2026.
//

#include "Tetromino.h"

#include <iostream>
#include <ostream>
Tetromino::Tetromino(TetrominoType tetrominoType): tetrominoType(tetrominoType),rotation(0),position(0, 3) {setShape();setColor();}
void Tetromino::clearShape() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            shape[i][j] = 0;
}
TetrominoType Tetromino::getType() const {
    return tetrominoType;
}

void Tetromino::setShape() {
    clearShape();
    switch(tetrominoType) {
        case TetrominoType::T:
            shape[2][3] = 1;
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::O:
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[1][1] = 1;
            break;
        case TetrominoType::I:
            shape[2][0] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            shape[2][3] = 1;
            break;

        case TetrominoType::J:
            shape[0][2] = 1;
            shape[1][2] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::L:
            shape[0][1] = 1;
            shape[1][1] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::S:
            shape[1][2] = 1;
            shape[1][3] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::Z:
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            shape[2][3] = 1;
            break;
    }
}
bool Tetromino::isEmpty(int row, int col) const {
    return shape[row][col] == 0;
}
void Tetromino::rotate90() {
    clearShape();
    switch(tetrominoType) {
        case TetrominoType::T:
            shape[2][3] = 1;
            shape[2][2] = 1;
            shape[3][2] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::O:
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[1][1] = 1;
            break;
        case TetrominoType::I:
            shape[0][2] = 1;
            shape[2][2] = 1;
            shape[1][2] = 1;
            shape[3][2] = 1;
            break;
        case TetrominoType::L:
            shape[1][1] = 1;
            shape[1][3] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::J:
            shape[2][2] = 1;
            shape[1][1] = 1;
            shape[2][1] = 1;
            shape[2][3] = 1;
            break;

        case TetrominoType::S:
            shape[1][1] = 1;
            shape[3][2] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::Z:
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            shape[3][1] = 1;
            break;
    }
}
void Tetromino::rotate180() {
    clearShape();
    switch(tetrominoType) {
        case TetrominoType::T:
            shape[2][3] = 1;
            shape[2][2] = 1;
            shape[3][2] = 1;
            shape[2][1] = 1;
            break;
        case TetrominoType::O:
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[1][1] = 1;
            break;
        case TetrominoType::I:
            shape[2][0] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            shape[2][3] = 1;
            break;

        case TetrominoType::J:
            shape[0][1] = 1;
            shape[0][2] = 1;
            shape[1][1] = 1;
            shape[2][1] = 1;
            break;
        case TetrominoType::L:
            shape[0][1] = 1;
            shape[0][2] = 1;
            shape[2][2] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::S:
            shape[1][2] = 1;
            shape[1][3] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::Z:
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            shape[2][3] = 1;
            break;
    }
}
void Tetromino::rotate270() {
    clearShape();
    switch(tetrominoType) {
        case TetrominoType::T:
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[3][2] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::O:
            shape[2][2] = 1;
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[1][1] = 1;
            break;
        case TetrominoType::I:
            shape[0][2] = 1;
            shape[2][2] = 1;
            shape[1][2] = 1;
            shape[3][2] = 1;
            break;

        case TetrominoType::J:
            shape[1][3] = 1;
            shape[1][1] = 1;
            shape[2][3] = 1;
            shape[1][2] = 1;
            break;
        case TetrominoType::L:
            shape[2][3] = 1;
            shape[1][3] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::S:
            shape[1][1] = 1;
            shape[3][2] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;
        case TetrominoType::Z:
            shape[2][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            shape[3][1] = 1;
            break;
    }
}
void Tetromino::rotate() {
    rotation = (rotation + 1) % 4;
    switch (rotation) {
        case 0: setShape();   break;
        case 1: rotate90();   break;
        case 2: rotate180();  break;
        case 3: rotate270();  break;
    }
}
void Tetromino::moveleft() {
    position.setY(position.getY() - 1);
}
void Tetromino::moveright() {
    position.setY(position.getY() + 1);
}
void Tetromino::movedown() {
    position.setX(position.getX() + 1);
}
std::array<Point, 4> Tetromino::getCells() const {
    std::array<Point, 4> result;
    int k = 0;
    int firstRow = 0;
    while (firstRow < 4) {
        bool found = false;
        for (int j = 0; j < 4; ++j) {
            if (!isEmpty(firstRow, j)) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
        ++firstRow;
    }
    for (int i = firstRow; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!isEmpty(i, j)) {
                result[k++] = Point(
                    position.getX() + i - firstRow,
                    position.getY() + j
                );
            }
        }
    }
    return result;
}
void Tetromino::setColor() {
    switch(tetrominoType) {
        case TetrominoType::T:
            color = Color::Purple;
            break;
        case TetrominoType::O:
            color = Color::Yellow;
            break;
        case TetrominoType::I:
            color = Color::Cyan;
            break;
        case TetrominoType::J:
            color = Color::Blue;
            break;
        case TetrominoType::L:
            color = Color::Orange;
            break;
        case TetrominoType::S:
            color = Color::Green;
            break;
        case TetrominoType::Z:
            color = Color::Red;
            break;
    }
}
Color Tetromino::getColor() const {
    return color;
}
