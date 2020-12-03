//
// Created by WebbDong on 8/24/2020.
//

#ifndef INC_15_INHERITANCE_TEACHER_H
#define INC_15_INHERITANCE_TEACHER_H

#include "Person.h"

namespace dwb {

    class Teacher : public Person {
    public:
        Teacher();

        Teacher(const std::string& name, int age, int height, float salary);

        void teach();

    private:
        float salary;
    };

}

#endif //INC_15_INHERITANCE_TEACHER_H
