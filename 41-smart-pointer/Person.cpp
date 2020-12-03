//
// Created by WebbDong on 11/15/2020.
//
#include <iostream>

#include "Person.h"

Person::Person() {
    Person::age = 0;
    Person::height = 0;
    std::cout << "Person()" << std::endl;
}

Person::Person(const std::string& name, int age, int height) {
    Person::name = name;
    Person::age = age;
    Person::height = height;
    std::cout << "Person(int, int, const string &)" << std::endl;
}

Person::~Person() {
    std::cout << "~Person()" << std::endl;
}

void Person::display() {
    std::cout << "age = " << this->age << " height = " << this->height << " name = " << this->name << std::endl;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

int Person::getHeight() const {
    return height;
}

void Person::setHeight(int height) {
    Person::height = height;
}

const std::string& Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    Person::name = name;
}
