//
// Created by WebbDong on 9/17/2020.
//
#include <iostream>
#include <string>

#include "UnrestrictedUnionTest.h"

namespace dwb {

    class Fighter {
    public:
        Fighter() {}

        Fighter(int speed) {
            this->speed = speed;
        }

        int getSpeed() const {
            return speed;
        }

        void setSpeed(int speed) {
            Fighter::speed = speed;
        }

    private:
        int speed;
    };

    union Union1 {
        Fighter fighter;
        std::string name;
        int num;
        static int staticNum;

        Union1() {
//            new(&fighter) Fighter;
            new(&name) std::string;
        }

        Union1(const std::string& name) {
            new(&this->name) std::string(name);
        }

        Union1(int speed) {
            new(&this->name) std::string;
            fighter.setSpeed(speed);
        }

        ~Union1() {
        }

        void display() {
            std::cout << "name = " << name << ", num = " << num << ", staticNum = " << Union1::staticNum << std::endl;
        }

        static void staticFunc() {
            std::cout << "staticFunc" << std::endl;
        }
    };

    class Pilot {
    public:
        Pilot() {}

        Pilot(const std::string& name) {
            new(&this->name) std::string(name);
        }

        Pilot(int speed) {
            fighter.setSpeed(speed);
        }

        ~Pilot() {}

        void dislplay() {
            std::cout << "fighter.getSpeed() = " << fighter.getSpeed() << ", speed = "
                      << speed << ", name = " << name << std::endl;
        }

    private:
        // 匿名非受限联合体成员
        union {
            Fighter fighter;
            int speed;
            std::string name;
        };
    };

    int Union1::staticNum = 80000;

    /**
     * 非受限联合体
     *      1、C++11 标准规定，任何非引用类型都可以成为联合体的数据成员，这种联合体也被称为非受限联合体。
     *      2、C++98 不允许联合体的成员是非 POD 类型，但是 C++11 取消了这种限制。
     *          POD(Plain Old Data)，POD 类型一般具有以下几种特征（包括 class、union 和 struct等）：
     *              1) 没有用户自定义的构造函数、析构函数、拷贝构造函数和移动构造函数。
     *              2) 不能包含虚函数和虚基类。
     *              3) 非静态成员必须声明为 public。
     *              4) 类中的第一个非静态成员的类型与其基类不同
     *                      class B1 {
     *                      }
     *
     *                      class B2 : B1 {
     *                          B1 b;
     *                      }
     *
     *                      class B2 的第一个非静态成员 b 是基类类型，所以它不是 POD 类型。
     *              5) 在类或者结构体继承时，满足以下两种情况之一：
     *                      派生类中有非静态成员，且只有一个仅包含静态成员的基类；
     *                      基类有非静态成员，而派生类没有非静态成员。
     *              6) 所有非静态数据成员均和其基类也符合上述规则（递归定义），也就是说 POD 类型不能包含非 POD 类型的数据。
     *              7) 此外，所有兼容C语言的数据类型都是 POD 类型（struct、union 等不能违背上述规则）。
     *      3、C++11 允许联合体有静态成员
     *      4、非受限联合体的赋值注意事项
     *          C++11 规定，如果非受限联合体内有一个非 POD 的成员，而该成员拥有自定义的构造函数，
     *          那么这个非受限联合体的默认构造函数将被编译器删除；其他的特殊成员函数，例如默认拷贝构造函数、
     *          拷贝赋值操作符以及析构函数等，也将被删除。这条规则可能导致对象构造失败。POD成员需要使用placement new
     *
     *          placement new：placement new 是 new 关键字的一种进阶用法，既可以在栈（stack）上生成对象，
     *              也可以在堆（heap）上生成对象。相对应地，我们把常见的 new 的用法称为 operator new，它只能在 heap 上生成对象。
     *              placement new 的语法格式如下：
     *                  new(address) ClassConstruct(...)
     *
     *                  address 表示已有内存的地址，该内存可以在栈上，也可以在堆上；ClassConstruct(...) 表示调用类的构造函数，
     *                  如果构造函数没有参数，也可以省略括号。placement new 利用已经申请好的内存来生成对象，
     *                  它不再为对象分配新的内存，而是将对象数据放在 address 指定的内存中。
     *      5、非受限联合体的匿名声明和“枚举式类”
     *          匿名联合体是没有名字的联合体
     *              union U {
     *                  // 此联合体为匿名联合体
     *                  union {
     *                      int x;
     *                  };
     *              };
     *          非受限联合体也可以匿名，而当非受限的匿名联合体运用于类的声明时，这样的类被称为“枚举式类”。有非受限的匿名联合体成员
     *          的类，遵循POD规则
     */
    void UnrestrictedUnionTest::test() {
        Union1 u1;
//        u1.name = "F35";
//        u1.num = 666;
        u1.fighter.setSpeed(60000);
        std::cout << "name = " << u1.name << ", num = " << u1.num << std::endl;
        std::cout << "u1.fighter.getSpeed() = " << u1.fighter.getSpeed() << std::endl;
        u1.display();
        Union1::staticFunc();
        Union1::staticNum = 99999;
        std::cout << "staticNum = " << Union1::staticNum << std::endl;
        std::cout << "--------------------------------------------" << std::endl;

        Union1 u2(50000);
        std::cout << "name = " << u2.name << ", u2.fighter.getSpeed() = " << u2.fighter.getSpeed() << std::endl;
        std::cout << "--------------------------------------------" << std::endl;

        Pilot p1("Adam");
        p1.dislplay();

        Pilot p2(70000);
        p2.dislplay();
    }

}