//
// Created by WebbDong on 8/27/2020.
//

#ifndef INC_18_ABSTRACT_CLASS_DOG_H
#define INC_18_ABSTRACT_CLASS_DOG_H

#include "Animal.h"

namespace dwb {

    class Dog : public Animal {
    public:
        Dog(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0);

        ~Dog();

        void run();

        void yelp();
    };

}

#endif //INC_18_ABSTRACT_CLASS_DOG_H
