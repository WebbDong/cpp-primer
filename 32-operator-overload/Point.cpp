//
// Created by WebbDong on 9/1/2020.
//
#include <iostream>

#include "Point.h"

namespace dwb {

    // 全局+运算符重载函数实现
    const Point operator+(const Point& p1, const Point& p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    Point::Point(float x, float y) : x(x), y(y) {}

    void Point::display() {
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }

    // 减法运算符重载成员函数实现
    /*
    const Point Point::operator-(const Point& p) const {
        return Point(this->x - p.x, this->y - p.y);
    }
    */

    const Point operator-(const Point& p1, const Point& p2) {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    std::ostream& operator<<(std::ostream& cout, const Point& p) {
        cout << "(" << p.x << ", " << p.y << ")";
        return cout;
    }

    std::istream& operator>>(std::istream& cin, Point& p) {
        std::cout << "输入属性x: ";
        cin >> p.x;
        std::cout << "输入属性y: ";
        cin >> p.y;
        return cin;
    }

    const Point Point::operator*(const Point &p) const {
        return Point(this->x * p.x, this->y * p.y);
    }

    const Point Point::operator/(const Point &p) const {
        return Point(this->x / p.x, this->y / p.y);
    }

    bool Point::operator==(const Point &p) const {
        return (this->x == p.x) && (this->y == p.y);
    }

    bool Point::operator!=(const Point &p) const {
        return (this->x != p.x) || (this->y != p.y);
    }

    const Point Point::operator-() const {
        return Point(-this->x, -this->y);
    }

    Point& Point::operator+=(const Point& p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    Point& Point::operator-=(const Point& p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }

    Point& Point::operator++() {
        this->x++;
        this->y++;
        return *this;
    }

    Point Point::operator++(int) {
        Point old(this->x, this->y);
        this->x++;
        this->y++;
        return old;
    }

    Point& Point::operator--() {
        this->x--;
        this->y--;
        return *this;
    }

    Point Point::operator--(int) {
        Point old(this->x, this->y);
        this->x--;
        this->y--;
        return old;
    }

    float Point::operator[](int index) const {
        return index == 0 ? this->x : this->y;
    }

    /*
    Point& Point::operator=(const Point& p) {
        this->x = p.x;
        return *this;
    }
     */

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