//
// Created by WebbDong on 8/24/2020.
//
#include <iostream>
#include "Person.h"

namespace dwb {

    Person::Person() {}

    Person::Person(const std::string& name, int age, int height) : name(name), age(age), height(height) {}

    void Person::sayHello() {
        std::cout << "Hello, I'm " << name << ", " << age << " years old and " << height << " cm tall." << std::endl;
    }

}