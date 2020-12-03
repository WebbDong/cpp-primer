#include <iostream>

#include "Cat.h"
#include "Dog.h"

/**
 * 纯虚函数
 *      1、纯虚函数：没有函数体且初始化为0的虚函数，用来定义接口规范
 *
 * 抽象类
 *      1、含有纯虚函数的类，不可以实例化（不可以创建对象）
 *      2、抽象类也可以包含非纯虚函数、成员变量
 *      3、如果父类是抽象类，子类没有完全重写纯虚函数，那么这个子类依然是抽象类
 * @return
 */
int main() {
    // Animal为抽象类，不能实例化
//    dwb::Animal* animal = new dwb::Animal;

    dwb::Animal* animal1 = new dwb::Cat("Cat", 5, 60);
    animal1->run();
    animal1->yelp();
    animal1->sayHello();
    delete animal1;

    std::cout << std::endl;

    dwb::Animal* animal2 = new dwb::Dog("Dog", 2, 80);
    animal2->run();
    animal2->yelp();
    animal2->sayHello();
    delete animal2;
    return 0;
}
