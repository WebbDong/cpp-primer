//
// Created by WebbDong on 11/15/2020.
//

#ifndef INC_41_SMART_POINTER_STUDENT_H
#define INC_41_SMART_POINTER_STUDENT_H

#include <string>

#include "Person.h"

class Student : public Person {
public:
    Student(const std::string& name, int age, int height, float score);

    ~Student();

    virtual void display();

private:
    float score;
};


#endif //INC_41_SMART_POINTER_STUDENT_H
