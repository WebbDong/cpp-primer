#include <iostream>

#include "Cat.h"
#include "Dog.h"

class SuperClass {
public:
    virtual void func();

private:
    int age;
};

class SubClass : public SuperClass {

};

/**
 * 多态
 *      1、父类指针可以指向子类对象，是安全的，开发中经常用到（继承方式必须是public）
 *      2、默认情况下，编译器只会根据指针类型调用对应的函数，不存在多态
 *
 * 多态的要素
 *      1、子类重写父类的成员函数（override）
 *      2、父类指针指向子类对象
 *      3、利用父类指针调用重写的成员函数
 *
 * 虚函数
 *      1、C++中的多态通过虚函数（virtual function）来实现
 *      2、虚函数：被virtual修饰的成员函数
 *      3、只要在父类中声明为虚函数，子类中重写的函数也自动变成虚函数（也就是说子类中可以省略virtual关键字）
 *
 * 虚表
 *      1、虚函数的实现原理是虚表，这个虚表里面存储着最终需要调用的虚函数地址，这个虚表也叫虚函数表。
 *      2、虚表的地址会存储在对象的内存中，对象的前几个字节会存储着虚表的地址，虚表中存储着虚函数的地址。
 *      3、同一个类创建的对象，共用一份虚表。不管对象在全局区、栈还是堆，都是同一份虚表。
 *      4、只要存在一个虚函数，就存在虚表，如果子类没有重写父类的虚函数，子类会将父类的虚函数地址，放入子类的虚表中。
 *
 * 在子类中调用父类的成员函数
 *      在子类中直接使用父类名::父类的函数名()进行调用
 *
 * 虚析构函数
 *      1、如果存在父类指针指向子类对象的情况，也应该将它的析构函数声明为虚函数
 *      2、只有声明为虚析构函数时，delete父类指针时，才会调用子类的析构函数，保证析构的完整性
 *      3、只要父类的析构函数是虚析构函数，子类也会是虚析构函数
 *
 * 只有指针类型和引用类型才可以多态。
 * @return
 */
int main() {
    dwb::Animal* animal1 = new dwb::Cat("猫", 1, 30);
    animal1->run();
    animal1->yelp();
    animal1->display();
    delete animal1;

    std::cout << std::endl;

    dwb::Animal* animal2 = new dwb::Dog("狗", 2, 35);
    animal2->run();
    animal2->yelp();
    animal2->display();
    delete animal2;

    std::cout << sizeof(SubClass) << std::endl << std::endl;

    dwb::Dog dog1("哈士奇", 4, 40);
    // 引用类型也可以多态
    dwb::Animal& animal3 = dog1;
    animal3.run();
    animal3.display();

    dwb::Cat cat1("英短", 8, 30);
    // animal3是dog1的别名，将cat1的属性赋值给dog1
    animal3 = cat1;
    animal3.run();
    animal3.display();

    dog1.run();
    dog1.display();
    return 0;
}
