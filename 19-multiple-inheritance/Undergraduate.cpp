//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "Undergraduate.h"

namespace dwb {

    // Person基类的初始化必须调用Person基类的构造函数，如果没有使用虚继承，将无法调用Person基类的构造函数
    Undergraduate::Undergraduate(const std::string& name, int age, int height, float score, float salary, int grade)
        : Person(name, age, height), Student(score), Worker(salary), grade(grade) {
        std::cout << "Undergraduate::Undergraduate(const std::string& name, int age, int height,"
                  << " float score, float salary, int grade)" << std::endl;
    }

    Undergraduate::~Undergraduate() {
        std::cout << "Undergraduate::~Undergraduate()" << std::endl;
    }

    void Undergraduate::run() {
        std::cout << "Undergraduate::run()" << std::endl;
    }

    void Undergraduate::dissert() {
        std::cout << "grade = " << grade << std::endl;
    }

    int Undergraduate::getGrade() const {
        return grade;
    }

    void Undergraduate::setGrade(int grade) {
        Undergraduate::grade = grade;
    }

}