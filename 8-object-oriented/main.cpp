#include <iostream>

using namespace std;

class Person {
public:
//private:
    int age;
    int height;
    string name;

public:
    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Person::height = height;
    }

    const string& getName() const {
        return name;
    }

    void setName(const string& name) {
        Person::name = name;
    }

    void sayHello() {
        cout << "Hello, I'm " << Person::name << ". I'm " << Person::age << " years old " << "and " << Person::height
             << " cm tall." << endl;
    }
};

/**
 * C++中可以使用struct和class来定义一个类，区别在于struct的默认成员权限是public，class的默认成员权限是private
 * @return
 */
int main() {
    Person person;
    person.setName("Webb");
    person.setHeight(188);
    person.setAge(20);
    person.sayHello();

    Person person2 = {50, 170, "Conner"};
    person2.sayHello();

    Person* person3 = new Person{44, 165, "Lisa"};
    person3->sayHello();
    delete person3;

    Person* p = &person;
    p->setName("Adam");
    p->setHeight(180);
    p->setAge(40);
    p->sayHello();
    cout << endl;

    cout << "sizeof(Person) = " << sizeof(Person) << endl;
    cout << "&person = " << &person << endl;
    cout << "&person.age = " << &person.age << endl;
    cout << "&person.name = " << &person.name << endl;
    // 指针变量p的地址
    cout << "&p = " << &p << endl;
    // 指针变量p指向的person对象地址
    cout << "p = " << p << endl;
    cout << "&p->age = " << &p->age << endl;
    cout << endl;

    // 第一个成员变量的地址就是person对象的地址，通过指针地址偏移来访问其他成员
    Person* p2 = (Person*) &person.age;
    p2->setName("Conner");
    p2->setAge(60);
    p2->setHeight(190);
    p2->sayHello();
    person.sayHello();
    return 0;
}
