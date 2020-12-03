//
// Created by WebbDong on 8/23/2020.
//
#include <iostream>

#include "Car.h"

namespace dwb {

    Car::Car() {}

    Car::Car(int horsePower) : horsePower(horsePower) {}

    void Car::display() {
        std::cout << "horsePower = " << horsePower << std::endl;
    }

}
