//
// Created by WebbDong on 9/3/2020.
//

#include "Person.h"

namespace dwb {

    Person::Person(const std::string& name, int age) : name(name), age(age) {}

    Person::~Person() {}

    void Person::display() {
        std::cout << "(" << "name = " << name << ", age = " << age << ")";
    }

    std::ostream& operator<<(std::ostream& cout, const Person& p) {
        return cout << "(" << "name = " << p.name << ", age = " << p.age << ")";
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

}