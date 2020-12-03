//
// Created by WebbDong on 9/3/2020.
//

#ifndef INC_34_TYPE_CAST_PERSON_H
#define INC_34_TYPE_CAST_PERSON_H

#include <string>
#include <iostream>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name, int age);

        virtual ~Person();

        virtual void display();

        friend std::ostream& operator<<(std::ostream& cout, const Person& p);

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;

        int age;
    };

}

#endif //INC_34_TYPE_CAST_PERSON_H
