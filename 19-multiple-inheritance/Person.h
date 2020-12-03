//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_19_MULTIPLE_INHERITANCE_PERSON_H
#define INC_19_MULTIPLE_INHERITANCE_PERSON_H

#include "Consts.h"

namespace dwb {

    class Person {
    public:
        Person(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0);

        virtual ~Person();

        virtual void run() = 0;

        void sayHello();

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

        int getHeight() const;

        void setHeight(int height);

    public:
        std::string name;
        int age;
        int height;
    };

}

#endif //INC_19_MULTIPLE_INHERITANCE_PERSON_H
