//
// Created by WebbDong on 8/25/2020.
//

#include <iostream>

#include "Teacher.h"

namespace dwb {

    Teacher::Teacher(const std::string& name, int age, int height, float salary)
            : Person(name, age, height), salary(salary) {
        std::cout << "Teacher::Teacher(const std::string& name, int age, int height, float salary)" << std::endl;
    }

    Teacher::~Teacher() {
        std::cout << "Teacher::~Teacher()" << std::endl;
    }

    void Teacher::teach() {
        std::cout << "salary = " << salary << std::endl;
    }

}