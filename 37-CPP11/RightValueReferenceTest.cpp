//
// Created by WebbDong on 9/18/2020.
//
#include <iostream>

#include "RightValueReferenceTest.h"

namespace dwb {

    class Tank {
    public:
        Tank() : speed(0), pNum(new int(500)) {
            std::cout << "Tank()" << std::endl;
        }

        Tank(int speed, int num) : speed(speed), pNum(new int(num)) {
            std::cout << "Tank(int speed, int num)" << std::endl;
        }

        // 拷贝构造函数
        Tank(const Tank& tank) : speed(tank.speed), pNum(new int(*tank.pNum)) {
            std::cout << "Tank(const Tank& tank)" << std::endl;
        }

        // 移动构造函数
        Tank(Tank&& tank) : speed(tank.speed), pNum(tank.pNum) {
            // num指针是一个浅拷贝，同时在函数内部重置了 tank.num，有效避免了“同一块对空间被释放多次”情况的发生。
            // 避免临时内存频繁销毁
            tank.pNum = nullptr;
            std::cout << "Tank(Tank&& tank)" << std::endl;
        }

        ~Tank() {
            if (pNum != nullptr) {
                delete pNum;
            }
        }

        void display() {
            std::cout << "speed = " << speed;
            if (pNum != nullptr) {
                std::cout << ", *pNum = " << *pNum;
            }
            std::cout << ", &speed = " << &speed << ", pNum = " << pNum << std::endl;
        }

        int speed;
        int* pNum;
    };

    class Magazine {
    public:
        Magazine() : bulletNum(0) {
            std::cout << "Magazine()" << std::endl;
        }

        Magazine(int bulletNum) : bulletNum(bulletNum) {
            std::cout << "Magazine(int bulletNum)" << std::endl;
        }

        Magazine(const Magazine& magazine) : bulletNum(magazine.bulletNum) {
            std::cout << "Magazine(const Magazine& magazine)" << std::endl;
        }

        int bulletNum;
    };

    class Suppressor {
    public:
        Suppressor(int width) : width(width) {
            std::cout << "Suppressor(int width)" << std::endl;
        }

        int width;
    };

    class Gun {
    public:
        Gun() : length(0), cartridge(0), pPrice(new double(0.0)), pMagazine(nullptr), suppressor(Suppressor(0)) {
            std::cout << "Gun()" << std::endl;
        }

        Gun(int length, int cartridge, double price, Magazine* magazine, Suppressor suppressor)
                : length(length), cartridge(cartridge), pPrice(new double(price)),
                  pMagazine(magazine), suppressor(suppressor) {
            std::cout << "Gun(int length, int cartridge, double price, Magazine* magazine, Suppressor suppressor)" << std::endl;
        }

        // 拷贝构造函数，指针变量使用std::move防止多余的拷贝
        Gun(const Gun& gun)
                : length(gun.length), cartridge(gun.cartridge), pPrice(new double(*gun.pPrice)),
                  pMagazine(new Magazine(*gun.pMagazine)), suppressor(gun.suppressor) {
            std::cout << "Gun(const Gun& gun)" << std::endl;
        }

        // 移动构造函数
        Gun(Gun&& gun)
                : length(gun.length), cartridge(gun.cartridge), pPrice(gun.pPrice),
                  pMagazine(gun.pMagazine), suppressor(gun.suppressor) {
            gun.pPrice = nullptr;
            gun.pMagazine = nullptr;
            std::cout << "Gun(Gun&& gun)" << std::endl;
        }

        ~Gun() {
            if (pPrice != nullptr) {
                delete pPrice;
            }
            if (pMagazine != nullptr) {
                delete pMagazine;
            }
        }

        friend std::ostream& operator<<(std::ostream& cout, const Gun& gun) {
            gun.display();
            return cout;
        }

        void display() const {
            std::cout << "length = " << length << ", cartridge = " << cartridge << ", &suppressor = " << &suppressor
                      << ", suppressor.width = " << suppressor.width;
            if (pPrice != nullptr) {
                std::cout << ", pPrice = " << pPrice << ", *pPrice = " << *pPrice;
            }
            if (pMagazine != nullptr) {
                std::cout << ", pMagazine = " << pMagazine << ", pMagazine->bulletNum = " << pMagazine->bulletNum;
            }
            std::cout << std::endl;
        }

        int length;
        int cartridge;
        Suppressor suppressor;
        double* pPrice;
        Magazine* pMagazine;
    };

    Tank getTank() {
        Tank t;
        std::cout << "getTank() &t.pNum = " << &t.pNum << ", t.pNum = " << t.pNum << std::endl;
        return t;
    }

    /**
     * 1、右值引用基本用法
     */
    void basicRValueRefTest() {
        const int constNum1 = 100;
        // 不允许非const引用来存储常量
//        int& refNum1 = constNum1;
//        int& refNum2 = 100;
        const int& refNum3 = constNum1;
        const int& refNum4 = 600;

        // 右值引用不可以引用左值，也就是不可以引用变量
//        int&& rvalueRef1 = constNum1;
        // 右值引用只能是右值，也就是常量字面值
        int&& rvalueRef2 = 9999;
        std::cout << "rvalueRef2 = " << rvalueRef2 << std::endl;
        rvalueRef2 = 88009;
        std::cout << "rvalueRef2 = " << rvalueRef2 << std::endl;

        // 右值引用不可以直接定义的同时赋值一个右值引用变量
//        int&& rvalueRef3 = rvalueRef2;

        int&& rvalueRef3 = 60;
        int&& rvalueRef4 = 90;
        // 可以给定义好了的右值引用变量赋值一个定义好了的右值引用变量
        rvalueRef3 = rvalueRef4;

        // 常量右值引用
        const int&& constrvalueRef1 = 555555;
        std::cout << "constrvalueRef1 = " << constrvalueRef1 << std::endl;
    }

    /**
     * 2、移动构造函数
     */
    void moveConstructorTest() {
        Tank t1 = getTank();
        t1.display();
        std::cout << "moveConstructorTest() &t.pNum = " << &t1.pNum << ", t.pNum = " << t1.pNum << std::endl;
    }

    /**
     * 3、std::move函数
     */
    void moveFuncTest() {
        std::string str1 = "Lamborghini";
        // 将str1强制转换为右值，并且将值赋值给str2，str1的数据被清空
        std::string str2 = std::move(str1);
        std::cout << "str1 = " << str1 << ", str2 = " << str2
                  << ", &str1 = " << &str1 << ", &str2 = " << &str2 << std::endl;

        std::string str3 = "Ferrari";
        // 与std::move等价
        std::string str4 = static_cast<std::string&&>(str3);
        std::cout << "str3 = " << str3 << ", str4 = " << str4
                  << ", &str3 = " << &str3 << ", &str4 = " << &str4 << std::endl;

        int num1 = 888;
        // 对基本数据类型效果等于直接赋值
        int num2 = std::move(num1);
        // num1的右值引用
        int&& rlRef1 = std::move(num1);
        std::cout << "num1 = " << num1 << ", num2 = " << num2
                  << ", &num1 = " << &num1 << ", &num2 = " << &num2
                  << ", &rlRef1 = " << &rlRef1 << ", rlRef1 = " << rlRef1 << std::endl;

        int* pNum1 = new int(600);
        // 对指针类型效果等于直接赋值
        int* pNum2 = std::move(pNum1);
        std::cout << "pNum1 = " << pNum1 << ", *pNum1 = " << *pNum1
                  << ", pNum2 = " << pNum2 << ", *pNum2 = " << *pNum2 << std::endl;
        delete pNum2;
        std::cout << "-------------------------------------------------------------" << std::endl;

        Tank tank1(200, 100);
        tank1.display();
        // 调用移动构造函数
        Tank tank2 = std::move(tank1);
        tank1.display();
        tank2.display();
        std::cout << "-------------------------------------------------------------" << std::endl;

        Magazine* pMagazine1 = new Magazine(7);
        Gun g1(8, 45, 1200, pMagazine1, Suppressor(50));
        g1.display();
        // 调用拷贝构造函数
        Gun g2 = g1;
        g2.display();
        // 调用移动构造函数
        Gun g3 = std::move(g2);
        g3.display();
    }

    // 万能引用模板的右值引用，既可以接收左值也可以接收右值
    template<typename T>
    void almightyRef(T&& t) {
        std::cout << "almightyRef(T&& t) t = " << t << std::endl;
    }

    void otherFunc(int& i) {
        std::cout << "otherFunc(int& i) i = " << i << std::endl;
    }

    void otherFunc(const int& i) {
        std::cout << "otherFunc(const int& i) i = " << i << std::endl;
    }

    /**
     * 如果模板函数俄参数也用到了泛型类型，那参数前面也需要用typename
     * 参数：typename std::remove_reference<T>::type& t，将传入的参数去除引用类型特性，然后和&结合，为T非引用泛型类型的左值引用
     * @tparam T
     * @param t
     * @return
     */
    template<typename T>
    constexpr T&& myForward(typename std::remove_reference<T>::type& t) noexcept {
        return static_cast<T&&>(t);
    }

    /**
     * 参数：typename std::remove_reference<T>::type&& t，将传入的参数去除引用类型特性，然后和&&结合，为T非引用泛型类型的右值引用
     * @tparam T
     * @param t
     * @return
     */
    template<typename T>
    constexpr T&& myForward(typename std::remove_reference<T>::type&& t) noexcept {
        return static_cast<T&&>(t);
    }

    template<typename T>
    void prefectForward(T&& t) {
        // 如果不适用std::forward，那只会调用otherFunc(int& i)，t是一个变量，永远都是左值。
//        otherFunc(t);
        // 但是使用std::forward，可以保留传入参数的左值和右值属性，可以实现完美转发。
//        otherFunc(std::forward<T>(t));
        otherFunc(myForward<T>(t));
    }

    /**
     * 4、完美转发
     */
    void forwardTest() {
        int x = 700;
        almightyRef(x);
        almightyRef(500);

        double d = 58.45;
        almightyRef(d);
        almightyRef(69.85);
        std::cout << "-----------------------------------------------" << std::endl;

        Gun g1(8, 45, 1200, new Magazine(7), Suppressor(50));
        almightyRef(g1);
        almightyRef(Gun(15, 335, 600, new Magazine(8), Suppressor(80)));
        std::cout << "-----------------------------------------------" << std::endl;

        prefectForward(x);
        prefectForward(8000);
    }

    /**
     * 右值引用
     *      右值引用可以绑定临时变量和常量字面值
     * 移动语义
     *      在 C++ 11 标准之前（C++ 98/03 标准中），如果想用其它对象初始化一个同类的新对象，只能借助类中的复制（拷贝）构造函数。
     *      因为临时数据导致频繁的拷贝构造和析构。移动语义指的就是以移动的方式而非拷贝来初始化。简单的理解，
     *      移动语义指的就是将其他对象（通常是临时对象）拥有的内存资源“移为已用”。
     * C++移动构造函数（移动语义的具体实现）
     *      当用户利用右值初始化类对象时，会调用移动构造函数；使用左值（非右值）初始化类对象时，会调用拷贝构造函数。
     * std::move函数，将左值强制转换为右值
     *      std::move本质是将传入的参数通过static_cast强转为右值引用
     * 完美转发
     *      完美转发指的是函数模板可以将自己的参数“完美”地转发给内部调用的其它函数。所谓完美，即不仅能准确地转发参数的值，还能保证被转发参数的左、右值属性不变。
     *      例如：
     *          template<typename T>
     *          void function(T t) {
     *              otherdef(t);
     *          }
     *
     *          function() 函数模板中调用了 otherdef() 函数。在此基础上，完美转发指的是：如果 function() 函数接收到的参数 t 为左值，
     *          那么该函数传递给 otherdef() 的参数 t 也是左值；反之如果 function() 函数接收到的参数 t 为右值，那么传递给 otherdef() 函数的参数 t 也必须为右值。
     *
     *      C++98/03中，使用const引用和非const引用的函数重载来实现完美转发
     *          例如：
     *              void otherdef(int& i) {
     *                  std::cout << "lvalue" << std::endl;
     *              }
     *
     *              void otherdef(const int& i) {
     *                  std::cout << "rvalue" << std::endl;
     *              }
     *
     *      C++ 11 标准中允许在函数模板中使用右值引用来实现完美转发。C++11 标准中规定，通常情况下右值引用形式的参数只能接收右值，
     *      不能接收左值。但对于函数模板中使用右值引用语法定义的参数来说，它不再遵守这一规定，既可以接收右值，也可以接收左值
     *      （此时的右值引用又被称为“万能引用”）。
     *
     *      引用折叠规则：
     *           C++ 11标准为了更好地实现完美转发，特意为其指定了新的类型匹配规则，又称为引用折叠规则
     *              当实参为左值或者左值引用（A&）时，函数模板中 T&& 将转变为 A&（A& && = A&）；
     *              当实参为右值或者右值引用（A&&）时，函数模板中 T&& 将转变为 A&&（A&& && = A&&）。
     *              引用折叠规则：
     *                  X& + & => X&
     *                  X&& + & => X&
     *                  X& + && => X&
     *                  X&& + && => X&&
     *
     *      std::forward模板函数
     *          将模板函数的万能引用变量传参给const引用参数和非const引用参数，实现完美转发。
     *
     *      std::remove_reference
     *          用于去除一个变量的引用特性
     */
    void RightValueReferenceTest::test() {
//        basicRValueRefTest();
//        moveConstructorTest();
//        moveFuncTest();
        forwardTest();
    }

}