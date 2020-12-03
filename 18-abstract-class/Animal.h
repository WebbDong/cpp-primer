//
// Created by WebbDong on 8/27/2020.
//

#ifndef INC_18_ABSTRACT_CLASS_ANIMAL_H
#define INC_18_ABSTRACT_CLASS_ANIMAL_H

#include "Consts.h"

namespace dwb {

    class Animal {
    public:
        Animal(const std::string& name, int age, int height);

        virtual ~Animal();

        virtual void run() = 0;

        virtual void yelp() = 0;

        void sayHello();

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

#endif //INC_18_ABSTRACT_CLASS_ANIMAL_H
