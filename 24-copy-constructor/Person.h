//
// Created by WebbDong on 8/29/2020.
//

#ifndef INC_24_COPY_CONSTRUCTOR_PERSON_H
#define INC_24_COPY_CONSTRUCTOR_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        Person(const std::string& name = "", int age = 0);

        Person(const Person& person);

        virtual ~Person();

        virtual void sayHello();

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        std::string name;
        int age;
    };

}

#endif //INC_24_COPY_CONSTRUCTOR_PERSON_H
