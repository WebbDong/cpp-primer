//
// Created by WebbDong on 9/23/2020.
//
#include <iostream>
#include <type_traits>

#include "ConceptRequiresTest.h"

namespace dwb {

    template<typename T>
    concept Number = std::is_arithmetic<T>::value;

    template<Number N>
    N add(N x, N y) {
        return x + y;
    }

    /**
     * concept关键字
     *      concept用于声明具有特定约束条件的模板类型。
     * requires关键字
     *      concept结合requires之后，对模板类型参数的约束可以细致到类型成员变量、类型成员函数甚至其返回值等等。
     */
    void ConceptRequiresTest::test() {
        std::cout << "add<int>(40, 60) = " << add<int>(40, 60) << std::endl;
    }

}