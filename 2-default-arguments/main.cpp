#include <iostream>

int AGE = 6;

int sum(int a = 5, int b = AGE) {
    return a + b;
}

void test3(int a) {
    std::cout << "a = " << a * a << std::endl;
}

void test2(int a) {
    std::cout << "a = " << a << std::endl;
}

void test(int v, void(*p)(int) = test2) {
    p(v);
}

// ------------------------函数重载和默认参数冲突start-----------------------------
void display(int a, int b = 20) {
    std::cout << "a is " << a << std::endl;
}

void display(int a) {
    std::cout << "a is " << a << std::endl;
}
// ------------------------函数重载和默认参数冲突end-------------------------------

/**
    C++默认参数
        1、默认参数只能按照从右到左的顺序
        2、如果函数同时有声明和实现，默认参数只能放在函数声明中
        3、默认参数值可以是常量、全局符号(全局变量、函数名)
        4、如果函数的实参经常是同一个值，可以考虑使用默认参数
        5、函数重载和默认参数可能会产生冲突、二义性(建议优先选用默认参数)
 * @return
 */
int main() {
    std::cout << sum() << std::endl;
    std::cout << sum(10) << std::endl;
    std::cout << sum(50, 100) << std::endl;
    test(200);
    test(200, test3);

    // 当第一个display的参数b有默认值时，此时将不知道调用哪个display函数，产生冲突与二义性
//    display(10);
    return 0;
}
