//
// Created by Polina Stupak on 13.10.2026.
//

#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const { return x; }

int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }

void Point::setY(int y) { this->y = y; }


bool Point::isOccupied() const { return filled; }

void Point::setFilled(bool filled) { this->filled = filled; }