//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    Person::Person(const std::string& name, int age, int height)
        : name(name), age(age), height(height) {
        std::cout << "Person::Person(const std::string& name, int age, int height)" << std::endl;
    }

    Person::~Person() {
        std::cout << "Person::~Person()" << std::endl;
    }

    void Person::sayHello() {
        std::cout << "name = " << name << ", age = " << age << ", height = " << height << std::endl;
    }

    const std::string& dwb::Person::getName() const {
        return name;
    }

    void dwb::Person::setName(const std::string& name) {
        Person::name = name;
    }

    int dwb::Person::getAge() const {
        return age;
    }

    void dwb::Person::setAge(int age) {
        Person::age = age;
    }

    int dwb::Person::getHeight() const {
        return height;
    }

    void dwb::Person::setHeight(int height) {
        Person::height = height;
    }

}
