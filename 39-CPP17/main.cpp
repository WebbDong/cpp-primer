#include <iostream>

void initIfSwitchTest() {
    int num1 = 500;
    if (int a = 10; num1 > 100 && a == 10) {
        std::cout << "a = " << a << std::endl;
    }

    switch (int a = 20; num1) {
        case 500:
            std::cout << "a = " << a << std::endl;
        default:
            break;
    }
}

template<bool flag>
void templateFunc() {
    if constexpr (flag) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

void constexprTest() {
    templateFunc<true>();
    templateFunc<false>();

    constexpr auto lambda1 = [](auto m, auto n) {
        return m + n;
    };
    std::cout << "lambda1(40, 60) = " << lambda1(40, 60) << std::endl;
}

/**
 * C++17新特性lan
 *      1、支持初始化语句的if和switch
 *      2、constexpr if条件编译。它可以在编译阶段，根据模板参数的值编译相应的段落。与普通的if相比，
 *          好处是避免生成多余的if…else…条件判断分支，影响效率。坏处是会使生成的文件变大。
 *
 *         constexpr用于lambda表达式返回值
 * @return
 */
 int main() {
    initIfSwitchTest();
    constexprTest();
    return 0;
}
