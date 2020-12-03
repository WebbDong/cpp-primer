#include <iostream>

#include "Person.h"

/**
 * const成员
 *      被const修饰的成员变量、非静态成员函数
 *
 *      1、const成员变量：
 *          必须初始化（类内部初始化），可以在声明的时候直接初始化赋值
 *          非static的const成员变量还可以在初始化列表中初始化、
 *
 *      2、const成员函数（非静态）
 *          const关键字写在参数列表后面，函数的声明和实现都必须带const
 *          内部不能修改非static成员变量
 *          内部只能调用const成员函数、static成员函数
 *          非const成员函数可以调用const成员函数
 *          const成员函数和非const成员函数构成重载
 *          非const对象（指针）优先调用非const成员函数
 *          const对象（指针）只能调用const成员函数、static成员函数
 * @return
 */
int main() {
    std::cout << dwb::Person::staticConstNumber << std::endl;

    dwb::Person p1("Adam");
    p1.constFunc();
    p1.func();

    dwb::Person* pPerson1 = new dwb::Person("John");
    pPerson1->constFunc();
    pPerson1->func();
    delete pPerson1;

    const dwb::Person constP1("Lisa");
    constP1.constFunc();
    // 不能调用
//    constP1.func();

    const dwb::Person* pConstPerson1 = new dwb::Person("Harden");
    pConstPerson1->constFunc();
    // 不能调用
//    pConstPerson1->func();
    delete pConstPerson1;
    return 0;
}
