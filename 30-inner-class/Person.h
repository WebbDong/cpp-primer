//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_30_INNER_CLASS_PERSON_H
#define INC_30_INNER_CLASS_PERSON_H

#include <string>

namespace dwb {

    class Person {
    public:
        // 内部类
        class Car {
        public:
            Car(const std::string& brand = "", int horsePower = 0);

            void display();

        private:
            std::string brand;
            int horsePower;
        };

        Person();

        Person(const std::string& name, int age);

        void display();

    private:
        static int staticNumber;
        std::string name = "";
        int age = 0;
    };

}

#endif //INC_30_INNER_CLASS_PERSON_H
