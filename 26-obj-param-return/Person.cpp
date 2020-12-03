//
// Created by WebbDong on 8/30/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    Person::Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Person::Person(const std::string& name, int age)" << std::endl;
    }

    Person::Person(const dwb::Person& person) : name(person.name), age(person.age) {
        std::cout << "Person::Person(const dwb::Person& person)" << std::endl;
    }

    void Person::display() {
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