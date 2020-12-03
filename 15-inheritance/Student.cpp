//
// Created by WebbDong on 8/24/2020.
//
#include <iostream>
#include "Student.h"

namespace dwb {

    Student::Student() {}

    Student::Student(const std::string& name, int age, int height, float score)
            : Person(name, age, height), score(score) {}

    void Student::study() {
        std::cout << "Studying" << std::endl;
    }

}
