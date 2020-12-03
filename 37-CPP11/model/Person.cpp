//
// Created by WebbDong on 9/4/2020.
//

#include "Person.h"

namespace dwb {

    int Person::staticNumber = 458;

    Person::Person(const std::string& name, int age) : name(name), age(age) {}

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

    std::ostream& operator<<(std::ostream& cout, const Person& p) {
        return cout << "(name = " << p.name << ", age = " << p.age << ")";
    }

}