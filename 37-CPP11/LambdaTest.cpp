//
// Created by WebbDong on 9/6/2020.
//
#include <iostream>

#include "LambdaTest.h"

namespace dwb {

    // Lambda配合模板
    template<typename T>
    auto addTemplateLambda = [](T a, T b) -> T {
        return a + b;
    };

    void lambdaTest() {
        // 匿名lambdad函数，定义后立刻执行
        ([] {
            std::cout << "Hello Lambda" << std::endl;
        })();

        // 使用函数指针来指向lambda 表达式
        void (*lambda1)() = [] {
            std::cout << "lambda1" << std::endl;
        };
        lambda1();
        (*lambda1)();

        auto lambda2 = [] {
            std::cout << "lambda2" << std::endl;
        };
        lambda2();
        (*lambda2)();

        auto lambda3 = [](int a, int b) -> int {
            return a + b;
        };
        int res1 = lambda3(50, 80);
        std::cout << "res1 = " << res1 << std::endl;

        int res2 = addTemplateLambda<int>(800, 1000);
        std::cout << "res2 = " << res2 << std::endl;

        // 省略返回值
        auto lambda4 = [](int a, int b) {
            return a - b;
        };
        int res3 = lambda4(600, 400);
        std::cout << "res3 = " << res3 << std::endl;
    }

    /**
     * 外部变量访问方式
     */
    void captureListTest() {
        int a = 500;
        int b = 700;
        // 外部变量a和b值传递
        auto lambda1 = [a, b](int x, int y) {
            return a + b + x + y;
        };
        int res1 = lambda1(100, 700);
        std::cout << "res1 = " << res1 << std::endl;

        // 所有外部变量都是值传递
        auto lambda2 = [=](int x, int y) {
            return a - b - x - y;
        };
        int res2 = lambda2(200, 300);
        std::cout << "res2 = " << res2 << std::endl;

        // a变量引用传递，b变量值传递
        auto lambda3 = [&a, b](int x, int y) {
            return a + b + x + y;
        };
        a = 50000;
        int res3 = lambda3(50, 90);
        std::cout << "res3 = " << res3 << std::endl;
    }

    /**
     * mutable
     */
    void mutableTest() {
        int num1 = 700;
        int num2 = 800;
        auto lambda1 = [num1, &num2]() mutable {
            // 不会修改外部num1变量，修改的是lambda内部的一个副本
            num1 = 900000;
            // 引用传递会改变外部num2变量
            num2 = 800000;
            std::cout << "lambda1(): num1 = " << num1 << ", num2 = " << num2 << std::endl;
        };
        lambda1();
        std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    }

    /**
     * 异常
     */
    void exceptionTest() {
        /*
        auto lambda1 = []() noexcept {
            throw "Error";
        };
        try {
            // 声明了noexcept，即便抛出了异常也无法捕捉
            lambda1();
        } catch (const char* msg) {
            std::cout << msg << std::endl;
        } catch (...) {
            std::cout << "error" << std::endl;
        }
         */
        auto lambda2 = []() throw(std::string) {
            throw std::string("Error");
        };
        try {
            lambda2();
        } catch (const std::string& msg) {
            std::cout << msg << std::endl;
        }
    }

    /**
     * lambda 表达式
     *      lambda匿名函数的定义:
     *          [外部变量访问方式说明符] (参数) mutable noexcept/throw() -> 返回值类型 {
     *              函数体;
     *          };
     *
     *          详解：
     *              1) [外部变量方位方式说明符]
     *                  [ ] 方括号用于向编译器表明当前是一个 lambda 表达式，其不能被省略。在方括号内部，
     *                  可以注明当前 lambda 函数的函数体中可以使用哪些“外部变量”。所谓外部变量，指的是和当前 lambda 表达式位于同一作用域内的所有局部变量。
     *
     *                  [外部变量]的定义方式：
     *                      []：空方括号表示当前 lambda 匿名函数中不导入任何外部变量。
     *                      [=]：只有一个 = 等号，表示以值传递的方式导入所有外部变量；
     *                      [&]：只有一个 & 符号，表示以引用传递的方式导入所有外部变量；
     *                      [val1,val2,...]：表示以值传递的方式导入 val1、val2 等指定的外部变量，同时多个变量之间没有先后次序；
     *                      [&val1,&val2,...]：表示以引用传递的方式导入 val1、val2等指定的外部变量，多个变量之间没有前后次序；
     *                      [val,&val2,...]：以上 2 种方式还可以混合使用，变量之间没有前后次序。
     *                      [=,&val1,...]：表示除 val1 以引用传递的方式导入外，其它外部变量都以值传递的方式导入。
     *                      [this]：表示以值传递的方式导入当前的 this 指针。
     *              2) (参数)
     *                  和普通函数的定义一样，lambda 匿名函数也可以接收外部传递的多个参数。和普通函数不同的是，如果不需要传递参数，可以连同 () 小括号一起省略；
     *              3) mutable
     *                  此关键字可以省略，如果使用则之前的 () 小括号将不能省略（参数个数可以为 0）。默认情况下，
     *                  对于以值传递方式引入的外部变量，不允许在 lambda 表达式内部修改它们的值（可以理解为这部分变量都是 const 常量）。
     *                  而如果想修改它们，就必须使用 mutable 关键字。注意，对于以值传递方式引入的外部变量，lambda 表达式修改的是拷贝的那一份，并不会修改真正的外部变量；
     *              4) noexcept/throw()
     *                  可以省略，如果使用，在之前的 () 小括号将不能省略（参数个数可以为 0）。默认情况下，lambda 函数的函数体中可以抛出任何类型的异常。
     *                  而标注 noexcept 关键字，则表示函数体内不会抛出任何异常；使用 throw() 可以指定 lambda 函数内部可以抛出的异常类型。
     *                  如果 lambda 函数标有 noexcept 而函数体内抛出了异常，又或者使用 throw() 限定了异常类型而函数体内抛出了非指定类型的异常，
     *                  这些异常无法使用 try-catch 捕获，会导致程序执行失败
     *              5) -> 返回值类型
     *                  指明 lambda 匿名函数的返回值类型。如果 lambda 函数体内只有一个 return 语句，或者该函数返回 void，
     *                  则编译器可以自行推断出返回值类型，此情况下可以直接省略-> 返回值类型。
     *              6) 函数体
     *                  和普通函数一样，lambda 匿名函数包含的内部代码都放置在函数体中。该函数体内除了可以使用指定传递进来的参数之外，
     *                  还可以使用指定的外部变量以及全局范围内的所有全局变量。需要注意的是，外部变量会受到以值传递还是以引用传递方式引入的影响，
     *                  而全局变量则不会。换句话说，在 lambda 表达式内可以使用任意一个全局变量，必要时还可以直接修改它们的值。
     */
    void LambdaTest::test() {
//        lambdaTest();
//        captureListTest();
//        mutableTest();
        exceptionTest();
    }

}