//
// Created by Mir on 11/04/2022.
//

#include "Point.h"

int Point::lastX = 0;
int Point::lastY = 0;

Point::Point(int x, int y) : x(x), y(y) {
    lastX = x;
    lastY = y;
}

Point::Point() : Point(lastX + 1, lastY + 1) {
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
