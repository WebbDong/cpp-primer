//
// Created by WebbDong on 8/21/2020.
//

#ifndef INC_12_DESTRUCTOR_PERSON_H
#define INC_12_DESTRUCTOR_PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person();

    Person(std::string name, int age);

    // 析构函数，当销毁一个Person对象时就会调用
    ~Person();

    const std::string &getName() const;

    void setName(const std::string &name);

    int getAge() const;

    void setAge(int age);
};


#endif //INC_12_DESTRUCTOR_PERSON_H
