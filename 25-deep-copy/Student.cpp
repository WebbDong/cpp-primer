//
// Created by WebbDong on 8/30/2020.
//
#include <iostream>

#include "Student.h"

namespace dwb {

    Student::Student(const char* name, int age, int height, float score)
        : Person(name, age, height), score(score) {}

    Student::Student(const dwb::Student& student) : Person(student), score(student.score) {}

    void Student::study() {
        std::cout << "score = " << score << std::endl;
    }

    void Student::run() {
        std::cout << "Student::run()" << std::endl;
    }

    float Student::getScore() const {
        return score;
    }

    void Student::setScore(float score) {
        Student::score = score;
    }

}