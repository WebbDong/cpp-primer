//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "EarlySingleton.h"

namespace dwb {

    EarlySingleton EarlySingleton::instance;

    EarlySingleton::EarlySingleton() {
        std::cout << "EarlySingleton::EarlySingleton()" << std::endl;
    }

    EarlySingleton::EarlySingleton(const EarlySingleton& instance) {}

    EarlySingleton::~EarlySingleton() {
        std::cout << "EarlySingleton::~EarlySingleton()" << std::endl;
    }

    EarlySingleton* EarlySingleton::getInstance() {
        return &EarlySingleton::instance;
    }

    void EarlySingleton::func() {
        std::cout << "EarlySingleton::func()" << std::endl;
    }

}