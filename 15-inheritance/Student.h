//
// Created by WebbDong on 8/24/2020.
//

#ifndef INC_15_INHERITANCE_STUDENT_H
#define INC_15_INHERITANCE_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student();

        Student(const std::string& name, int age, int height, float score);

        void study();

    private:
        float score;
    };

}

#endif //INC_15_INHERITANCE_STUDENT_H
