//
// Created by WebbDong on 9/5/2020.
//
#include <iostream>

#include "InitializationListTest.h"

namespace dwb {

    /**
     * 列表初始化（统一了初始化方式）
     */
    void InitializationListTest::test() {
        int num1 = {50};
        float fnum1 = {60.5f};
        double dnum1 = {120.5};
        std::cout << "num1 = " << num1 << std::endl;
        std::cout << "fnum1 = " << fnum1 << std::endl;
        std::cout << "dnum1 = " << dnum1 << std::endl;
    }

}