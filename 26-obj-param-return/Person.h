//
// Created by WebbDong on 8/30/2020.
//

#ifndef INC_26_OBJ_PARAM_RETURN_PERSON_H
#define INC_26_OBJ_PARAM_RETURN_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name = "", int age = 0);

        Person(const Person& person);

        void display();

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;
        int age;
    };

}

#endif //INC_26_OBJ_PARAM_RETURN_PERSON_H
