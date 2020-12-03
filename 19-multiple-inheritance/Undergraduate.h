//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_19_MULTIPLE_INHERITANCE_UNDERGRADUATE_H
#define INC_19_MULTIPLE_INHERITANCE_UNDERGRADUATE_H

#include "Student.h"
#include "Worker.h"

namespace dwb {

    class Undergraduate : public Student, public Worker {
    public:
        Undergraduate(const std::string& name = UNKNOWN_NAME,
                      int age = 0,
                      int height = 0,
                      float score = 0.0f,
                      float salary = 0.0f,
                      int grade = 0);

        ~Undergraduate();

        void run();

        void dissert();

        int getGrade() const;

        void setGrade(int grade);

    private:
        int grade;
    };

}

#endif //INC_19_MULTIPLE_INHERITANCE_UNDERGRADUATE_H
