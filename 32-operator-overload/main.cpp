#include <iostream>

#include "Point.h"
#include "Person.h"
#include "Student.h"
#include "Sum.h"

/**
 * 运算符重载
 *      1、运算符重载（操作符重载）：可以为运算符增加一些新的功能
 *      2、全局函数、成员函数都支持运算符重载
 *      3、有些运算符不可以被重载，比如：
 *          对象成员访问运算符 .
 *          域运算符 ::
 *          三目运算符  ?:
 *          sizeof
 *          预处理符号： #
 *          成员指针访问运算符  .* 和 ->*
 *      4、有些运算符只能重载为成员函数，比如：
 *          赋值运算符 =
 *          下标运算符 []
 *          函数运算符 ()
 *          指针访问成员 ->
 *      5、仿函数（函数对象）
 *          仿函数：将一个对象当作一个函数一样来使用，重写()运算符来实现
 *          对比普通函数，它作为对象可以保存状态
 * @return
 */
int main() {
    dwb::Person person1("Adam", 45);
    dwb::Person person2("Conner", 40);
    std::cout << "(person1 >= person2) = " << (person1 >= person2) << std::endl;
    std::cout << "(person1 <= person2) = " << (person1 <= person2) << std::endl;
    std::cout << "(person1 > person2) = " << (person1 > person2) << std::endl;
    std::cout << "(person1 < person2) = " << (person1 < person2) << std::endl;

    dwb::Student student1("Lisa", 30, 90);
    dwb::Student student2;
    student2 = student1;
    student2.display();

    dwb::Sum sum;
    const int a = 30;
    const int b = 40;
    // 仿函数
    std::cout << "sum(30, 40) = " << sum(a, b) << std::endl;

    const dwb::Point p1(10, 20);
    dwb::Point p2(40, 60);
    dwb::Point p3(20, 20);
    dwb::Point p4 = p1 + p2 + p3;
    p4.display();

    dwb::Point p5 = p1 * p3;
    p5.display();

    dwb::Point p6 = p3 - p2 - p1;
    p6.display();

    dwb::Point p7 = p2 / p3 / p1;
    p7.display();

    std::cout << "(p1 == p2) = " << (p1 == p2) << std::endl;
    std::cout << "(p1 != p2) = " << (p1 != p2) << std::endl;

    dwb::Point p8 = -p2;
    p8.display();

    p3 += dwb::Point(60, 60);
    p3.display();

    p3 -= dwb::Point(10, 10);
    p3.display();

    ++p3;
    p3.display();

    dwb::Point old = p3++;
    old.display();
    p3.display();

    dwb::Point p9(70, 80);
    p9--;
    --p9;
    p9.display();

    std::cout << p9[0] << "----" << p9[1] << std::endl;
    std::cout << p1 << p2 << p3 << p8 << ", 123" << 456 << std::endl;

    dwb::Point p10(10, 20);
    dwb::Point p11(50, 60);
    p10 = p11;
    p10.display();

    dwb::Point p12;
    std::cin >> p12;
    std::cout << p12;
    return 0;
}
