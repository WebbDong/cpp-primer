#include <iostream>
#include <cmath>

#include "Person.h"
#include "TemplateTest.h"
#include "MyVector.hpp"

// 函数模板
template<typename T>
T add(T a, T b) {
    return a + b;
}

// 多参数函数模板
template<typename A, typename B>
A subtraction(A a, B b) {
    return a + b;
}

class Class1 {
public:
    static int get() {
        return 8888;
    }

    int func() {
        return 666;
    }
};

class Class2 {
public:
    static std::string get() {
        return "Class2 static std::string get()";
    }

    std::string func() {
        return "Class2 std::string func()";
    }
};

// 模板参数可以明确类型，但只限于char、int、long、枚举这些整型类型，只能传入常量
template<typename T, int SIZE>
class FixedSizeBuffer {
public:
    FixedSizeBuffer() : size(SIZE) {}

private:
    T buffer[SIZE];
    int size;
};

// 模板参数默认类型
template<typename T = double>
class Point {
public:
    Point<T>(T x, T y) : x(x), y(y) {}

    T distance() {
        return sqrt(x * x + y * y);
    }

private:
    T x;
    T y;
};

template<typename T>
void templateParamCallStaticFunc() {
    // 模板参数调用类静态方法
    auto data1 = T::get();
    std::cout << "templateParamCallStaticFunc() ---- T::get() = " << data1 << std::endl;

    // 模板参数实例化对象并且调用func方法
    auto data2 = T().func();
    std::cout << "templateParamCallStaticFunc() ---- T().func() = " << data2 << std::endl;
}

void MyVectorTest() {
    dwb::MyVector<int> vector1;
    for (auto i = 1; i <= 10; i++) {
        vector1.add(i);
    }
    std::cout << "vector1 = " << vector1 << std::endl;
    vector1.insert(5, 8888);
    std::cout << "vector1 = " << vector1 << std::endl;
    vector1.set(10, 6666);
    std::cout << "vector1 = " << vector1 << std::endl;
    vector1.add(9999);
    std::cout << "vector1 = " << vector1 << std::endl;
    vector1.remove(0);
    std::cout << "vector1 = " << vector1 << std::endl;
    std::cout << "vector1.get(vector1.getSize() - 1) = " << vector1.get(vector1.getSize() - 1) << std::endl;
    std::cout << "vector1[0] = " << vector1[0] << std::endl;
    vector1.clear();
    std::cout << vector1 << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    dwb::MyVector<dwb::Person> vector2;
    vector2.add(dwb::Person("Adam", 20, 180));
    vector2.add(dwb::Person("Conner", 30, 185));
    std::cout << vector2 << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    dwb::MyVector<int*> vector3;
    int num1 = 500;
    int num2 = 600;
    vector3.add(&num1);
    vector3.add(&num2);
    int* pNum1 = new int(700);
    vector3.add(pNum1);
    std::cout << vector3 << std::endl;
    std::cout << *vector3[0] << ", " << *vector3[1] << ", " << *vector3[2] << std::endl;
    delete pNum1;
    std::cout << "----------------------------------------------------" << std::endl;

    dwb::MyVector<dwb::Person*> vector4;
    dwb::Person* pPerson1 = new dwb::Person("Lisa", 40, 170);
    vector4.add(pPerson1);
    dwb::Person person1("John", 25, 190);
    vector4.add(&person1);
    std::cout << vector4 << std::endl;
    std::cout << *vector4[0] << *vector4[1] << std::endl;
    delete pPerson1;
}

/**
 * 模板
 *      1、泛型，是一种将类型参数化以达到代码复用的技术，C++中使用模板来实现泛型
 *      2、模板的使用格式如下：
 *          template <typename\class T>
 *          typename和class是等价的
 *      3、模板没有被使用时，是不会被实例化出来的
 *      4、模板的声明和实现如果分离到.h和.cpp中，会导致链接错误，可以在头文件，显示指定泛型类型的类声明，但是需要所有类型都有一一声明，不实用。
 *          有的编译器可以使用.tpp文件，但一般将模板的声明和实现统一放到一个.hpp文件中
 *      5、可以定义函数模板，类模板
 *      6、模板参数可以明确类型，但只限于char、int、long、枚举这些整型类型，只能传入常量
 *      7、模板参数可以指定默认类型
 *      8、模板的原理是编译器会根据泛型类型或参数类型生成不同的多个最终目标函数，必须有使用到，被调用时才会生成。
 */
int main() {
    std::cout << "add(10, 30) = " << add(10, 30) << std::endl;

    // 指明泛型类型
    std::cout << "add<double>(20.5, 60.6) = " << add<double>(20.5, 60.6) << std::endl;
    dwb::Person p1("Adam", 20, 170);
    dwb::Person p2("Conner", 15, 140);
    std::cout << "add<dwb::Person>(p1, p2) = " << add<dwb::Person>(p1, p2);

    std::cout << "subtraction(10, 50.8) = " << subtraction(10, 50.8) << std::endl;
    std::cout << "subtraction<double, int>(80.5, 40) = " << subtraction<double, int>(80.5, 40) << std::endl;

    dwb::TemplateTest<int> templateTest1(500);
    std::cout << "templateTest1.division(8, 4) = " << templateTest1.division(8, 4) << std::endl;

    dwb::TemplateTest<long> templateTest2(900L);
    std::cout << "templateTest2.division(800L, 400L) = " << templateTest2.division(800L, 400L) << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    MyVectorTest();

    templateParamCallStaticFunc<Class1>();
    templateParamCallStaticFunc<Class2>();

    const int SIZE = 30;
    FixedSizeBuffer<char, SIZE> line;
    FixedSizeBuffer<std::string, 10> sb;

    // 使用默认的double类型
    Point<> point1(20.5, 30.5);
    std::cout << "point1.distance() = " << point1.distance() << std::endl;
    Point<int> point2(20.5, 30.5);
    std::cout << "point2.distance() = " << point2.distance() << std::endl;
    return 0;
}
