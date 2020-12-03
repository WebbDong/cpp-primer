#include <iostream>

#include "Person.h"

void test(dwb::Person person) {
    person.sayHello();
}

dwb::Person test2() {
    // 返回时隐式调用Person(int age)构造函数创建对象
    return 40;
}

dwb::Person test3() {
    // 返回时隐式调用Person(const std::string& name)构造函数
    return std::string("Lisa");
}

/**
 * 隐式构造
 *      C++中存在隐式构造的现象：某些情况下，会隐式调用单参数的构造函数
 *
 * 显示构造
 *      可以通过关键字explicit禁止掉隐式构造
 * @return
 */
int main() {
    {
        // 隐式调用Person(int age)构造函数
        dwb::Person p1 = 45;
        p1.sayHello();
    }
    std::cout << std::endl;

    {
        // 隐式调用Person(const std::string& name)构造函数
        dwb::Person p2 = std::string("Adam");
        p2.sayHello();
    }
    std::cout << std::endl;

    // 隐式调用Person(int age)构造函数
    test(30);
    std::cout << std::endl;

    // 隐式调用Person(const std::string& name)构造函数
    test(std::string("Conner"));
    std::cout << std::endl;

    {
        dwb::Person p3 = test2();
        p3.sayHello();
    }
    std::cout << std::endl;

    {
        dwb::Person p4 = test3();
        p4.sayHello();
    }
    std::cout << std::endl;

    {
        // 调用Person::Person()构造函数
        dwb::Person p5;
        // 隐式调用Person::Person(int age)构造函数创建一个临时对象，在将这个临时对象的属性赋值给p5，然后销毁
        p5 = 66;
        p5.sayHello();
    }
    std::cout << std::endl;

    {
        dwb::Person p6;
        p6.setAge(100);
        // 隐式调用Person(const std::string& name)构造函数创建一个临时对象，在将这个临时对象的属性赋值给p6，然后销毁
        p6 = std::string("John");
        p6.sayHello();
    }
    return 0;
}
