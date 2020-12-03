//
// Created by WebbDong on 8/25/2020.
//

#include <iostream>

#include "EliteStudent.h"

namespace dwb {

    EliteStudent::EliteStudent(const std::string& name, int age, int height, float score, float scholarship)
            : Student(name, age, height, score), scholarship(scholarship) {
        std::cout << "EliteStudent::EliteStudent(const std::string& name, int age, int height, float score, float scholarship)"
                  << std::endl;
    }

    EliteStudent::~EliteStudent() {
        std::cout << "EliteStudent::~EliteStudent()" << std::endl;
    }

    void EliteStudent::dissert() {
        std::cout << "scholarship = " << scholarship << std::endl;
    }

}