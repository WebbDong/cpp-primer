#include <iostream>

#include "Car.h"

namespace dwb {
    int number = 380;

    void func() {
        std::cout << number << std::endl;
    }

    class Person {
    public:
        Person() {}

        Person(int age, const std::string& name) : age(age), name(name) {}

        int getAge() const {
            return age;
        }

        void setAge(int age) {
            Person::age = age;
        }

        const std::string& getName() const {
            return name;
        }

        void setName(const std::string& name) {
            Person::name = name;
        }

        void display() {
            std::cout << "name = " << name << ", age = " << age << std::endl;
        }

    private:
        int age;
        std::string name;
    };
}

namespace outer {
    namespace inner {
        int number = 900;
    }
}

void testUsing() {
    using dwb::number;
    std::cout << number << std::endl;
}

void testUsingNamespace() {
    using namespace dwb;
    std::cout << number << std::endl;
    Person p(50, "Adam");
    p.display();
}

void func() {
    std::cout << "global func()" << std::endl;
}

void testDefaultNamespace() {
    using namespace dwb;
    ::func();
    ::dwb::func();
}

/**
 * 命名空间
 *      1、命名空间不影响内存布局
 *      2、有个默认的全局命名空间，所有东西默认都在它里面，但是它没有名字，使用::直接来访问它的成员
 */
int main() {
    dwb::func();
    testUsing();
    testUsingNamespace();
    std::cout << outer::inner::number << std::endl;
    testDefaultNamespace();

    dwb::Car car(800);
    car.display();
    return 0;
}
