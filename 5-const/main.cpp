#include <iostream>

struct Date {
    int year;
    int month;
    int day;
};

/**
    Const
        1、修饰变量，让其成为常量
        2、如果修饰的是类的变量、结构体的变量、结构体的指针变量，其成员不可以修改
 * @return
 */
int main() {
    const int age = 20;

    Date d1 = {2011, 2, 5};
    Date d2 = {2013, 4, 5};
    const Date d3 = d1;
    d3 = d2;
    d3.year = 2020;
    d3.month = 2;
    d3.day = 5;

    const Date* p1 = &d1;
    p1->year = 2013;
    (*p1).month = 8;
    *p1 = d2;
    p1 = &d2;

    Date* const p2 = &d2;
    p2->year = 2013;
    (*p2).month = 8;
    *p2 = d3;
    p2 = &d3;

    const Date* const p3 = &d3;
    p3->year = 2013;
    (*p3).month = 8;
    *p3 = d1;
    p3 = &d1;
    return 0;
}
