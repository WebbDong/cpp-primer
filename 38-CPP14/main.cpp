#include <iostream>
#include <iomanip>

// 函数返回值类型推导
auto func(int x, int y) {
    return x + y;
}

// Lambda参数可以使用auto类型推导
void lambda() {
    auto lambda1 = [](auto x, auto y) {
        return x + y;
    };
    std::cout << "lambda1(60, 80) = " << lambda1(60, 80) << std::endl;
}

// 模板常量
template<typename T>
//constexpr T PI = 3.1415926535897932385L;
constexpr T PI = T(3.1415926535897932385L);

// 模板变量
template<typename T = double>
T templateNum = 600.5;

// 别名模板
template<typename T, typename R>
class Class1 {
public:
    T t;
    R r;
};

using NewClass1 = Class1<double, int>;

template<typename T>
using NewClass2 = Class1<T, double>;

// C++11中不可以，C++14中可以
constexpr int factorial(int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += i;
    }
    return ret;
}

// C++11中不可以，C++14中可以
constexpr int multiReturnFunc(bool flag) {
    if (flag) {
        return 400;
    } else {
        return 800;
    }
}

// [[deprecated]]标记
class [[deprecated]] Class2 {
public:
    [[deprecated]] void display() {
        std::cout << "display()" << std::endl;
    }

    [[deprecated]] int num;
};

/**
 * C++14新特性
 *      1、函数返回值类型推导
 *          函数内如果有多个return语句，它们必须返回相同的类型，否则编译失败。
 *          如果return语句返回初始化列表，返回值类型推导也会失败
 *          如果函数是虚函数，不能使用返回值类型推导
 *          返回类型推导可以用在递归函数中，但是递归调用必须以至少一个返回语句作为先导，以便编译器推导出返回类型。
 *      2、Lambda参数可以使用auto类型推导
 *      3、变量模板和常量模板
 *      4、别名模板
 *      5、constexpr增强
 *          constexpr返回值类型函数，可以返回函数内的局部变量
 *          constexpr返回值类型函数，可以有多个return语句
 *      6、[[deprecated]]标记
 *          C++14中增加了deprecated标记，修饰类、变量、函数等，当程序中使用到了被其修饰的代码时，编译时被产生警告，
 *          用户提示开发者该标记修饰的内容将来可能会被丢弃，尽量不要使用。
 *      7、二进制字面量与整形字面量分隔符
 *      8、C++14引入std::quoted用于给字符串添加双引号
 *      9、decltype(auto)可以用来声明变量以及定义函数返回类型。可以推导出对象类型，也可以推导出引用类型。
 * @return
 */
int main() {
    std::cout << "func(10, 20) = " << func(10, 20) << std::endl;

    lambda();

    std::cout << "PI<double> = " << PI<double> << ", PI<int> = " << PI<int> << std::endl;
    std::cout << "templateNum<double> = " << templateNum<double> << ", templateNum<int> = "
              << templateNum<int> << std::endl;

    // 模板变量不同的泛型类型参数，可以存储不同的值。分配一段连续的内存。
    templateNum<> = 90000.25;
    templateNum<int> = 458700;
    templateNum<float> = 65.5;
    std::cout << "templateNum<double> = " << templateNum<double> << ", templateNum<int> = " << templateNum<int>
              << ", templateNum<float> = " << templateNum<float> << std::endl;
    std::cout << "&templateNum<double> = " << &templateNum<double> << ", &templateNum<int> = " << &templateNum<int>
              << ", &templateNum<float>> = " << &templateNum<float> << std::endl;
    std::cout << "sizeof(templateNum<double>) = " << sizeof(templateNum<double>) << ", sizeof(templateNum<int>) = "
              << sizeof(templateNum<int>) << ", sizeof(templateNum<float>) = " << sizeof(templateNum<float>)
              << std::endl;
    int* pIntNum = &templateNum<int>;
    double* pDoubleNum = &templateNum<double>;
    float* pFloatNum = &templateNum<float>;
    std::cout << "pDoubleNum = " << pDoubleNum << ", *pDoubleNum = " << *pDoubleNum
              << ", pIntNum = " << pIntNum << ", *pIntNum = " << *pIntNum
              << ", pFloatNum = " << pFloatNum << ", *pFloatNum = " << *pFloatNum << std::endl;

    NewClass1 nc1;
    nc1.t = 89.9;
    nc1.r = 700;
    std::cout << "nc1.t = " << nc1.t << ", nc1.r = " << nc1.r << std::endl;

    NewClass2<int> nc2;
    nc2.t = 800;
    nc2.r = 96.5;
    std::cout << "nc2.t = " << nc2.t << ", nc2.r = " << nc2.r << std::endl;

    constexpr int r1 = factorial(10);
    std::cout << "factorial(10) = " << r1 << std::endl;

    constexpr int r2 = multiReturnFunc(true);
    std::cout << "multiReturnFunc(true) = " << r2 << std::endl;

    Class2 c2;
    c2.num = 8000;
    c2.display();

    int bin = 0b0001'0011'1010;
    double d = 3.14'1234'1234'1234;
    std::cout << "bin = " << bin << ", d = " << d << std::endl;

    std::string str1 = "Ferrari";
    std::cout << "std::quoted(str1) = " << std::quoted(str1) << std::endl;

    int& numRef1 = templateNum<int>;
    // auto1不是templateNum<int>的引用
    auto auto1 = numRef1;
    auto1 = 6666666;
    std::cout << "auto1 = " << auto1 << ", templateNum<int> = " << templateNum<int>
              << ", &auto1 = " << &auto1 << ", &templateNum<int> = " << &templateNum<int> << std::endl;
    // auto2为templateNum<int>的引用
    decltype(auto) auto2 = numRef1;
    auto2 = 8888888;
    std::cout << "auto2 = " << auto2 << ", templateNum<int> = " << templateNum<int>
              << ", &auto2 = " << &auto2 << ", &templateNum<int> = " << &templateNum<int> << std::endl;
    return 0;
}
