//
// Created by WebbDong on 8/31/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    Person::Person() {
        std::cout << "Person::Person() " << this << std::endl;
    }

    Person::Person(const std::string& name) : name(name) {
        std::cout << "Person::Person(const std::string& name) " << this << std::endl;
    }

    Person::Person(int age) : age(age) {
        std::cout << "Person::Person(int age) " << this << std::endl;
    }

    Person::~Person() {
        std::cout << "Person::~Person() " << this << std::endl;
    }

    void Person::sayHello() {
        std::cout << "name = " << name << ", age = " << age << std::endl;
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