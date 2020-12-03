//
// Created by WebbDong on 8/20/2020.
//

#ifndef INC_9_MEMORY_CAR_H
#define INC_9_MEMORY_CAR_H

#include <iostream>
#include <string>

class Car {
private:
    std::string brand;
    int seatNum;
    int horsePower;
    int torque;

public:
    Car();

    Car(const std::string &brand, int seatNum, int horsePower, int torque);

    const std::string &getBrand() const;

    void setBrand(const std::string &brand);

    int getSeatNum() const;

    void setSeatNum(int seatNum);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getTorque() const;

    void setTorque(int torque);

    void display();

    static void coutCarArray(Car *pArr, int m);

    static void coutCarMatrix(Car **pMatrix, int m, int n);
};

#endif //INC_9_MEMORY_CAR_H
