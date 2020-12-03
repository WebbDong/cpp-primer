//
// Created by WebbDong on 8/20/2020.
//

#include "Car.h"

Car::Car(const std::string &brand, int seatNum, int horsePower, int torque)
        : brand(brand), seatNum(seatNum), horsePower(horsePower), torque(torque) {}

Car::Car() : brand(""), seatNum(0), horsePower(0), torque(0) {}

const std::string &Car::getBrand() const {
    return brand;
}

void Car::setBrand(const std::string &brand) {
    Car::brand = brand;
}

int Car::getSeatNum() const {
    return seatNum;
}

void Car::setSeatNum(int seatNum) {
    Car::seatNum = seatNum;
}

int Car::getHorsePower() const {
    return horsePower;
}

void Car::setHorsePower(int horsePower) {
    Car::horsePower = horsePower;
}

int Car::getTorque() const {
    return torque;
}

void Car::setTorque(int torque) {
    Car::torque = torque;
}

void Car::display() {
    std::cout << "brand = " << Car::brand << " seatNum = " << Car::seatNum << " horsePower = " << Car::horsePower
              << " torque = " << Car::torque << std::endl;
}

void Car::coutCarArray(Car *pArr, int m) {
    for (int i = 0; i < m; i++) {
        Car car = pArr[i];
        std::cout << "brand = " << car.getBrand() << " seatNum = " << car.getSeatNum()
                  << " horsePower = " << car.getHorsePower() << " torque = " << car.getTorque() << std::endl;
    }
    std::cout << std::endl;
}

void Car::coutCarMatrix(Car **pMatrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Car car = pMatrix[i][j];
            std::cout << "brand = " << car.getBrand() << " seatNum = " << car.getSeatNum()
                      << " horsePower = " << car.getHorsePower() << " torque = " << car.getTorque() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
