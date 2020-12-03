//
// Created by WebbDong on 8/31/2020.
//

#include "Math.h"

namespace dwb {

    Point Math::add(Point p1, Point p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    Point Math::subtraction(Point p1, Point p2) {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    Point Math::multiplication(Point p1, Point p2) {
        return Point(p1.x * p2.x, p1.y * p2.y);
    }

    Point Math::division(Point p1, Point p2) {
        return Point(p1.x / p2.x, p1.y / p2.y);
    }

}