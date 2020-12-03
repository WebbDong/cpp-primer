#include <iostream>

#include "Person.h"

/**
 * 普通对象参数，传参时，会创建新对象后传入。如果没有拷贝构造函数，默认直接进行所有字段赋值操作，如果有拷贝构造函数
 * 会调用拷贝构造函数创建。
 * @param person
 */
void objParamFunc(dwb::Person person) {
    std::cout << "objParamFunc(dwb::Person person) person.getName() = " << person.getName() << std::endl;
    std::cout << "objParamFunc(dwb::Person person) person.getAge() = " << person.getAge() << std::endl;
    std::cout << "objParamFunc(dwb::Person person) &person = " << &person << std::endl;
}

/**
 * 使用引用，不会创建新对象
 * @param person
 */
void objRefParamFunc(dwb::Person& person) {
    std::cout << "objParamFunc(dwb::Person person) person.getName() = " << person.getName() << std::endl;
    std::cout << "objParamFunc(dwb::Person person) person.getAge() = " << person.getAge() << std::endl;
    std::cout << "objParamFunc(dwb::Person person) &person = " << &person << std::endl;
}

/**
 * 有的编译器函数返回普通对象时，会重新创建一个对象所有字段赋值后返回，如果定义了拷贝构造函数，会调用拷贝构造函数创建成功后返回。
 * GNU编译器不会创建新对象，而是自动执行值返回优化(RVO， Return value optimization)，会将返回的对象构造在调用者函数的栈中，省去拷贝。
 * 可以使用-fno-elide-constructors关闭RVO，例如：g++ test.cpp  -fno-elide-constructors  -o test
 * @return
 */
dwb::Person returnObjFunc() {
    dwb::Person p1("Conner", 42);
    std::cout << "returnObjFunc() &p1 = " << &p1 << std::endl;
    return p1;
}

/**
 * 普通对象类型参数和返回值
 *      使用对象类型作为函数的参数或者返回值，可能会产生一些不必要的中间对象。
 *      传递对象建议使用引用或指针类型。
 * @return
 */
int main() {
//    dwb::Person p1("Adam", 40);
//    std::cout << "main() &p1 = " << &p1 << std::endl;
//    objParamFunc(p1);
//    objRefParamFunc(p1);

    // 会使用RVO
    dwb::Person person1 = returnObjFunc();
    std::cout << "main() &person1 = " << &person1 << std::endl;
    person1.display();
    std::cout << std::endl;

    dwb::Person person2;
    // 不会使用RVO
    person2 = returnObjFunc();
    std::cout << "main() &person2 = " << &person2 << std::endl;
    person2.display();
    return 0;
}
