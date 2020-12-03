#include <iostream>
#include <string.h>

using namespace std;

class Person {
public:
    Person() {
        Person::age = 0;
        Person::height = 0;
        cout << "Person()  ";
    }

    Person(int age, int height, const string& name) {
        Person::age = age;
        Person::height = height;
        Person::name = name;
        cout << "Person(int, int, const string &)  ";
    }

    void display() {
        cout << "age = " << this->age << " height = " << this->height << " name = " << this->name << endl;
    }

private:
    int age;
    int height;
    string name;
};

class Student {
public:
    // 构造函数中调用其他构造函数（委托构造函数），必须写在初始化列表里
    Student() : Student("", 0, 0) {
        // 不可以这样直接调用其他构造函数，不会起作用，这句代码是在创建一个临时的Student对象
//        Student("", 50, 80);
    }

    Student(string name, int age, float score) : name(name), age(age), score(score) {}

    void display() {
        std::cout << "name = " << name << ", age = " << age << ", score = " << score << std::endl;
    }

private:
    string name;
    int age;
    float score;
};

class Vehicle {
public:
    // 初始化列表配合函数默认参数
    Vehicle(int horsePower = 0, int seatCount = 0);

    void display() {
        std::cout << "horsePower = " << horsePower << ", seatCount = " << seatCount << std::endl;
    }

private:
    int horsePower;
    int seatCount;
};

Vehicle::Vehicle(int horsePower, int seatCount) : horsePower(horsePower), seatCount(seatCount) {}

/**
 * 构造函数
 *      1、一旦自定义了构造函数，必须使用其中一个自定义的构造函数来初始化对象
 *      2、通过malloc分配的对象不会调用构造函数
 *      3、在某些特定的情况下，编译器才会为类生成无参构造函数
 *
 * 初始化列表
 *      如果类定义和类实现是分离的，初始化列表只能写在类实现中，函数的默认参数只能写在声明中。
 * @return
 */
int main() {
    Person person1;
    person1.display();
    cout << endl;

    Person person2(40, 190, "Adam");
    person2.display();
    cout << endl;

    Person* p1 = new Person;
    p1->display();
    delete p1;
    cout << endl;

    Person* p2 = new Person();
    p2->display();
    delete p2;
    cout << endl;

    Person* p3 = new Person(20, 180, "Conner");
    p3->display();
    delete p3;
    cout << endl;

    // 使用malloc，不会调用构造函数
    Person* p4 = (Person*) malloc(sizeof(Person));
    p4->display();
    memset(p4, 0, sizeof(Person));
    p4->display();
    free(p4);
    cout << endl;

    // 注意: 在栈中创建对象时，不能使用以下这种方式，编译器会当作函数声明看待，必须使用Person person3
//    Person person3();
//    person3.display();

    Vehicle vehicle1;
    vehicle1.display();
    Vehicle vehicle2(700);
    vehicle2.display();

    Student student1;
    student1.display();
    Student student2("Adam", 30, 70.9f);
    student2.display();
    return 0;
}
