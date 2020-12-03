//
// Created by WebbDong on 9/1/2020.
//

#include "Person.h"

namespace dwb {

    Person::Person() {}

    Person::Person(const std::string& name, int age, int height) : name(name), age(age), height(height) {}

    Person Person::operator+(const Person& p) {
        return Person(name, age + p.age, height + p.height);
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

    int Person::getHeight() const {
        return height;
    }

    void Person::setHeight(int height) {
        Person::height = height;
    }

    std::ostream& operator<<(std::ostream& cout, const Person& p) {
        return cout << "(" << "name = " << p.name << ", age = " << p.age
                    << ", height = " << p.height << ")";
    }

}