//
// Created by WebbDong on 8/25/2020.
//

#ifndef INC_16_INHERITANCE_CONSTRUCTOR_STUDENT_H
#define INC_16_INHERITANCE_CONSTRUCTOR_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student();

        Student(const std::string& name, int age, int height, float score);

        ~Student();

        void study();

    private:
        float score;
    };

}

#endif //INC_16_INHERITANCE_CONSTRUCTOR_STUDENT_H
