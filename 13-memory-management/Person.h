//
// Created by WebbDong on 8/22/2020.
//

#ifndef INC_13_MEMORY_MANAGEMENT_PERSON_H
#define INC_13_MEMORY_MANAGEMENT_PERSON_H

#include <string>
#include "Car.h"

class Person {
public:
    Person();

    Person(const std::string& name, int age);

    Person(const std::string& name, int age, Car* car);

    virtual ~Person();

    const std::string& getName() const;

    void setName(const std::string& name);

    int getAge() const;

    void setAge(int age);

    Car* getCar() const;

    void setCar(Car* car);

    void display();

private:
    std::string name;
    int age;
    Car* car;
};

#endif //INC_13_MEMORY_MANAGEMENT_PERSON_H
