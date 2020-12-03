#include <iostream>

#include "ArithmeticException.h"

template<typename T>
T divide(T a, T b) {
    if (b == 0) {
//        throw std::string("不能除以0");
        error::ArithmeticException e;
        std::cout << "divide(T a, T b) : &e" << &e << std::endl;
        throw e;
    }
    return a / b;
}

/**
 * 异常处理
 *      异常的抛出声明(动态异常规范):
 *          为了增强可读性和方便团队协作，如果函数内部可能会抛出异常，建议函数声明一下异常类型
 *
 *          // 可能抛出任意的异常
 *          void func1();
 *
 *          // 不抛出任何异常
 *          void func2() throw();
 *
 *          // 只抛出int、double类型的异常
 *          void func3() throw(int, double);
 *
 *          在C++11规范中已经弃用动态异常规范，C++11规范中新增了noexcept关键词，表示函数不会引发异常
 *              void func1() noexcept;
 * @return
 */
int main() {
    /*
    try {
        double res = divide<double>(50.0, 0.0);
        std::cout << "res = " << res;
    } catch (const std::string& msg) {
        std::cout << msg;
    } catch (...) { // 捕捉所有异常
        std::cout << "Error";
    }
     */

    try {
        double res = divide<double>(50.0, 0.0);
        std::cout << "res = " << res;
    } catch (const error::ArithmeticException& e) {
        std::cout << "main() : &e" << &e << std::endl;
        std::cout << e.what();
    }
    return 0;
}
