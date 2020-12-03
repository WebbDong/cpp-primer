#include <iostream>

#include "Point.h"
#include "Math.h"

/*
namespace dwb {

    // 友元函数外部实现
    Point add2(Point p1, Point p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

}
 */

/**
 * 友元
 *      1、友元包括友元函数和友元类
 *      2、如果将函数A（非成员函数）声明为类C的友元函数，那么函数A就能直接访问类C对象的所有成员
 *      3、如果将类A声明为类C的友元类，那么类A的所有成员函数都能直接访问类C对象的所有成员
 *      4、友元破坏了面向对象的封装性，但在某些频繁访问成员变量的地方可以提高性能
 */
int main() {
    dwb::Point p1(10, 30);
    dwb::Point p2(50, 50);
    dwb::Point p3 = dwb::add2(p1, p2);
    p3.display();
    std::cout << std::endl;

    dwb::Point p4 = dwb::Math::add(p1, p2);
    p4.display();

    dwb::Point p5 = dwb::Math::subtraction(p1, p2);
    p5.display();

    dwb::Point p6 = dwb::Math::multiplication(p1, p2);
    p6.display();

    dwb::Point p7 = dwb::Math::division(p1, p2);
    p7.display();
    return 0;
}
