#include <iostream>

#include "Person.h"
#include "SuperClass1.h"
#include "SuperClass2.h"
#include "InnerClass2.h"

/**
 * 内部类
 *      1、如果将类A定义在类C的内部，那么类A就是一个内部类（嵌套类）
 *      2、内部类的特点
 *          支持public、protected、private权限
 *          成员函数可以直接访问其外部类对象的所有成员（反过来则不行）
 *          成员函数可以直接不带类名、对象名访问其外部类的static成员
 *          不会影响外部类的内存布局
 *          可以在外部类内部声明，在外部类外面进行定义
 * @return
 */
int main() {
    dwb::Person p;
    p.display();

    dwb::Person::Car c1("Adam", 45);
    c1.display();

    dwb::SuperClass1 superClass1(80);
    std::cout << "superClass1.getNum() = " << superClass1.getNum() << std::endl;

    dwb::SuperClass1::InnerClass1 innerClass1("Adam");
    std::cout << "innerClass1.getName() = " << innerClass1.getName() << std::endl;

    dwb::SuperClass2 superClass2(50);
    std::cout << "superClass2.getNum() = " << superClass2.getNum() << std::endl;

    dwb::SuperClass2::InnerClass2 innerClass2("Conner");
    std::cout << "innerClass2.getName() = " << innerClass2.getName();
    return 0;
}
