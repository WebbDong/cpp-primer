//
// Created by WebbDong on 8/24/2020.
//
#include <iostream>
#include "Teacher.h"

namespace dwb {

    Teacher::Teacher() {}

    Teacher::Teacher(const std::string& name, int age, int height, float salary)
            : Person(name, age, height), salary(salary) {}

    void Teacher::teach() {
        std::cout << "Teaching" << std::endl;
    }

}