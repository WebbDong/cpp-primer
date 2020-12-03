//
// Created by WebbDong on 9/4/2020.
//

#ifndef INC_36_CPP11_PERSON_H
#define INC_36_CPP11_PERSON_H

#include <iostream>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name, int age);

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

        friend std::ostream& operator<<(std::ostream& cout, const Person& p);

        static int staticNumber;

    private:
        std::string name;
        int age;
    };

}

#endif //INC_36_CPP11_PERSON_H
