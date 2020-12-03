//
// Created by WebbDong on 9/1/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    Person::Person(const std::string& name, int age) : name(name), age(age) {}

    Person::~Person() {}

    void Person::display() {
        std::cout << "name = " << name << ", age = " << age << std::endl;
    }

    bool Person::operator<=(const Person& p) {
        return this->age <= p.age;
    }

    bool Person::operator>=(const Person& p) {
        return this->age >= p.age;
    }

    bool Person::operator>(const Person& p) {
        return this->age > p.age;
    }

    bool Person::operator<(const Person& p) {
        return this->age < p.age;
    }

    Person& Person::operator=(const Person& p) {
        this->name = p.name;
        this->age = p.age;
        return *this;
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