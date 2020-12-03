#include <iostream>

#include "Person.h"
#include "Student.h"

void cStyleCast() {
    int num = 10;
    double double1 = double(num);
    double double2 = (double) num;
    std::cout << "&num = " << &num << std::endl;
    std::cout << "&double1 = " << &double1 << std::endl;
    std::cout << "&double2 = " << &double2 << std::endl;
}

void constCast() {
    int num = 10;
    const int* pNum1 = &num;
    int* pNum2 = const_cast<int*>(pNum1);
    int* pNum3 = (int*) pNum1;
    std::cout << "pNum1 = " << pNum1 << std::endl;
    std::cout << "pNum2 = " << pNum2 << std::endl;
    std::cout << "pNum3 = " << pNum3 << std::endl;

    const int& refNum1 = num;
    int& refNum2 = const_cast<int&>(num);
    int& refNum3 = const_cast<int&>(refNum1);
    int& refNum4 = (int&) refNum1;
    std::cout << "&refNum1 = " << &refNum1 << ", refNum1 = " << refNum1 << std::endl;
    std::cout << "&refNum2 = " << &refNum2 << ", refNum2 = " << refNum2 << std::endl;
    std::cout << "&refNum3 = " << &refNum3 << ", refNum3 = " << refNum3 << std::endl;
    std::cout << "&refNum4 = " << &refNum4 << ", refNum4 = " << refNum4 << std::endl;

    const dwb::Person p1("Adam", 25);
    const dwb::Person& refPerson1 = p1;
    dwb::Person& refPerson2 = const_cast<dwb::Person&>(p1);
    dwb::Person& refPerson3 = const_cast<dwb::Person&>(refPerson1);
    dwb::Person& refPerson4 = (dwb::Person&) p1;
    std::cout << "&p1 = " << &p1 << ", p1 = " << p1 << std::endl;
    std::cout << "&refPerson2 = " << &refPerson2 << ", refPerson2 = " << refPerson2 << std::endl;
    std::cout << "&refPerson3 = " << &refPerson2 << ", refPerson3 = " << refPerson2 << std::endl;
    std::cout << "&refPerson4 = " << &refPerson4 << ", refPerson4 = " << refPerson4 << std::endl;

    const dwb::Person* pPerson1 = &p1;
    dwb::Person* pPerson2 = const_cast<dwb::Person*>(&p1);
    dwb::Person* pPerson3 = const_cast<dwb::Person*>(pPerson1);
    dwb::Person* pPerson4 = (dwb::Person*) pPerson1;
    std::cout << "pPerson2 = " << pPerson2 << ", *pPerson2 = " << *pPerson2 << std::endl;
    std::cout << "pPerson3 = " << pPerson3 << ", *pPerson3 = " << *pPerson3 << std::endl;
    std::cout << "pPerson4 = " << pPerson4 << ", *pPerson4 = " << *pPerson4 << std::endl;
}

void dynamicCast() {
    dwb::Person* pPerson1 = new dwb::Person("Conner", 40);
    dwb::Person* pPerson2 = new dwb::Student("Adam", 25, 90.5);
    // 类型检查不通过，返回nullptr
    dwb::Student* pStudent1 = dynamic_cast<dwb::Student*>(pPerson1);
    dwb::Student* pStudent2 = dynamic_cast<dwb::Student*>(pPerson2);
    std::cout << "pPerson1 = " << pPerson1 << std::endl;
    std::cout << "pPerson2 = " << pPerson2 << std::endl;
    std::cout << "pStudent1 = " << pStudent1 << std::endl;
    std::cout << "pStudent2 = " << pStudent2 << std::endl;
    delete pPerson1;
    delete pPerson2;

    dwb::Person p1("John", 33);
    dwb::Student s1("Lisa", 26, 165);
    dwb::Person& refPerson1 = s1;
    // 报std::bad_cast异常
    dwb::Student& refStudent1 = dynamic_cast<dwb::Student&>(p1);
    dwb::Student& refStudent2 = dynamic_cast<dwb::Student&>(refPerson1);
    std::cout << "&refStudent1 = " << &refStudent1 << std::endl;
    std::cout << "&refStudent2 = " << &refStudent2 << ", refStudent2 = " << refStudent2 << std::endl;
    std::cout << std::endl;
}

void staticCast() {
    int num = 5000;
    double dNum = static_cast<double>(num);
    std::cout << "dNum = " << dNum << std::endl;

    const int constNum = static_cast<const int>(num);
    std::cout << "constNum = " << constNum << std::endl;

    dwb::Person p1("Adam", 26);
    const dwb::Person constPerson = static_cast<const dwb::Person>(p1);
    std::cout << "constPerson = " << constPerson << std::endl;

    dwb::Student s1("Conner", 30, 98.5);
    dwb::Person& refP1 = s1;
    dwb::Student& refS1 = static_cast<dwb::Student&>(refP1);
    // 不会进行类型检查，转换成功，但是很危险
//    dwb::Student& refS2 = static_cast<dwb::Student&>(p1);
    const dwb::Student& constRefS1 = static_cast<const dwb::Student&>(refP1);
    std::cout << "refS1 = " << refS1 << std::endl;
//    std::cout << "refS2 = " << refS2 << std::endl;
    std::cout << "constRefS1 = " << constRefS1 << std::endl;

    dwb::Person* pPerson1 = new dwb::Student("Lisa", 20, 165);
    dwb::Student* pStudent1 = static_cast<dwb::Student*>(pPerson1);
    const dwb::Student* pConstStudent1 = static_cast<const dwb::Student*>(pPerson1);
    std::cout << "pStudent1 = " << pStudent1 << ", *pStudent1 = " << *pStudent1 << std::endl;
    std::cout << "pConstStudent1 = " << pConstStudent1 << ", *pConstStudent1 = " << *pConstStudent1 << std::endl;
    delete pPerson1;

    const int constArray[] = {1, 2, 3, 4, 5, 6};
    int* array = const_cast<int*>(constArray);
    array[0] = 100;
    array[5] = 900;
    for (int i = 0; i < 6; i++) {
        std::cout << constArray[i] << " ";
    }
}

void reinterpretCast() {
    int num = 200;
    // 不同类型转换需要指定引用
    double dNum = reinterpret_cast<double&>(num);
    std::cout << "&num = " << &num << ", &dNum = " << &dNum << ", dNum = " << dNum << std::endl;

    int num2 = reinterpret_cast<int>(num);
    std::cout << "&num2 = " << &num2 << ", num2 = " << num2 << std::endl;
}

/**
 * 类型转换
 *      C语言风格的类型转换符
 *          (type)expression
 *          type(expression)
 *
 *      C++中有4个类型转换符
 *          1、static_cast：
 *              对比dynamic_cast，缺乏运行时安全检测
 *              不能交叉转换（不是同一继承体系的，无法转换）
 *              常用于基本数据类型的转换、可以将非const转成const
 *              可以转换基本数据类型，指针，引用
 *          2、dynamic_cast：
 *              一般用于多态类型的转换，有运行时安全检测。只能转换引用和指针，当转换指针时，如果类型检查不通过时返回nullptr。
 *              当转换引用时，如果类型检查不通过时抛出std::bad_cast异常。
 *          3、reinterpret_cast：
 *              属于比较底层的强制转换，没有任何类型检查和格式转换，仅仅是简单的二进制数据拷贝。它会产生一个新值。
 *              可以交叉转换
 *              可以将指针和整数互相转换
 *          4、const_cast：
 *              一般用于去除const或volatile属性，将const转换成非const，将volatile属性移除。只能转换引用和指针
 *
 *          使用格式：xx_cast<type>(expression)
 */
int main() {
//    cStyleCast();
//    std::cout << "-------------------------------------------------" << std::endl;
//    constCast();
//    std::cout << "-------------------------------------------------" << std::endl;
//    dynamicCast();
//    std::cout << "-------------------------------------------------" << std::endl;
//    staticCast();
//    std::cout << "-------------------------------------------------" << std::endl;
    reinterpretCast();
    return 0;
}
