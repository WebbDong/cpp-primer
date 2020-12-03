#include <iostream>
#include "math.h"

/*
extern "C" void fun1() {

}

extern "C" void fun1(int a) {

}

extern "C" {
    void fun2() {

    }

    void fun2(int a) {

    }
}
 */

extern "C" void otherTest();

/**
    extern "C"
        1、被extern "C"修饰的代码会按照C语言的方式进行编译
        2、如果函数同时有声明和实现，必须要让函数声明被extern "C"修饰，函数的实现可以不修饰
        3、通常用于C与C++混合开发，有些第三方库也是纯C写的，如果要在C++中使用就需要，因为C编译器和C++编译器编译完成后的函数
            名规则不同，如果不显示声明extern "C"，函数默认会做是C++函数，此时在链接时就会寻找不到C函数实现
        4、注意，C语言编译器不识别extern "C"
 *@return
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "sum(10, 30) = " << sum(10, 30) << std::endl;
    std::cout << "subtraction(40, 20) = " << subtraction(40, 20) << std::endl;
    otherTest();
    return 0;
}
