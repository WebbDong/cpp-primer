//
// Created by WebbDong on 8/30/2020.
//

#ifndef INC_24_COPY_CONSTRUCTOR_STUDENT_H
#define INC_24_COPY_CONSTRUCTOR_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student(const std::string& name = "", int age = 0, float score = 0.0f);

        Student(const Student& student);

        void sayHello();

        float getScore() const;

        void setScore(float score);

    private:
        float score;
    };

}

#endif //INC_24_COPY_CONSTRUCTOR_STUDENT_H
