//
// Created by WebbDong on 9/1/2020.
//
#include <iostream>

#include "Student.h"

namespace dwb {

    Student::Student(const std::string& name, int age, float score) : Person(name, age), score(score) {}

    Student& Student::operator=(const Student& student) {
        // 调用父类的赋值运算符重载函数
        Person::operator=(student);
        score = student.score;
        return *this;
    }

    void Student::display() {
        std::cout << "name = " << getName() << ", age = " << getAge() << ", score = " << score << std::endl;
    }

}