//
// Created by WebbDong on 8/30/2020.
//

#ifndef INC_25_DEEP_COPY_STUDENT_H
#define INC_25_DEEP_COPY_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : public Person {
    public:
        Student(const char* name = nullptr, int age = 0, int height = 0, float score = 0.0f);

        Student(const Student& student);

        void study();

        void run();

        float getScore() const;

        void setScore(float score);

    private:
        float score;
    };

}

#endif //INC_25_DEEP_COPY_STUDENT_H
