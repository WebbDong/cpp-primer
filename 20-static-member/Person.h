//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_20_STATIC_MEMBER_PERSON_H
#define INC_20_STATIC_MEMBER_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        static std::string staticString;

        static void staticFunc();

        Person(const std::string& name = "", int age = 0);

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

    private:
        static int staticNumber;
        std::string name;
        int age;
    };

}

#endif //INC_20_STATIC_MEMBER_PERSON_H
