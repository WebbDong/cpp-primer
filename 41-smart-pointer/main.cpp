#include <iostream>
#include <memory>

#include "MyAutoPtr.hpp"
#include "Person.h"
#include "Student.h"

void autoPtrTest() {
    // 智能指针p1指向堆空间的Person对象
    std::auto_ptr<Person> p1(new Person("Adam", 40, 180));
    p1->display();
    std::cout << "-----------------------------------------------------------" << std::endl;

    Person *pPerson1 = new Person("Conner", 30, 188);
    std::auto_ptr<Person> p2(pPerson1);
    p2->display();
    std::cout << "pPerson1 = " << pPerson1 << std::endl;
    std::cout << "&pPerson1 = " << &pPerson1 << std::endl;
    std::cout << "&p2 = " << &p2 << std::endl;

    std::cout << "-----------------------------------------------------------" << std::endl;

    std::auto_ptr<Person> p3(new Student("Lisa", 25, 170, 80));
    p3->display();
}

void myAutoPtrTest() {
    dwb::MyAutoPtr<Person> p1(new Student("Linda", 25, 170, 80));
    p1->display();
}

void sharedPtrTest() {
    std::shared_ptr<Person> p1(new Person("Adam", 40, 180));
    p1->display();

    std::shared_ptr<Student[]> pArr1(new Student[4] {
            Student("Lisa", 25, 170, 90),
            Student("Linda", 25, 170, 70),
            Student("Conner", 30, 188, 80),
            Student("Conner", 30, 188, 80)
    });

    std::cout << "pArr1.use_count() = " << pArr1.use_count() << std::endl;
}

void uniquePtrTest() {
    std::unique_ptr<Person> p1(new Person("Adam", 40, 180));
    std::unique_ptr<Person> p2 = std::move(p1);
    p2->display();

    std::unique_ptr<Student[]> pArr1(new Student[4] {
            Student("Lisa", 25, 170, 90),
            Student("Linda", 25, 170, 70),
            Student("Conner", 30, 188, 80),
            Student("Conner", 30, 188, 80)
    });
}

/**
 * 智能指针
 *      传统指针存在的问题
 *          1、需要手动管理内存
 *          2、容易发生内存泄露
 *          3、释放后产生野指针
 *
 *      智能指针是为了解决传统指针存在的问题
 *          auto_ptr：属于C++98标准，在C++11中已经不推荐使用（有缺陷，比如不能用于数组，存在多次析构的情况等）
 *          shared_ptr：属于C++11标准
 *          unique_ptr：属于C++11标准
 *
 *      shared_ptr
 *          1、多个shared_ptr可以指向同一个对象，当最后一个shared_ptr在作用域范围内结束时，对象才会被自动释放
 *          2、可以通过一个已存在的智能指针初始化一个新的智能指针
 *
 *      shared_ptr原理：
 *          1、一个shared_ptr会对一个对象产生强引用（strong reference）
 *          2、每个对象都有个与之对应的强引用计数，记录着当前对象被多少个shared_ptr强引用着，可以通过shared_ptr的use_count函数获得强引用计数
 *          3、当有一个新的shared_ptr指向对象时，对象的强引用计数就会+1
 *          4、当有一个shared_ptr销毁时（比如作用域结束），对象的强引用计数就会-1
 *          5、当一个对象的强引用计数为0时（没有任何shared_ptr指向对象时），对象就会自动销毁（析构）
 *
 *      shared_ptr循环引用
 *          解决循环引用的方法是使用弱引用weak_ptr
 *
 *      weak_ptr
 *          weak_ptr会对一个对象产生弱引用
 *          weak_ptr可以指向对象解决shared_ptr的循环引用问题
 *
 *      unique_ptr
 *          1、unique_ptr也会对一个对象产生强引用，它可以确保同一时间只有1个指针指向对象
 *          2、当unique_ptr销毁时（作用域结束时），其指向的对象也就自动销毁了
 *          3、可以使用std::move函数转移unique_ptr的所有权，不使用std::move不能随意更换并且也不可以多个unique_ptr指向多个普通指针
 */
int main() {
//    autoPtrTest();
//    myAutoPtrTest();
//    sharedPtrTest();
    uniquePtrTest();
    return 0;
}
