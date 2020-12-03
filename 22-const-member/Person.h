//
// Created by WebbDong on 8/29/2020.
//

#ifndef INC_22_CONST_MEMBER_PERSON_H
#define INC_22_CONST_MEMBER_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        static const int staticConstNumber;

        Person(const std::string& name);

        void constFunc() const;

        void func();

    private:
        std::string name;
//        const int constNumber = 0;
        const int constNumber;
    };

}

#endif //INC_22_CONST_MEMBER_PERSON_H
