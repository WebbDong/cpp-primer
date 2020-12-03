//
// Created by WebbDong on 9/1/2020.
//

#ifndef INC_32_OPERATOR_OVERLOAD_PERSON_H
#define INC_32_OPERATOR_OVERLOAD_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name, int age);

        virtual ~Person();

        virtual void display();

        bool operator>=(const Person& p);

        bool operator<=(const Person& p);

        bool operator>(const Person& p);

        bool operator<(const Person& p);

        Person& operator=(const Person& p);

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;
        int age;
    };

}

#endif //INC_32_OPERATOR_OVERLOAD_PERSON_H
