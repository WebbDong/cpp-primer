//
// Created by WebbDong on 9/1/2020.
//

#ifndef INC_33_TEMPLATE_PERSON_H
#define INC_33_TEMPLATE_PERSON_H

#include <iostream>
#include <string>

namespace dwb {

    class Person {
    public:
        Person();

        Person(const std::string& name, int age, int height);

        Person operator+(const Person& p);

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

        int getHeight() const;

        void setHeight(int height);

        friend std::ostream& operator<<(std::ostream& cout, const Person& p);

    private:
        std::string name;
        int age;
        int height;
    };

}

#endif //INC_33_TEMPLATE_PERSON_H
