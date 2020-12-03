//
// Created by WebbDong on 8/30/2020.
//
#include <iostream>

#include "Student.h"

namespace dwb {

    Student::Student(const std::string& name, int age, float score)
        : Person(name, age), score(score) {
        std::cout << "Student::Student(const std::string& name, int age, float score)" << std::endl;
    }

    Student::Student(const dwb::Student& student)
        : Person(student), score(student.score) {
        std::cout << "Student::Student(const dwb::Student& student)" << std::endl;
    }

    void Student::sayHello() {
        std::cout << "name = " << Person::getName() << ", age = " << Person::getAge()
                  << ", score = " << score << std::endl;
    }

    float Student::getScore() const {
        return score;
    }

    void Student::setScore(float score) {
        Student::score = score;
    }

}