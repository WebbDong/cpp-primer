//
// Created by WebbDong on 8/27/2020.
//
#include <iostream>

#include "Animal.h"

namespace dwb {

    Animal::Animal(const std::string& name, int age, int height)
            : name(name), age(age), height(height) {
        std::cout << "Animal::Animal(const std::string& name, int age, int height)" << std::endl;
    }

    Animal::~Animal() {
        std::cout << "Animal::~Animal()" << std::endl;
    }

    void Animal::sayHello() {
        std::cout << "name = " << name << ", age = " << age << ", height" << height << std::endl;
    }

    const std::string& Animal::getName() const {
        return name;
    }

    void Animal::setName(const std::string& name) {
        Animal::name = name;
    }

    int Animal::getAge() const {
        return age;
    }

    void Animal::setAge(int age) {
        Animal::age = age;
    }

    int Animal::getHeight() const {
        return height;
    }

    void Animal::setHeight(int height) {
        Animal::height = height;
    }

}