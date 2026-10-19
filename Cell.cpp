//
// Created by Polina Stupak on 19.10.2026.
//

#include "Cell.h"
Cell::Cell(Color colorn): color(colorn) {}

void Cell::setColor(Color setcolor)  { color = setcolor ; }

Color Cell::getColor()  { return color; }