//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_19_MULTIPLE_INHERITANCE_WORKER_H
#define INC_19_MULTIPLE_INHERITANCE_WORKER_H

#include "Person.h"

namespace dwb {

    class Worker : virtual public Person {
    public:
        Worker(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0, float salary = 0.0f);

        Worker(float salary = 0.0f);

        ~Worker();

        void run();

        void work();

        float getSalary() const;

        void setSalary(float salary);

    private:
        float salary;
    };

}

#endif //INC_19_MULTIPLE_INHERITANCE_WORKER_H
