//
// Created by WebbDong on 8/30/2020.
//

#ifndef INC_25_DEEP_COPY_PERSON_H
#define INC_25_DEEP_COPY_PERSON_H

namespace dwb {

    class Person {
    public:
        Person(const char* name = nullptr, int age = 0, int height = 0);

        Person(const Person& person);

        virtual ~Person();

        void sayHello();

        virtual void run();

        char* getName() const;

        void setName(char* name);

        int getAge() const;

        void setAge(int age);

        int getHeight() const;

        void setHeight(int height);

    private:
        void init(const char* string);

    private:
        char* name;
        int age;
        int height;
    };

}

#endif //INC_25_DEEP_COPY_PERSON_H
