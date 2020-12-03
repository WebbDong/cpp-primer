//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_19_MULTIPLE_INHERITANCE_STUDENT_H
#define INC_19_MULTIPLE_INHERITANCE_STUDENT_H

#include "Person.h"

namespace dwb {

    class Student : virtual public Person {
    public:
        Student(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0, float score = 0.0f);

        Student(float score = 0.0f);

        ~Student();

        void run();

        void study();

        float getScore() const;

        void setScore(float score);

    private:
        float score;
    };

}

#endif //INC_19_MULTIPLE_INHERITANCE_STUDENT_H
