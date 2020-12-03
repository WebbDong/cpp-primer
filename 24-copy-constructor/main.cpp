#include <iostream>

#include "Person.h"
#include "Student.h"

/**
 * 拷贝构造函数
 *      拷贝构造函数是构造函数的一种
 *      当利用已存在的对象创建一个新对象时（类似于拷贝），就会调用新对象的拷贝构造函数进行初始化
 *      拷贝构造函数的格式是固定的，接收一个const引用作为参数，可以使用初始化列表，也可以使用函数体
 *      如果不显示实现构造函数，默认的拷贝方式是将对象的所有字段一一赋值(包括继承下来的字段)
 * @return
 */
int main() {
    dwb::Person p1("Adam", 30); // 调用Person(const std::string& name = "", int age = 0)构造函数
    p1.sayHello();

    dwb::Person p2(p1); // 调用Person(const Person& person)拷贝构造函数
    p2.sayHello();

    dwb::Person p3 = p2; // 调用Person(const Person& person)拷贝构造函数
    p3.sayHello();
    std::cout << "------------------------------------" << std::endl;

    dwb::Student s1("Conner", 28, 98.5f); // 调用Student(const std::string& name = "", int age = 0, float score = 0.0f)构造函数
    s1.sayHello();
    std::cout << "------------------------------------" << std::endl;

    dwb::Student s2(s1); // 调用Student(const Student& student)拷贝构造函数
    s2.sayHello();
    std::cout << "------------------------------------" << std::endl;

    dwb::Student s3 = s2; // 调用Student(const Student& student)拷贝构造函数
    s3.sayHello();
    std::cout << "------------------------------------" << std::endl;

    dwb::Student s4; // 调用Student(const std::string& name = "", int age = 0, float score = 0.0f)构造函数
    s4.sayHello();

    s4 = s3; // 赋值操作，将s3的字段赋值给s4的字段
    s4.sayHello();
    return 0;
}
