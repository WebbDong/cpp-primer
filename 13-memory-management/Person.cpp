//
// Created by WebbDong on 8/22/2020.
//

#include <iostream>
#include "Person.h"

Person::Person() : name(""), age(0), car(nullptr) {}

Person::Person(const std::string& name, int age) : name(name), age(age)
        , car(new Car("Ferrari", "LaFerrari", 963, 900, 2)) {}

Person::Person(const std::string& name, int age, Car* car) : name(name), age(age), car(car) {}

Person::~Person() {
    delete car;
}

const std::string& Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    Person::name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

Car* Person::getCar() const {
    return car;
}

void Person::setCar(Car* car) {
    Person::car = car;
}

void Person::display() {
    std::cout << "Hello, I'm " << name << " and " << age << " years old. I have a " << car->getBrand()
              << " " << car->getModel() << " " << car->getHorsePower() << " horse power" << std::endl;
}
