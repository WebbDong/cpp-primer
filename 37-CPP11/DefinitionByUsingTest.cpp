//
// Created by WebbDong on 9/5/2020.
//
#include <iostream>
#include <vector>
#include <map>

#include "DefinitionByUsingTest.h"

namespace dwb {

    class Car {
    public:
        Car(const std::string& brand, int horsePower) : brand(brand), horsePower(horsePower) {}

        void display() {
            std::cout << "brand = " << brand << ", horsePower = " << horsePower;
        }

        const std::string& getBrand() const {
            return brand;
        }

        void setBrand(const std::string& brand) {
            Car::brand = brand;
        }

        int getHorsePower() const {
            return horsePower;
        }

        void setHorsePower(int horsePower) {
            Car::horsePower = horsePower;
        }

        friend std::ostream& operator<<(std::ostream& cout, const Car& car) {
            return cout << "(brand = " << car.brand << ", horsePower = " << car.horsePower << ")";
        }

    private:
        std::string brand;
        int horsePower;
    };

    // 重定义模板
    template<typename V>
    using StringKeyMapType = std::map<std::string, V>;

    // 模板函数指针别名
    template<typename T>
    class TestClass3 {
    public:
        // 使用typedef定义模板函数指针别名
        typedef void (*type)(T, T);
    };

    // 使用using定义模板函数指针别名
    template<typename T>
    using TemplateFuncPointer = void (*)(T, T);

    template<typename T>
    void templateFunc(T a, T b) {
        std::cout << "void templateFunc(T a, T b) a = " << a << ", b = " << b;
    }

    /**
     * 使用using定义别名（替代typedef）
     */
    void DefinitionByUsingTest::test() {
        using MyInt = int;
        MyInt num = 100;
        std::cout << "num = " << num << std::endl;

        using CarMapPairType = std::pair<std::string, Car>;
        using CarMapType = std::map<std::string, Car>;
        using CarMapIteratorType = std::map<std::string, Car>::iterator;
        CarMapType stringCarMap;
        stringCarMap.insert(CarMapPairType("Adam", Car("Ferrari", 800)));
        stringCarMap.insert(CarMapPairType("Conner", Car("Lamborghini", 750)));
        stringCarMap.insert(CarMapPairType("Toyota", Car("Toyota", 200)));
        CarMapIteratorType iterator = stringCarMap.find("Adam");
        std::cout << iterator->first << ", " << iterator->second << std::endl;
        std::cout << stringCarMap.find("Toyota")->second << std::endl;
        std::cout << stringCarMap.find("Conner")->second << std::endl;

        StringKeyMapType<int> stringIntMap;
        stringIntMap.insert(std::pair<std::string, int>("string1", 500));
        stringIntMap.insert(std::pair<std::string, int>("string2", 800));
        auto iterator1 = stringIntMap.find("string1");
        std::cout << iterator1->first << " = " << iterator1->second << std::endl;
        auto iterator2 = stringIntMap.find("string2");
        std::cout << iterator2->first << " = " << iterator2->second << std::endl;

        Car car1("Bugatti", 1200);
        // 类非静态成员函数指针
        void (Car::*pFunc)() = &Car::display;
        Car* pCar = new Car("Honda", 400);
        (pCar->*pFunc)();
        std::cout << std::endl;
        (car1.*pFunc)();
        std::cout << std::endl;

        // 类非静态成员函数指针
        using FuncPointer = void (Car::*)();
        FuncPointer pDisplay = &Car::display;
        (pCar->*pDisplay)();
        std::cout << std::endl;
        (car1.*pDisplay)();
        std::cout << std::endl;
        delete pCar;

        // 模板函数指针别名
        TestClass3<int>::type pTemplateFunc1;
        pTemplateFunc1 = &templateFunc;
        (*pTemplateFunc1)(5, 6);
        std::cout << std::endl;

        TemplateFuncPointer<int> pTemplateFunc2 = &templateFunc;
        (*pTemplateFunc2)(40, 30);
    }

}