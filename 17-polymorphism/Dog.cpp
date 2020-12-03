//
// Created by WebbDong on 8/27/2020.
//
#include <iostream>

#include "Dog.h"

namespace dwb {

    Dog::Dog(const std::string& name, int age, int height)
            : Animal(name, age, height) {
        std::cout << "Dog::Dog(const std::string& name, int age, int height)" << std::endl;
    }

    Dog::~Dog() {
        std::cout << "Dog::~Dog()" << std::endl;
    }

    void Dog::run() {
        std::cout << "Dog::run()" << std::endl;
    }

    void Dog::yelp() {
        std::cout << "Dog::yelp()" << std::endl;
    }

}