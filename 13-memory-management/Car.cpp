//
// Created by WebbDong on 8/22/2020.
//

#include "Car.h"

Car::Car() : brand(""), model(""), horsePower(0), torque(0), seatNum(0) {}

Car::Car(const std::string& brand, const std::string& model, int horsePower, int torque, int seatNum)
        : brand(brand), model(model), horsePower(horsePower), torque(torque), seatNum(seatNum) {}

const std::string& Car::getBrand() const {
    return brand;
}

void Car::setBrand(const std::string& brand) {
    Car::brand = brand;
}

const std::string& Car::getModel() const {
    return model;
}

void Car::setModel(const std::string& model) {
    Car::model = model;
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

int Car::getSeatNum() const {
    return seatNum;
}

void Car::setSeatNum(int seatNum) {
    Car::seatNum = seatNum;
}
