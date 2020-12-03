//
// Created by WebbDong on 8/29/2020.
//

#ifndef INC_23_REFERENCE_MEMBER_PERSON_H
#define INC_23_REFERENCE_MEMBER_PERSON_H

namespace dwb {

    class Person {
    public:
        static int staticNumber;

        static int& staticRefNumber;

        Person(int age);

        void func();

        int getAge() const;

        void setAge(int age);

        int& getRefAge() const;

        void setRefAge(int& refAge);

    private:
        int age;
        int& refAge;
//        int& refAge = age;
    };

}

#endif //INC_23_REFERENCE_MEMBER_PERSON_H
