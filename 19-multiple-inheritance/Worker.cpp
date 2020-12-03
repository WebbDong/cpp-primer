//
// Created by WebbDong on 8/28/2020.
//
#include <iostream>

#include "Worker.h"

namespace dwb {

    Worker::Worker(const std::string& name, int age, int height, float salary)
        : Person(name, age, height), salary(salary) {
        std::cout << "Worker::Worker(const std::string& name, int age, int height, float salary)" << std::endl;
    }

    Worker::Worker(float salary) : salary(salary) {
        std::cout << "Worker::Worker(float salary)" << std::endl;
    }

    Worker::~Worker() {
        std::cout << "Worker::~Worker()" << std::endl;
    }

    void Worker::run() {
        std::cout << "Worker::run()" << std::endl;
    }

    void Worker::work() {
        std::cout << "salary = " << salary << std::endl;
    }

    float Worker::getSalary() const {
        return salary;
    }

    void Worker::setSalary(float salary) {
        Worker::salary = salary;
    }

}