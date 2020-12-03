#include <iostream>
#include <vector>

#include "Person.hpp"

/**
 * 类成员函数的函数指针
 */
void classMemberFuncPointer() {
    // 指向类静态成员函数的函数指针，静态成员函数取地址时前面可以不加&
    void (*pFunc1)() = &dwb::Person<>::staticFunc;
    pFunc1();
    (*pFunc1)();

    dwb::Person<> person1("Adam", 26);
    dwb::Person<>* pPerson2 = new dwb::Person<>("Conner", 40);
    // 指向类非静态成员函数的函数指针，指针定义时必须指定类的域限定，非静态成员函数取地址时前面必须加上&
    void (dwb::Person<>::*pFunc2)() = &dwb::Person<>::display;
    // 非静态成员函数，需要对象才能调用
    (person1.*pFunc2)();
    (pPerson2->*pFunc2)();
    delete pPerson2;
}

// 使用using定义模板函数指针别名，C++11特性。不可以定义在函数中，可以定义在类中。
template<typename T>
using TemplateFuncPointer = T (*)(T, T);

// 模板函数指针，不可以定义在函数中
template<typename T>
T (*pTemplateFunc)(T, T);

// 使用typedef定义模板函数指针别名
template<typename T>
class TemplateFuncPointerByTypedef {
public:
    typedef T (*Type)(T, T);
};

template<typename T>
T add(T a, T b) {
    return a + b;
}

/**
 * 模板函数指针
 */
void templateFuncPointer() {
    pTemplateFunc<int> = add;
    int res1 = pTemplateFunc<int>(70, 90);
    std::cout << "pTemplateFunc<int>(70, 90) = " << res1 << std::endl;

    // 使用模板函数指针别名，使用时必须显式指定模板类型参数
    TemplateFuncPointer<int> pTemplateFunc1 = add;
    int res2 = pTemplateFunc1(50, 60);
    std::cout << "pTemplateFunc1(50, 60) = " << res2 << std::endl;

    dwb::Person<double>::TemplateFuncPointer pTemplateFunc2 = add;
    std::cout << "pTemplateFunc2(70.5, 88.6) = " << pTemplateFunc2(70.5, 88.6) << std::endl;

    dwb::Person<>::TemplateFuncPointer2<float> pTemplateFunc3 = add;
    std::cout << "pTemplateFunc3(11.2f, 35.6f) = " << pTemplateFunc3(11.2f, 35.6f) << std::endl;

    dwb::Person<>::staticNum = 800;
    std::cout << dwb::Person<>::staticNum << std::endl;

    dwb::Person<>::pStaticTemplateFunc = add;
    std::cout << "pStaticTemplateFunc(80, 100) = " << dwb::Person<>::pStaticTemplateFunc(80, 100) << std::endl;

    dwb::Person<> p;
    p.pTemplateFunc = add;
    std::cout << "p.pTemplateFunc(70, 5000) = " << p.pTemplateFunc(70, 5000) << std::endl;

    TemplateFuncPointerByTypedef<double>::Type pTemplateFunc4 = add;
    std::cout << "pTemplateFunc4(654.5, 50.88) = " << pTemplateFunc4(654.5, 50.88) << std::endl;
}

/**
 * 模板类对象指针
 */
void templateObjPointer() {
    std::vector<std::string> vector1;
    vector1.push_back("Ferrari");
    vector1.push_back("Lamborghini");

    std::vector<std::string>* pVector1 = &vector1;
    pVector1->push_back("Bugatti");
    std::cout << "(*pVector1)[0] = " << (*pVector1)[0] << std::endl;
    std::cout << "(*pVector1)[1] = " << (*pVector1)[1] << std::endl;
}

/**
 * C++指针专栏
 */
int main() {
//    classMemberFuncPointer();
//    templateFuncPointer();
    templateObjPointer();
    return 0;
}
