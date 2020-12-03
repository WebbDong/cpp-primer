//
// Created by WebbDong on 8/21/2020.
//

#include "Person.h"
#include <iostream>

Person::Person() : name(""), age(0) {}

Person::Person(std::string name, int age) : name(name), age(age) {}

Person::~Person() {
    std::cout << "~Person() 调用，name = " << Person::name << "，age = " << Person::age << std::endl;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}
