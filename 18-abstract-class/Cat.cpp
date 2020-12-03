//
// Created by WebbDong on 8/27/2020.
//
#include <iostream>

#include "Cat.h"

namespace dwb {

    Cat::Cat(const std::string& name, int age, int height)
            : Animal(name, age, height) {
        std::cout << "Cat::Cat(const std::string& name, int age, int height)" << std::endl;
    }

    Cat::~Cat() {
        std::cout << "Cat::~Cat()" << std::endl;
    }

    void Cat::run() {
        std::cout << "Cat::run()" << std::endl;
    }

    void Cat::yelp() {
        std::cout << "Cat::yelp()" << std::endl;
    }

}