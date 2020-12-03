//
// Created by WebbDong on 11/15/2020.
//

#ifndef INC_41_SMART_POINTER_PERSON_H
#define INC_41_SMART_POINTER_PERSON_H


class Person {

public:
    Person();

    Person(const std::string& name, int age, int height);

    virtual ~Person();

    virtual void display();

    int getAge() const;

    void setAge(int age);

    int getHeight() const;

    void setHeight(int height);

    const std::string& getName() const;

    void setName(const std::string& name);

private:
    int age;
    int height;
    std::string name;
};


#endif //INC_41_SMART_POINTER_PERSON_H
