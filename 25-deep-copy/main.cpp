#include <iostream>

#include "Person.h"
#include "Student.h"

/**
 * 浅拷贝、深拷贝
 *      1、编译器默认的提供的拷贝是浅拷贝（shallow copy）
 *          将一个对象中所有成员变量的值拷贝到另一个对象
 *          如果某个成员变量是个指针，只会拷贝指针中存储的地址值，并不会拷贝指针指向的内存空间
 *          可能会导致堆空间多次free的问题
 *      2、如果需要实现深拷贝（deep copy），就需要自定义拷贝构造函数
 *          将指针类型的成员变量所指向的内存空间，拷贝到新的内存空间
 * @return
 */
int main() {
    dwb::Person p1("Adam", 25, 185);
    p1.sayHello();

    dwb::Person p2(p1);
    p2.sayHello();
    std::cout << std::endl;

    dwb::Student s1("Conner", 30, 180, 80);
    s1.sayHello();
    s1.study();

    dwb::Student s2 = s1;
    s2.sayHello();
    s2.study();
    std::cout << std::endl;

    dwb::Person& refPerson1 = s2;
    // 引用类型多态
    refPerson1.run();
    return 0;
}
