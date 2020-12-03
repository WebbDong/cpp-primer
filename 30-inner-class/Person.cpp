//
// Created by WebbDong on 8/31/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    int Person::staticNumber = 200;

    Person::Person() {}

    Person::Person(const std::string& name, int age) : name(name), age(age) {}

    void Person::display() {
        std::cout << "name = " << name << ", age = " << age << std::endl;
    }

    Person::Car::Car(const std::string& brand, int horsePower) : brand(brand), horsePower(horsePower) {}

    void Person::Car::display() {
        std::cout << "brand = " << brand << ", horsePower = " << horsePower
                  << ", staticNumber = " << staticNumber << std::endl;
    }

}