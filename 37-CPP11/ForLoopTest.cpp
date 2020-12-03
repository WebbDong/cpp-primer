//
// Created by WebbDong on 9/17/2020.
//
#include <iostream>
#include <vector>
#include <map>

#include "ForLoopTest.h"

namespace dwb {

    class Rocket {
    public:
        Rocket() {}

        Rocket(int speed) : speed(speed) {
            std::cout << "Rocket(int speed)" << std::endl;
        }

        Rocket(const Rocket& rocket) : speed(rocket.speed) {
            std::cout << "Rocket(const Rocket& rocket)" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& cout, const Rocket& rocket) {
            cout << "speed = " << rocket.speed << std::endl;
            return cout;
        }

        int getSpeed() const {
            return speed;
        }

        void setSpeed(int speed) {
            Rocket::speed = speed;
        }

    private:
        int speed;
    };

    /**
     * C++11 for循环
     *      新的for循环，语法：
     *          for (declaration : expression) {
     *              // 循环体
     *          }
     *
     *          declaration：表示此处要定义一个变量，该变量的类型为要遍历序列中存储元素的类型。C++ 11 标准中，
     *                       declaration参数处定义的变量类型可以用 auto 关键字表示，该关键字可以使编译器自行推导该变量的数据类型。
     *                       可以使用普通变量或者引用类型变量，使用引用类型可以遍历的同时修改集合中的元素值
     *          expression：表示要遍历的序列，常见的可以为事先定义好的普通数组或者容器，还可以是用 {} 大括号初始化的序列。
     */
    void ForLoopTest::test() {
        // 遍历{}初始化列表
        for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        // 遍历char数组
        char url[] = "http://c.biancheng.net/cplus/11/";
        for (char ch : url) {
            std::cout << ch;
        }
        std::cout << std::endl;

        // 遍历double vector
        std::vector<double> doubleVector;
        doubleVector.push_back(80.5);
        doubleVector.push_back(90.5);
        doubleVector.push_back(85.5);
        doubleVector.push_back(70.5);
        for (double n : doubleVector) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
        // 循环遍历时同时修改元素的值，使用引用类型变量
        for (auto &n : doubleVector) {
            n *= 2;
        }
        for (auto n : doubleVector) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        // 遍历对象类型vector
        std::vector<Rocket> rocketVector;
        rocketVector.push_back(Rocket(80000));
        rocketVector.push_back(Rocket(90000));
        rocketVector.push_back(Rocket(70000));
        rocketVector.push_back(Rocket(50000));
        rocketVector.push_back(Rocket(40000));
        std::cout << "--------------------------------------" << std::endl;
        // 将元素赋值给r变量时，会调用Rocket的拷贝构造函数
        for (auto r : rocketVector) {
            std::cout << r;
        }
        std::cout << "--------------------------------------" << std::endl;
        // 使用引用来防止多余的拷贝构造，如果不想修改元素的值，建议使用const引用
        for (const Rocket& r : rocketVector) {
            std::cout << r;
        }
        std::cout << "--------------------------------------" << std::endl;
        for (const auto& r : rocketVector) {
            std::cout << r;
        }
        std::cout << "--------------------------------------" << std::endl;

        // 遍历map
        std::map<std::string, std::string> map1{{"C++11","http://c.biancheng.net/cplus/11/"},
                                                {"Python","http://c.biancheng.net/python/"},
                                                {"Java","http://c.biancheng.net/java/"}};
        for (std::pair<std::string, std::string> p : map1) {
            std::cout << p.first << "：" << p.second << std::endl;
        }

        // 遍历string
        std::string str1 = "Lamborghini";
        for (char ch : str1) {
            std::cout << ch;
        }
    }

}