//
// Created by WebbDong on 9/3/2020.
//

#include "Student.h"

namespace dwb {

    Student::Student(const std::string& name, int age, float score) : Person(name, age), score(score) {}

    void Student::display() {
        std::cout << "(" << "name = " << getName() << ", age = " << getAge() << ", score = " << score << ")";
    }

    std::ostream& operator<<(std::ostream& cout, const Student& s) {
        return cout << "(" << "name = " << s.getName() << ", age = " << s.getAge() << ", score = " << s.score << ")";
    }

}