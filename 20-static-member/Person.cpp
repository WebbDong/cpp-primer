//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    std::string Person::staticString = "staticString";

    int Person::staticNumber = 1000;

    Person::Person(const std::string& name, int age)
            : name(name), age(age) {}

    void Person::staticFunc() {
        std::cout << Person::staticNumber << std::endl;
    }

    const std::string& Person::getName() const {
        return name;
    }

    void Person::setName(const std::string& name) {
        Person::name = name;
    }

    int Person::getAge() const {
        return age;
    }

    void Person::setAge(int age) {
        Person::age = age;
    }

}