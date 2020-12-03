//
// Created by WebbDong on 8/25/2020.
//

#ifndef INC_16_INHERITANCE_CONSTRUCTOR_PERSON_H
#define INC_16_INHERITANCE_CONSTRUCTOR_PERSON_H

#include <string>

namespace dwb {

    const std::string UNKNOWN_NAME = "";

    class Person {
    public:
        Person();

        Person(const std::string& name, int age, int height);

        ~Person();

        void sayHello();

    private:
        std::string name;
        int age;
        int height;
    };

}

#endif //INC_16_INHERITANCE_CONSTRUCTOR_PERSON_H
