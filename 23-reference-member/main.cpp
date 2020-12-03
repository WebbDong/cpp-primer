#include <iostream>

#include "Person.h"

class Base {
public:
    Base(int num = 0) : num(num) {}

    int getNum() const {
        return num;
    }

    void setNum(int num) {
        Base::num = num;
    }

private:
    int num;
};

class Sub {
public:
    Sub(int num, float money) : money(money) {
        base.setNum(num);
    }

    Base& getBaseRef() {
        // 返回的是成员变量base的引用，外界修改时会受影响
        return base;
    }

    Base getBase() {
        // 返回的是成员变量base的副本，外界修改时不会受影响
        return base;
    }

    void setBase(const Base& base) {
        // 将参数的所有字段全部赋值给成员变量base的字段
        Sub::base = base;
    }

    float& getMoneyRef() {
        // 返回的是成员变量money的引用，外界修改时会受影响
        return money;
    }

    float getMoney() const {
        // 返回的是成员变量money的副本，外界修改时不会受影响
        return money;
    }

    void setMoney(float money) {
        Sub::money = money;
    }

public:
    Base base;
    float money;
};

/**
 * 引用类型成员
 *      引用类型成员变量必须初始化
 *          在声明的时候直接初始化
 *          通过初始化列表初始化
 *
 *      当引用类型成员赋值的不是成员变量，会分配一个临时内存存储数据，如果是成员变量，那就是该变量的别名。
 *
 *      当成员函数返回成员变量的引用时，外界的修改会影响到对象的成员变量，如果返回的成员变量不是引用，
 *      返回的是该成员变量的副本，外界的修改不会影响到对象的成员变量。
 * @return
 */
int main() {
    std::cout << "dwb::Person::staticNumber = " << dwb::Person::staticNumber << std::endl;
    std::cout << "dwb::Person::staticRefNumber = " << dwb::Person::staticRefNumber << std::endl;
    std::cout << "&dwb::Person::staticNumber = " << &dwb::Person::staticNumber << std::endl;
    std::cout << "&dwb::Person::staticRefNumber = " << &dwb::Person::staticRefNumber << std::endl << std::endl;

    dwb::Person p1(40);
    p1.func();
    std::cout << "p1.getRefAge() = " << p1.getRefAge() << std::endl;
    std::cout << "&p1.getRefAge() = " << &p1.getRefAge() << std::endl << std::endl;

    {
        int age = 120;
        p1.setRefAge(age);
        std::cout << "&age = " << &age << std::endl;
        std::cout << "&p1.getRefAge() = " << &p1.getRefAge() << std::endl;
    }
    p1.func();
    std::cout << "p1.getRefAge() = " << p1.getRefAge() << std::endl;
    std::cout << "&p1.getRefAge() = " << &p1.getRefAge() << std::endl << std::endl;

    int number = 30;
    int &refNumber = number;
    std::cout << "&number = " << &number << std::endl;
    std::cout << "&refNumber = " << &refNumber << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    Sub sub(500, 40.5f);
    std::cout << "&sub.base = " << &sub.base << std::endl;
    Base base1(9000);
    std::cout << "&base1 = " << &base1 << std::endl;
    // 将base1的所有字段全部赋值给sub的成员变量base的字段
    sub.setBase(base1);
    std::cout << "sub.getBaseRef().getNum() = " << sub.getBaseRef().getNum() << std::endl;
    std::cout << "&sub.base = " << &sub.base << std::endl << std::endl;

    Base& baseRef1 = sub.getBaseRef();
    std::cout << "&baseRef1 = " << &baseRef1 << std::endl;
    // 修改会影响sub对象里的成员变量base
    baseRef1.setNum(55555);
    std::cout << "sub.base.getNum() = " << sub.base.getNum() << std::endl << std::endl;

    Base base2 = sub.getBase();
    std::cout << "&base2 = " << &base2 << std::endl;
    // 修改不会影响sub对象里的成员变量base
    base2.setNum(8888888);
    std::cout << "sub.base.getNum() = " << sub.base.getNum() << std::endl << std::endl;

    std::cout << "sub.money = " << sub.money << std::endl;
    std::cout << "&sub.money = " << &sub.money << std::endl;
    float& moneyRef1 = sub.getMoneyRef();
    std::cout << "&moneyRef1 = " << &moneyRef1 << std::endl;
    // 修改会影响sub对象里的成员变量money
    moneyRef1 = 458.12f;
    std::cout << "sub.money = " << sub.money << std::endl;
    std::cout << "&sub.money = " << &sub.money << std::endl << std::endl;

    float money1 = sub.getMoney();
    std::cout << "&money1 = " << &money1 << std::endl;
    // 修改不会影响sub对象里的成员变量money
    money1 = 789.45f;
    std::cout << "sub.money = " << sub.money << std::endl;
    std::cout << "&sub.money = " << &sub.money << std::endl << std::endl;
    return 0;
}
