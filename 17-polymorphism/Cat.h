//
// Created by WebbDong on 8/27/2020.
//

#ifndef INC_17_POLYMORPHISM_CAT_H
#define INC_17_POLYMORPHISM_CAT_H

#include "Animal.h"

namespace dwb {

    class Cat : public Animal {
    public:
        Cat(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0);

        ~Cat();

        void run();

        void yelp();
    };

}

#endif //INC_17_POLYMORPHISM_CAT_H
