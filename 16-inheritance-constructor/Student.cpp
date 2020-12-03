//
// Created by WebbDong on 8/25/2020.
//

#include <iostream>

#include "Student.h"

namespace dwb {

    Student::Student() : Student(UNKNOWN_NAME, 0, 0, 0.0f) {
        std::cout << "Student::Student()" << std::endl;
    }

    Student::Student(const std::string& name, int age, int height, float score)
            : Person(name, age, height), score(score) {
        std::cout << "Student::Student(const std::string& name, int age, int height, float score)" << std::endl;
    }

    Student::~Student() {
        std::cout << "Student::~Student()" << std::endl;
    }

    void Student::study() {
        std::cout << "score = " << score << std::endl;
    }

}