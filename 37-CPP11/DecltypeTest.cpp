//
// Created by WebbDong on 9/4/2020.
//
#include <iostream>
#include <vector>

#include "model/Person.h"
#include "DecltypeTest.h"

namespace dwb {

    template<typename T>
    class TestClass {
    public:
        void func(T& container) {
            iterator = container.begin();
        }
    private:
        // 使用泛型内部类iterator定义成员变量iterator
        // 注意这里
        typename T::iterator iterator;
    };

    template<typename T>
    class TestClass2 {
    public:
        void func(T& container) {
            iterator = container.begin();
        }

    private:
        // 根据泛型参数的成员函数begin返回的类型来推导当作成员变量iterator的类型
        decltype(T().begin()) iterator;
    };

    int func() {
        std::cout << "int func()" << std::endl;
        return 200;
    }

    /**
     * decltype类型推导
     *      decltype 关键字是为了解决 auto 关键字只能对变量进行类型推导的缺陷而出现的。decltype类型推导可以不初始化变量
     *      语法：decltype(exp) varname;
     *      exp 注意事项：
     *          原则上讲，exp 就是一个普通的表达式，它可以是任意复杂的形式，但是我们必须要保证 exp 的结果是有类型的，不能是 void；
     *          例如，当 exp 调用一个返回值类型为 void 的函数时，exp 的结果也是 void 类型，此时就会导致编译错误。
     *          当exp是函数调用时，不会真的去执行该函数。
     *
     * decltype 推导规则
     *      1、如果 exp 是一个不被括号( )包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，
     *          那么 decltype(exp) 的类型就和 exp 一致，这是最普遍最常见的情况。
     *      2、如果 exp 是函数调用，那么 decltype(exp) 的类型就和函数返回值的类型一致。
     *      3、如果 exp 是一个左值，或者被括号( )包围，那么 decltype(exp) 的类型就是 exp 的引用
     *
     * decltype 的实际应用
     *      1、用于非静态成员变量
     */
    void DecltypeTest::test() {
        int x = 9999;
        const int constNum = 666;
        const int& refNum = x;
        decltype(10) num1;                      // 推导为int
        num1 = 800;
        decltype(x) num2 = 7777;                // 推导为int
        decltype(10.1) num3 = 40.5;             // 推导为double
        decltype(x + 800) num4;                 // 推导为int
        decltype(constNum) constNum5 = 999;     // 推导为const int
        decltype(&x) pNum6 = &num1;             // 推导为int*
        decltype(refNum) refNum7 = num1;        // 推导为const int&
        std::cout << "num1 = " << num1 << std::endl;
        std::cout << "num2 = " << num2 << std::endl;
        std::cout << "num3 = " << num3 << std::endl;
        std::cout << "num4 = " << num4 << std::endl;
        std::cout << "constNum5 = " << constNum5 << std::endl;
        std::cout << "pNum6 = " << pNum6 << ", *pNum6 = " << *pNum6 << std::endl;
        std::cout << "refNum7 = " << refNum7 << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        dwb::Person person1("Adam", 25);
        dwb::Person person3("Conner", 55);
        dwb::Person& refPerson1 = person1;
        decltype(dwb::Person::staticNumber) num8 = 5006;                    // 推导为int
        // 不会去真的执行int func()函数
        decltype(func()) num9 = 6524;                                       // 推导为int
        decltype(person1) person2("Lisa", 30);                    // 推导为dwb::Person
        decltype(&person1) pPerson1 = new Person("John", 33);     // 推导为dwb::Person*
        decltype(refPerson1) refPerson2 = person3;                          // 推导为dwb::Person&
        std::cout << "num8 = " << num8 << std::endl;
        std::cout << "num9 = " << num9 << std::endl;
        std::cout << "pPerson1 = " << pPerson1 << ", *pPerson1 = " << *pPerson1 << std::endl;
        std::cout << "refPerson2 = " << refPerson2 << std::endl;
        delete pPerson1;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        int num10 = 9000;
        int num11 = 600000;
        int n = 5555;
        decltype(num10) num12 = 100000;             // 推导为int
        decltype((num10)) refNum2 = num11;          // 推导为int&，因为exp被()包起来
        decltype(num10 + num11) num13 = 300000;     // 推导为int
        // exp表达式不会改变变量n的值
        decltype(n = num10 + num11) refNum3 = n;    // 推导为int&，因为exp结果是一个左值
        std::cout << "&num10 = " << &num10 << ", num10 = " << num10 << std::endl;
        std::cout << "&num11 = " << &num11 << ", num11 = " << num11 << std::endl;
        std::cout << "&num12 = " << &num12 << ", num12 = " << num12 << std::endl;
        std::cout << "&refNum2 = " << &refNum2 << ", refNum2 = " << refNum2 << std::endl;
        std::cout << "&num13 = " << &num13 << ", num13 = " << num13 << std::endl;
        std::cout << "&n = " << &n << ", n = " << n << std::endl;
        std::cout << "&refNum3 = " << &refNum3 << ", refNum3 = " << refNum3 << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        const std::vector<int> v;
        // 当泛型参数时const std::vector时，由于TestClass使用的泛型参数内部类是iterator，但只能调用
        // const的begin，返回const_iterator。需要的是const_iterator迭代器
        // 使用decltype来定义变量可以解决此问题
//        TestClass<const std::vector<int>> obj;
//        obj.func(v);

        TestClass2<const std::vector<int>> obj;
        obj.func(v);
    }

}