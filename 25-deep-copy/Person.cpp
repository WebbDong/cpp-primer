//
// Created by WebbDong on 8/30/2020.
//
#include <iostream>
#include <string.h>

#include "Person.h"

namespace dwb {

    Person::Person(const char* name, int age, int height) : age(age), height(height) {
        init(name);
    }

    Person::Person(const dwb::Person& person) : age(person.age), height(person.height) {
        init(person.name);
    }

    Person::~Person() {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
    }

    void Person::sayHello() {
        std::cout << "name = " << name << ", age = " << age << ", height = " << height << std::endl;
    }

    void Person::run() {
        std::cout << "Person::run()" << std::endl;
    }

    char* Person::getName() const {
        return name;
    }

    void Person::setName(char* name) {
        Person::name = name;
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

    void Person::init(const char* name) {
        if (name != nullptr) {
            // 深拷贝
            int len = strlen(name) + 1;
            this->name = new char[len];
            strcpy_s(this->name, len, name);
        }
    }

}