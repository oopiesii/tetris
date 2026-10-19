//
// Created by Polina Stupak on 13.10.2026.
//


#ifndef ASSIGNMENT3_POINT_H
#define ASSIGNMENT3_POINT_H

class Point {
    public:
        Point(int x = 0, int y = 0);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
    private:
        int x;
        int y;
};

#endif // ASSIGNMENT3_POINT_H


