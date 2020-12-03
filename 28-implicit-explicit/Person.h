//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_28_IMPLICIT_EXPLICIT_PERSON_H
#define INC_28_IMPLICIT_EXPLICIT_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:

        Person();

        Person(const std::string& name);

        Person(int age);

        ~Person();

        void sayHello();

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;
        int age;
    };

}

#endif //INC_28_IMPLICIT_EXPLICIT_PERSON_H
