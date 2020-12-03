//
// Created by WebbDong on 8/25/2020.
//

#ifndef INC_16_INHERITANCE_CONSTRUCTOR_TEACHER_H
#define INC_16_INHERITANCE_CONSTRUCTOR_TEACHER_H

#include "Person.h"

namespace dwb {

    class Teacher : public Person {
    public:
        Teacher(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0, float salary = 0.0f);

        ~Teacher();

        void teach();

    private:
        float salary;
    };

}

#endif //INC_16_INHERITANCE_CONSTRUCTOR_TEACHER_H
