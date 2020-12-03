//
// Created by WebbDong on 8/22/2020.
//

#ifndef INC_13_MEMORY_MANAGEMENT_CAR_H
#define INC_13_MEMORY_MANAGEMENT_CAR_H

#include <string>

class Car {
public:
    Car();

    Car(const std::string& brand, const std::string& model, int horsePower, int torque, int seatNum);

    const std::string& getBrand() const;

    void setBrand(const std::string& brand);

    const std::string& getModel() const;

    void setModel(const std::string& model);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getTorque() const;

    void setTorque(int torque);

    int getSeatNum() const;

    void setSeatNum(int seatNum);

private:
    std::string brand;
    std::string model;
    int horsePower;
    int torque;
    int seatNum;
};


#endif //INC_13_MEMORY_MANAGEMENT_CAR_H
