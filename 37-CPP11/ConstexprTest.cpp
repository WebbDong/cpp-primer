//
// Created by WebbDong on 9/18/2020.
//
#include <iostream>
#include <string>
#include <array>

#include "ConstexprTest.h"

namespace dwb {

    // constexpr修饰类的构造函数
    constexpr int constexprFunc() {
        return 5 + 10 + 20;
    }

    const int constFunc() {
        return 5 + 10 + 20;
    }

    class MyClass1 {
    public:
        constexpr MyClass1(char* str, int num) : str(str), num(num) {}

        void display() {
            std::cout << "str = " << str << ", num = " << num << std::endl;
        }

        constexpr int getNum() const {
            return num;
        }

    private:
        char* str;
        int num;
    };

    template<typename T>
    constexpr T templateFunc(T t) {
        return t;
    }

    /**
     * constexpr：验证是否为常量表达式
     *      constexpr 关键字的功能是使指定的常量表达式获得在程序编译阶段计算出结果的能力，而不必等到程序运行阶段。C++ 11 标准中，
     *      constexpr 可用于修饰普通变量、函数（包括模板函数）以及类的构造函数。注意，获得在编译阶段计算出结果的能力，
     *      并不代表 constexpr 修饰的表达式一定会在程序编译阶段被执行，具体的计算时机还是编译器说了算。
     *
     *      1、constexpr修饰普通变量
     *          定义变量时可以用 constexpr 修饰，从而使该变量获得在编译阶段即可计算出结果的能力。
     *      2、constexpr修饰函数
     *          constexpr 还可以用于修饰函数的返回值，这样的函数又称为“常量表达式函数”。
     *          constexpr 并非可以修改任意函数的返回值。换句话说，一个函数要想成为常量表达式函数，必须满足如下 4 个条件。
     *              1) 整个函数的函数体中，除了可以包含 using 指令、typedef 语句以及 static_assert 断言外，只能包含一条 return 返回语句。
     *              2) 该函数必须有返回值，即函数的返回值类型不能是 void。
     *              3) 函数在使用之前，必须有对应的定义语句。我们知道，函数的使用分为“声明”和“定义”两部分，
     *                  普通的函数调用只需要提前写好该函数的声明部分即可（函数的定义部分可以放在调用位置之后甚至其它文件中），
     *                  但常量表达式函数在使用前，必须要有该函数的定义。
     *              4) return 返回的表达式必须是常量表达式
     *      3、constexpr修饰类的构造函数
     *          constexpr 修饰类的构造函数时，要求该构造函数的函数体必须为空，且采用初始化列表的方式为各个成员赋值时，必须使用常量表达式。
     *      4、constexpr修饰类的成员函数
     *          constexpr 也可以修饰类中的成员函数，只不过此函数必须满足前面提到的 4 个条件。
     *          注意，C++11 标准中，不支持用 constexpr 修饰带有 virtual 的成员函数。
     *      5、constexpr修饰模板函数
     *          C++11 中，constexpr 可以修饰模板函数，但由于模板中类型的不确定性，因此模板函数实例化后的函数是否符合常量表达式函数的要求也是不确定的。
     *          针对这种情况下，C++11 标准规定，如果 constexpr 修饰的模板函数实例化结果不满足常量表达式函数的要求，则 constexpr 会被自动忽略，即该函数就等同于一个普通函数。
     *      6、constexpr和const的区别：
     *          void dis_1(const int x){
     *              //错误，x是只读的变量
     *              array <int,x> myarr{1,2,3,4,5};
     *              cout << myarr[1] << endl;
     *          }
     *
     *          void dis_2(){
     *              const int x = 5;
     *              array <int,x> myarr{1,2,3,4,5};
     *              cout << myarr[1] << endl;
     *          }
     *
     *          dis_1() 函数中的“const int x”只是想强调 x 是一个只读的变量，其本质仍为变量，无法用来初始化 array 容器；
     *          而 dis_2() 函数中的“const int x”，表明 x 是一个只读变量的同时，x 还是一个值为 5 的常量，所以可以用来初始化 array 容器。
     *
     *          C++ 11标准中，为了解决 const 关键字的双重语义问题，保留了 const 表示“只读”的语义，而将“常量”的语义划分给了新添加的 constexpr 关键字。
     *          因此 C++11 标准中，建议将 const 和 constexpr 的功能区分开，即凡是表达“只读”语义的场景都使用 const，表达“常量”语义的场景都使用 constexpr。
     */
    void ConstexprTest::test() {
        // constexpr修饰普通变量
        constexpr int num = 50 + 60 + 80;
        std::cout << "num = " << num << std::endl;

        // constexpr修饰函数
        constexpr int resNum = constexprFunc();
        std::cout << "constexprFunc() = " << constexprFunc() << std::endl;
        std::cout << "resNum = " << resNum << std::endl;

        constexpr MyClass1 mc1("Adam", 500);
        std::cout << "mc1.getNum() = " << mc1.getNum() << std::endl;

        constexpr int res1 = templateFunc(7000);
        std::cout << "res1 = " << res1 << std::endl;

        constexpr auto res2 = templateFunc(9000);
        std::cout << "res2 = " << res2 << std::endl;

        // 可以使用constexpr返回值的函数作为泛型参数
        std::array<int, constexprFunc()> array1;
        // 不可以使用const返回值的函数作为泛型参数
//        std::array<int, constFunc()> array2;
    }

}