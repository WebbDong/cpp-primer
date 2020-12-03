//
// Created by WebbDong on 9/19/2020.
//
#include <iostream>

#include "NullptrTest.h"

namespace dwb {

    void nullptrTest(int i) {
        std::cout << "nullptrTest(int i)" << std::endl;
    }

    void nullptrTest(int* p) {
        std::cout << "nullptrTest(int* p)" << std::endl;
    }

    /**
     * nullptr：初始化空指针
     *      C++98/03 标准中，将一个指针初始化为空指针的方式有 2 种：
     *          int* p = 0;
     *          int* p = NULL; //推荐使用
     */
    void NullptrTest::test() {
        nullptrTest(9000);
        nullptrTest(nullptr);
    }

}