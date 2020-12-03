//
// Created by WebbDong on 9/3/2020.
//

#ifndef INC_34_TYPE_CAST_STUDENT_H
#define INC_34_TYPE_CAST_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student(const std::string& name, int age, float score);

        virtual void display();

        friend std::ostream& operator<<(std::ostream& cout, const Student& p);

    private:
        float score;
    };

}

#endif //INC_34_TYPE_CAST_STUDENT_H
