#include <iostream>

using namespace std;

void func1(int a, double b) {
    cout << "void func1(int a, double b)" << endl;
}

void func1(double a, int b) {
    cout << "void func1(double a, int b)" << endl;
}

void test(long l) {
    cout << l << endl;
}

void test(double d) {
    cout << d << endl;
}

/**
    函数重载
        1、C语言不支持函数重载
        2、函数重载与函数返回值无关
        3、调用存在函数重载的函数，实参的隐式类型转换可能会产生二义性
 * @return
 */
int main() {
    func1(20, 20.5);
    func1(20.5, 20);

    // 会产生二义性，同时可以调用test(long)和test(double)，int同时可以隐式转换成long和double
    //test(10);
    test(10.0);
    test(10L);
    return 0;
}