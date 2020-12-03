//
// Created by WebbDong on 8/27/2020.
//

#ifndef INC_17_POLYMORPHISM_ANIMAL_H
#define INC_17_POLYMORPHISM_ANIMAL_H

#include "Consts.h"

namespace dwb {

    class Animal {
    public:
        Animal(const std::string& name = UNKNOWN_NAME, int age = 0, int height = 0);

        virtual ~Animal();

        virtual void run();

        virtual void yelp();

        void display();

        const std::string& getName() const;

        void setName(const std::string& name);

        int getAge() const;

        void setAge(int age);

        int getHeight() const;

        void setHeight(int height);

    private:
        std::string name;
        int age;
        int height;
    };

}

#endif //INC_17_POLYMORPHISM_ANIMAL_H
