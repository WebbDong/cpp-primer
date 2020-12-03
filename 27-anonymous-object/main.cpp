#include <iostream>

#include "Person.h"

void test(dwb::Person person) {
    person.sayHello();
}

/**
 * 匿名对象（临时对象）
 *      没有变量名、没有被指针指向的对象，用完后马上调用析构
 */
int main() {
//    dwb::Person("Adam", 40).sayHello();
    test(dwb::Person("Conner", 30));
    return 0;
}
