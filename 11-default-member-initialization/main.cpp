#include <iostream>

#include "Person.h"

using namespace std;

struct Car {
    int horsePower;
};

// 全局区：初始化为0
Person person1;
// 全局区：三个Person对象的成员变量都初始化为0
Person personArray1[3];
// 全局区：初始化为0
Car car1;
// 全局区：三个Car对象的成员变量都初始化为0
Car carArray1[3];

void coutPersonArray(Person* pArr, int m, string variateName);

void coutCarArray(Car* pArr, int m, string variateName);

/**
 * 成员变量的默认初始化
 *      如果自定义了构造函数，堆空间的成员变量都不会被默认初始化为0
 *      不同编译器可能会有差异
 * @return
 */
int main() {
    // 栈空间：初始化为0
    Person person2;
    // 堆空间：未初始化
    Person* pPerson1 = new Person;
    // 堆空间：初始化为0
    Person* pPerson2 = new Person();

    // 栈空间：三个Person对象的成员变量都未初始化
    Person personArray2[3];
    // 栈空间：三个Person对象的成员变量都初始化为0
    Person personArray3[3]{};
    // 堆空间：三个Person对象的成员变量都未初始化
    Person* pPersonArray1 = new Person[3];
    // 堆空间：三个Person对象的成员变量都初始化为0
    Person* pPersonArray2 = new Person[3]();
    // 堆空间：三个Person对象的成员变量都初始化为0
    Person* pPersonArray3 = new Person[3]{};
    cout << "person1.getAge() = " << person1.getAge() << endl;
    cout << "person2.getAge() = " << person2.getAge() << endl;
    cout << "pPerson1->getAge() = " << pPerson1->getAge() << endl;
    cout << "pPerson2->getAge() = " << pPerson2->getAge() << endl;
    coutPersonArray(personArray1, 3, "personArray1");
    coutPersonArray(personArray2, 3, "personArray2");
    coutPersonArray(personArray3, 3, "personArray3");
    coutPersonArray(pPersonArray1, 3, "pPersonArray1");
    coutPersonArray(pPersonArray2, 3, "pPersonArray2");
    coutPersonArray(pPersonArray3, 3, "pPersonArray3");
    delete pPerson1;
    delete pPerson2;
    delete[] pPersonArray1;
    delete[] pPersonArray2;
    delete[] pPersonArray3;
    cout << endl;

    // 栈空间：初始化为0
    Car car2;
    // 堆空间：未初始化
    Car* pCar1 = new Car;
    // 堆空间：初始化为0
    Car* pCar2 = new Car();

    // 栈空间：三个Car对象的成员变量都未初始化
    Car carArray2[3];
    // 栈空间：三个Car对象的成员变量都初始化为0
    Car carArray3[3]{};
    // 堆空间：三个Car对象的成员变量都未初始化
    Car* pCarArray1 = new Car[3];
    // 堆空间：三个Car对象的成员变量都初始化为0
    Car* pCarArray2 = new Car[3]();
    // 堆空间：三个Car对象的成员变量都初始化为0
    Car* pCarArray3 = new Car[3]{};
    cout << "car1.horsePower = " << car1.horsePower << endl;
    cout << "car2.horsePower = " << car2.horsePower << endl;
    cout << "pCar1->horsePower = " << pCar1->horsePower << endl;
    cout << "pCar2->horsePower = " << pCar2->horsePower << endl;
    coutCarArray(carArray1, 3, "carArray1");
    coutCarArray(carArray2, 3, "carArray2");
    coutCarArray(carArray3, 3, "carArray3");
    coutCarArray(pCarArray1, 3, "pCarArray1");
    coutCarArray(pCarArray2, 3, "pCarArray2");
    coutCarArray(pCarArray3, 3, "pCarArray3");
    delete pCar1;
    delete pCar2;
    delete[] pCarArray1;
    delete[] pCarArray2;
    delete[] pCarArray3;
    return 0;
}

void coutPersonArray(Person* pArr, int m, string variateName) {
    cout << variateName << " : ";
    for (int i = 0; i < m; i++) {
        cout << (pArr + i)->getAge() << " ";
    }
    cout << endl;
}

void coutCarArray(Car* pArr, int m, string variateName) {
    cout << variateName << " : ";
    for (int i = 0; i < m; i++) {
        cout << pArr[i].horsePower << " ";
    }
    cout << endl;
}
