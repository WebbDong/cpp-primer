//
// Created by WebbDong on 9/1/2020.
//

#ifndef INC_32_OPERATOR_OVERLOAD_STUDENT_H
#define INC_32_OPERATOR_OVERLOAD_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student(const std::string& name = "", int age = 0, float score = 0.0f);

        void display();

        Student& operator=(const Student& student);

    private:
        float score;
    };

}

#endif //INC_32_OPERATOR_OVERLOAD_STUDENT_H
