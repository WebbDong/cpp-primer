//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "Student.h"

namespace dwb {

    Student::Student(const std::string& name, int age, int height, float score)
        : Person(name, age, height), score(score) {
        std::cout << "Student::Student(const std::string& name, int age, int height, float score)" << std::endl;
    }

    Student::Student(float score) : score(score) {
        std::cout << "Student::Student(float score)" << std::endl;
    }

    Student::~Student() {
        std::cout << "Student::~Student()" << std::endl;
    }

    void Student::run() {
        std::cout << "Student::run()" << std::endl;
    }

    void Student::study() {
        std::cout << "score = " << score << std::endl;
    }

    float Student::getScore() const {
        return score;
    }

    void Student::setScore(float score) {
        Student::score = score;
    }

}