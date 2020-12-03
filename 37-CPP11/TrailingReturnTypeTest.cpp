//
// Created by WebbDong on 9/5/2020.
//
#include <iostream>

#include "TrailingReturnTypeTest.h"

namespace dwb {

    // 返回值泛型
    /*
    template<typename R, typename T, typename U>
    R add(T t, U u) {
        return t + u;
    }
     */

    // decltype推导返回值类型
    /*
    template <typename T, typename U>
    decltype((*(T*)0) + (*(U*)0)) add(T t, U u) {
        return t + u;
    }
     */

    // 返回类型后置，auto和decltype结合完成返回值类型的推导
    template<typename T, typename U>
    auto add(T t, U u) -> decltype(t + u) {
        return t + u;
    }

    int& foo(int& i) {
        return i;
    }

    float foo(float& f) {
        return f;
    }

    // 返回类型后置，根据函数重载和函数返回值来推导返回值
    template<typename T>
    auto func(T& val) -> decltype(foo(val)) {
        return foo(val);
    }

    /**
     * 返回类型后置（跟踪返回类型）
     */
    void TrailingReturnTypeTest::test() {
        int a = 1;
        float b = 2.5;
        // decltype推导函数返回值类型,传递给泛型参数
//        auto r = add<decltype(a + b)>(a, b);
        auto r1 = add(a, b);
        std::cout << "add(a, b) = " << r1 << std::endl;

        int num = 500;
        float fNum = 600.5;
        auto r2 = func(num);
        auto r3 = func(fNum);
        std::cout << "r2 = " << r2 << std::endl;
        std::cout << "r3 = " << r3;
    }

}