//
// Created by WebbDong on 8/31/2020.
//
#include <iostream>

#include "Point.h"

namespace dwb {

    // 友元函数实现
    dwb::Point add2(dwb::Point p1, dwb::Point p2) {
        return dwb::Point(p1.x + p2.x, p1.y + p2.y);
    }

    Point::Point(float x, float y) : x(x), y(y) {}

    void Point::display() const {
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }

    float Point::getX() const {
        return x;
    }

    void Point::setX(float x) {
        Point::x = x;
    }

    float Point::getY() const {
        return y;
    }

    void Point::setY(float y) {
        Point::y = y;
    }

}
