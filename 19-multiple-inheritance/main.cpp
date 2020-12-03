#include <iostream>

#include "Person.h"
#include "Undergraduate.h"

/**
 * 多继承
 *      1、C++允许一个类可以有多个父类（不建议使用，会增加程序设计复杂度）
 *      2、如果子类继承的多个父类都有虚函数，那么子类对象就会产生对应的多张虚表
 *
 * 菱形继承
 *      定义：两个子类继承同一个父类，另一个子类又同时继承这两个子类
 *
 *      菱形继承带来的问题：
 *          1、最底下子类从基类继承的成员变量冗余、重复
 *          2、最底下子类无法访问基类的成员，有二义性
 *          3、基类指针指向最底下子类也会产生二义性
 *          4、最底下子类的构造函数也无法调用基类的构造函数
 *
 * 虚继承
 *      1、虚继承可以解决菱形继承带来的问题
 *      2、Person类被称为虚基类
 * @return
 */
int main() {
    dwb::Person* person1 = new dwb::Undergraduate("Conner", 31, 185, 96.5, 900, 2);
    person1->sayHello();
    person1->run();
    delete person1;

    std::cout << std::endl;

    {
        dwb::Undergraduate undergraduate("Adam", 30, 180, 98.5, 1000, 3);
        undergraduate.sayHello();
        undergraduate.run();
        undergraduate.work();
        undergraduate.study();
        undergraduate.dissert();
    }
    return 0;
}
