//
// Created by WebbDong on 9/5/2020.
//

#ifndef INC_36_POINTER_PERSON_HPP
#define INC_36_POINTER_PERSON_HPP

#include <string>

namespace dwb {

    template<typename T = int>
    class Person {
    public:
        Person(const std::string& name = "", int age = 0);

        static void staticFunc();

        void display();

        // 模板函数指针类型别名，使用类的模板类型参数
        using TemplateFuncPointer = T (*)(T, T);

        static int staticNum;

        // 模板函数指针静态成员变量
        static T (*pStaticTemplateFunc)(T, T);

        // 模板函数指针成员变量
        T (*pTemplateFunc)(T, T);

        // 模板函数指针类型别名，使用自己的模板类型参数
        template<typename A> using TemplateFuncPointer2 = A (*)(A, A);

    private:
        std::string name;
        int age;
    };

    // 与访问权限无关，静态成员必须初始化。
    template<typename T> int Person<T>::staticNum = 0;

    // 与访问权限无关，静态成员必须初始化。
    template<typename T> T (*Person<T>::pStaticTemplateFunc)(T, T) = nullptr;

    template<typename T>
    Person<T>::Person(const std::string& name, int age) : name(name), age(age) {}

    template<typename T>
    void Person<T>::staticFunc() {
        std::cout << "void Person::staticFunc()" << std::endl;
    }

    template<typename T>
    void Person<T>::display() {
        std::cout << "name = " << name << ", age = " << age << std::endl;
    }

}

#endif //INC_36_POINTER_PERSON_HPP
