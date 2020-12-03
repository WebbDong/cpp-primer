//
// Created by WebbDong on 8/29/2020.
//
#include <iostream>

#include "Person.h"

namespace dwb {

    int Person::staticNumber = 8800;

    int& Person::staticRefNumber = Person::staticNumber;

//    Person::Person(int age) : age(age), refAge(Person::age) {}

    Person::Person(int age) : age(age), refAge(age) {}

    void Person::func() {
        std::cout << "Person::func() age = " << age << std::endl;
        std::cout << "Person::func() &age = " << &age << std::endl;
        std::cout << "Person::func() refAge = " << refAge << std::endl;
        std::cout << "Person::func() &refAge = " << &refAge << std::endl;
    }

    int Person::getAge() const {
        return age;
    }

    void Person::setAge(int age) {
        Person::age = age;
    }

    int& Person::getRefAge() const {
        return refAge;
    }

    void Person::setRefAge(int& refAge) {
        Person::refAge = refAge;
    }

}