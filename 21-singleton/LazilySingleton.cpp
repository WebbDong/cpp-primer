//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "LazilySingleton.h"

namespace dwb {

    LazilySingleton* LazilySingleton::instance = NULL;

    LazilySingleton::LazilySingleton() {}

    LazilySingleton::~LazilySingleton() {
        std::cout << "LazilySingleton::~LazilySingleton()" << std::endl;
    }

    LazilySingleton* LazilySingleton::getInstance() {
        // 后期加上线程安全控制
        if (LazilySingleton::instance == NULL) {
            LazilySingleton::instance = new LazilySingleton;
        }
        return LazilySingleton::instance;
    }

    void LazilySingleton::release() {
        // 后期加上线程安全控制
        if (LazilySingleton::instance != NULL) {
            delete LazilySingleton::instance;
            LazilySingleton::instance = NULL;
        }
    }

    void LazilySingleton::func() {
        std::cout << "LazilySingleton::func()" << std::endl;
    }

}