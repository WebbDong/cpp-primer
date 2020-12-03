//
// Created by WebbDong on 8/25/2020.
//

#include <iostream>

#include "Person.h"

namespace dwb {

    Person::Person() {
        std::cout << "Person::Person()" << std::endl;
    }

    Person::Person(const std::string& name, int age, int height)
            : name(name), age(age), height(height) {
        std::cout << "Person::Person(const std::string& name, int age, int height)" << std::endl;
    }

    Person::~Person() {
        std::cout << "Person::~Person()" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }

    void Person::sayHello() {
        std::cout << "name = " << name << ", age = " << age
                  << ", height = " << height << std::endl;
    }

}