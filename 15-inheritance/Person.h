//
// Created by WebbDong on 8/24/2020.
//

#ifndef INC_15_INHERITANCE_PERSON_H
#define INC_15_INHERITANCE_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        Person();

        Person(const std::string& name, int age, int height);

        void sayHello();

    private:
        std::string name;
        int age;
        int height;
    };

}


#endif //INC_15_INHERITANCE_PERSON_H
