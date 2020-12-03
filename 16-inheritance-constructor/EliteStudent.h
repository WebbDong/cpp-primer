//
// Created by WebbDong on 8/25/2020.
//

#ifndef INC_16_INHERITANCE_CONSTRUCTOR_ELITESTUDENT_H
#define INC_16_INHERITANCE_CONSTRUCTOR_ELITESTUDENT_H

#include "Student.h"

namespace dwb {

    class EliteStudent : public Student {
    public:
        EliteStudent(const std::string& name, int age, int height, float score, float scholarship);

        ~EliteStudent();

        void dissert();

    private:
        float scholarship;
    };

}

#endif //INC_16_INHERITANCE_CONSTRUCTOR_ELITESTUDENT_H
