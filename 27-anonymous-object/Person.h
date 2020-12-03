//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_27_ANONYMOUS_OBJECT_PERSON_H
#define INC_27_ANONYMOUS_OBJECT_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name = "", int age = 0);

        Person(const Person& person);

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

#endif //INC_27_ANONYMOUS_OBJECT_PERSON_H
