//
// Created by WebbDong on 8/29/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    const int Person::staticConstNumber = 20;

    Person::Person(const std::string& name) : name(name), constNumber(10) {}

    void Person::constFunc() const {
        // 不能修改
//        constNumber = 500;
        std::cout << constNumber << std::endl;
        std::cout << name << std::endl;
        // 不能修改非static成员变量
//        name = "Conner";
    }

    void Person::func() {
        std::cout << constNumber << std::endl;
        std::cout << name << std::endl;
        name = "Conner";
    }

}