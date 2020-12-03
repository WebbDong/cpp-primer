//
// Created by WebbDong on 11/15/2020.
//
#include <iostream>

#include "Student.h"

Student::Student(const std::string& name, int age, int height, float score)
        : Person(name, age, height), score(score) {}

Student::~Student() {
    std::cout << "~Student()" << std::endl;
}

void Student::display() {
    std::cout << "age = " << this->getAge() << " height = " << this->getHeight()
              << " name = " << this->getName() << " score = " << score << std::endl;
}