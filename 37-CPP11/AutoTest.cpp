//
// Created by WebbDong on 9/3/2020.
//
#include <iostream>
#include <vector>

#include "AutoTest.h"

namespace dwb {

    class Class1 {
    public:
        static int get() {
            return 9999;
        }
    };

    class Class2 {
    public:
        static std::string get() {
            return "Class2 std::string get()";
        }
    };

    template<typename T>
    void templateAutoFunc() {
        auto data = T::get();
        std::cout << data << std::endl;
    }

    template<typename T1, typename T2>
    void templateNoAutoFunc() {
        T2 data = T1::get();
        std::cout << data << std::endl;
    }


    /**
     * auto类型推导：
     *      在之前的 C++ 版本中，auto 关键字用来指明变量的存储类型，它和 static 关键字是相对的。auto 表示变量是自动存储的，
     *      这也是编译器的默认规则，所以写不写都一样。C++11 赋予 auto 关键字新的含义，使用它来做自动类型推导。
     *      使用了 auto 关键字以后，编译器会在编译期间自动推导出变量的类型。
     *
     * auto 的限制：
     *      1、使用 auto 的时候必须对变量进行初始化
     *      2、auto 不能在函数的参数中使用
     *      3、auto 不能作用于类的非静态成员变量（也就是没有 static 关键字修饰的成员变量）中。
     *      4、auto 不能定义数组
     *      5、auto 不能作用于模板参数  vector<auto> v; 是错误的
     *
     * auto 的应用：
     *      1、使用 auto 定义迭代器
     *      2、auto 用于泛型编程
     */
    void AutoTest::test() {
        // 1、auto类型推导
        auto num = 100;                                 // 推导为int
        auto doubleNum = 50.5;                          // 推导为double
        auto pDoubleNum = &doubleNum;                   // 推导为double*
        auto url = "http://c.biancheng.net/cplus/";     // 推导为const char*
        std::cout << "&num = " << &num << ", num = " << num << std::endl;
        std::cout << "&doubleNum = " << &doubleNum << ", doubleNum = " << doubleNum << std::endl;
        std::cout << "pDoubleNum = " << pDoubleNum << ", *pDoubleNum = " << *pDoubleNum << std::endl;
        std::cout << "url = " << url << std::endl;
        std::cout << "--------------------------------------------" << std::endl;

        // 2、auto的高级用法
        // auto 除了可以独立使用，还可以和某些具体类型混合使用，这样 auto 表示的就是“半个”类型，而不是完整的类型。
        auto* pNum2 = &num;                       // 推导为int，结合*，最终类型为int*
        auto& refDoubleNum = doubleNum;           // 推导为double，结合&，最终类型为double&
        const auto constDoubleNum = doubleNum;    // 推导为double，结合const，最终类型为const double
        const auto& constRefNum1 = num;           // 推导为int，结合const与&，最终类型为const int&
        const auto& constRefNum2 = &num;          // 推到为int，但是赋值的是&num是地址，所以&被忽略，最终类型为const int*
        std::cout << "pNum2 = " << pNum2 << ", *pNum2 = " << *pNum2 << std::endl;
        refDoubleNum = 150.5;
        std::cout << "&refDoubleNum = " << &refDoubleNum << ", refDoubleNum = " << refDoubleNum << ", doubleNum = " << doubleNum << std::endl;
        std::cout << "&constDoubleNum = " << &constDoubleNum << ", constDoubleNum = " << constDoubleNum << std::endl;
        std::cout << "&constRefNum1 = " << &constRefNum1 << ", constRefNum1 = " << constRefNum1 << std::endl;
        std::cout << "constRefNum2 = " << constRefNum2 << ", *constRefNum2 = " << *constRefNum2 << std::endl;
        std::cout << "--------------------------------------------" << std::endl;

        // 3、auto的应用
        // 使用 auto 定义迭代器
        std::vector<int> vector1;
        vector1.push_back(100);
        vector1.push_back(200);
        vector1.push_back(300);
        vector1.push_back(400);
//        std::vector<int>::const_iterator iter = vector1.cbegin();
        auto iter = vector1.cbegin();
        do {
            std::cout << *iter << " ";
            iter++;
        } while (iter != vector1.cend());
        std::cout << std::endl;

        // auto 用于泛型编程
        templateAutoFunc<Class1>();
        templateAutoFunc<Class2>();

        // 泛型不用auto的例子
        templateNoAutoFunc<Class1, int>();
        templateNoAutoFunc<Class2, std::string>();
    }

}