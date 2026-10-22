//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_CELL_H
#define ASSIGNMENT3_CELL_H
#include "Color.h"


class Cell {
public:
    Cell(Color color);
    void setColor(Color color);
    Color getColor() const;
private:
    Color color = Color::None;
};


#endif //ASSIGNMENT3_CELL_H
