#include <iostream>
#include <string.h>

#include "Car.h"

using namespace std;

/**
 * 打印数组
 * @param pArr
 * @param size
 */
void coutArray(int* pArr, int size) {
    for (int i = 0; i < size; i++) {
        cout << pArr[i] << " ";
    }
    cout << endl;
}

/**
 * 打印二维数组
 *
 * 三种形参方式接收数组实参
 *   int (*pMatrix)[5]
 *   int pMatrix[][5]
 *   int pMatrix[5][5]
 * @param pMatrix
 * @param m
 * @param n
 */
void coutMatrix(int pMatrix[][5], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << pMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * 打印二维数组
 * @param pMatrix
 * @param m
 * @param n
 */
void coutMatrix(int** pMatrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
//            cout << pMatrix[i][j] << " ";
            cout << *(*(pMatrix + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * malloc与free管理内存
 */
void mallocAndFree() {
    int* pInt = (int*) malloc(sizeof(int));
    *pInt = 500;
    cout << "*pInt = " << *pInt << endl;
    free(pInt);

    char* pChars = (char*) malloc(sizeof(char) * 4);
    *pChars = 'P';
    *(pChars + 1) = 'o';
    *(pChars + 2) = 'l';
    *(pChars + 3) = 'o';
    for (int i = 0; i < 4; i++) {
        cout << pChars[i];
    }
    cout << endl;
    cout << pChars << endl;
    free(pChars);
}

/**
 * 使用memset函数初始化字节
 *
 * 将四个字节设置为1：
 *      00000000 00000000 00000000 00000001
 *
 * 将四个字节中的每个字节设置为1
 *      00000001 00000001 00000001 00000001
 */
void mallocInit() {
    cout << "---------------------基本数据类型指针变量----------------------" << endl;
    int* pInt1 = (int*) malloc(sizeof(int));
    int* pInt2 = (int*) malloc(sizeof(int));
    // 将pInt2的四个字节，每一个字节都初始化为0，并不是将pInt2的四个字节设置为0
    memset(pInt2, 0, sizeof(int));
    cout << *pInt1 << endl;
    cout << *pInt2 << endl;
    free(pInt1);
    free(pInt2);

    cout << "---------------------一维数组----------------------" << endl;
    int* pArr1 = (int*) malloc(sizeof(int) * 10);
    memset(pArr1, 0, sizeof(int) * 10);
    coutArray(pArr1, 10);
    free(pArr1);

    cout << "-----------------------可以不固定第二维的大小基于二级指针的二维数组--------------------" << endl;
    int** pArr2 = (int**) malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        pArr2[i] = (int*) malloc(sizeof(int) * 5);
        // 初始化为0
        memset(pArr2[i], 0, sizeof(int) * 5);
    }
    coutMatrix(pArr2, 5, 5);
    for (int i = 0; i < 5; i++) {
        free(pArr2[i]);
    }
    free(pArr2);

    cout << "-----------------------基于指针数组的二维数组--------------------" << endl;
    int* pArr3[5];
    for (int i = 0; i < 5; i++) {
        pArr3[i] = (int*) malloc(sizeof(int) * 5);
        memset(pArr3[i], 0, sizeof(int) * 5);
    }
    coutMatrix(pArr3, 5, 5);
    for (int i = 0; i < 5; i++) {
        free(pArr3[i]);
    }
}

/**
 * new和delete管理内存
 */
void newAndDelete() {
    int* pInt = new int;
    *pInt = 800;
    cout << "*pInt = " << *pInt << endl;
    delete pInt;

    int* pArr = new int[4];
    pArr[0] = 100;
    pArr[1] = 200;
    pArr[2] = 300;
    pArr[3] = 400;
    for (int i = 0; i < 4; i++) {
        cout << pArr[i] << " ";
    }
    cout << endl;
    delete[] pArr;

    char* pChar = new char;
    *pChar = 'A';
    cout << *pChar << endl;
    delete pChar;

    char* pChars = new char[5];
    pChars[0] = 'H';
    pChars[1] = 'e';
    pChars[2] = 'l';
    pChars[3] = 'l';
    pChars[4] = 'o';
    for (int i = 0; i < 5; i++) {
        cout << pChars[i];
    }
    cout << endl;
    cout << pChars << endl;
    delete[] pChars;
}

/**
 * new初始化
 */
void newInit() {
    cout << "---------------------基本数据类型指针变量----------------------" << endl;
    // 不会初始化
    int* pInt1 = new int;
    // 初始化为0
    int* pInt2 = new int();
    // 初始化为指定的值
    int* pInt3 = new int(100);
    cout << "*pInt1 = " << *pInt1 << endl;
    cout << "*pInt2 = " << *pInt2 << endl;
    cout << "*pInt3 = " << *pInt3 << endl << endl;
    delete pInt1;
    delete pInt2;
    delete pInt3;

    int** pp1 = new int*;
    // pp1指针变量的地址
    cout << "&pp1 = " << &pp1 << endl;
    // pp1指向的新分配的内存地址
    cout << "pp1 = " << pp1 << endl;
    // pp1指向的新分配的内存地址的指针地址值，未初始化，是一个垃圾值
    cout << "*pp1 = " << *pp1 << endl;
    *pp1 = new int;
    // pp1指向的新分配的内存地址的指针地址值，是一个新分配的内存地址
    cout << "*pp1 = " << *pp1 << endl;
    // 二级指针最终的值，未初始化，是一个垃圾值
    cout << "**pp1 = " << **pp1 << endl << endl;
    delete *pp1;
    delete pp1;

    int** pp2 = new int*();
    // pp2指针变量的地址
    cout << "&pp2 = " << &pp2 << endl;
    // pp2指向的新分配的内存地址
    cout << "pp2 = " << pp2 << endl;
    // pp2指向的新分配的内存地址的指针地址值，初始化为0
    cout << "*pp2 = " << *pp2 << endl;
    *pp2 = new int();
    // pp2指向的新分配的内存地址的指针地址值，是一个新分配的内存地址
    cout << "*pp2 = " << *pp2 << endl;
    // 二级指针最终的值，初始化为0
    cout << "**pp2 = " << **pp2 << endl << endl;
    delete *pp2;
    delete pp2;

    cout << "---------------------一维数组----------------------" << endl;
    // 未初始化所有元素
    int* pArr1 = new int[5];
    // 将所有元素初始化为0
    int* pArr2 = new int[5]();
    // 将所有元素初始化为0
    int* pArr3 = new int[5]{};
    // 初始化第一个元素为5，其他元素为0
    int* pArr4 = new int[5]{5};
    coutArray(pArr1, 5);
    coutArray(pArr2, 5);
    coutArray(pArr3, 5);
    coutArray(pArr4, 5);
    delete[] pArr1;
    delete[] pArr2;
    delete[] pArr3;
    delete[] pArr4;

    cout << "-----------------------固定大小的二维数组--------------------" << endl;
    // 未初始化
    int (* pMatrix1)[5] = new int[5][5];
    // 将所有元素初始化为0
    int (* pMatrix2)[5] = new int[5][5]();
    // 将所有元素初始化为0
    int (* pMatrix3)[5] = new int[5][5]{};
    // 初始化第一行第一列的元素为5，其他元素都为0
    int (* pMatrix4)[5] = new int[5][5]{{5}};
    coutMatrix(pMatrix1, 5, 5);
    coutMatrix(pMatrix2, 5, 5);
    coutMatrix(pMatrix3, 5, 5);
    coutMatrix(pMatrix4, 5, 5);
    delete[] pMatrix1;
    delete[] pMatrix2;
    delete[] pMatrix3;
    delete[] pMatrix4;

    cout << "-----------------------可以不固定第二维的大小基于二级指针的二维数组--------------------" << endl;
    int** pMatrix5 = new int* [5]{};
    pMatrix5[0] = new int[5]{};
    pMatrix5[1] = new int[5]{};
//    pMatrix5[2] = new int[8] {1, 2, 3, 4, 5, 6, 7, 8};
    pMatrix5[2] = new int[5]{};
    pMatrix5[3] = new int[5]{};
    pMatrix5[4] = new int[5]{};
    coutMatrix(pMatrix5, 5, 5);
    for (int i = 0; i < 5; i++) {
        delete[] pMatrix5[i];
    }
    delete[] pMatrix5;

    cout << "-----------------------基于指针数组的二维数组--------------------" << endl;
    int* pMatrix6[5];
    for (int i = 0; i < 5; i++) {
        pMatrix6[i] = new int[5]{};
    }
    coutMatrix(pMatrix6, 5, 5);
    for (int i = 0; i < 5; i++) {
        delete[] pMatrix6[i];
    }
}

struct Person {
    int id;
    int height;
    int age;
};

void coutPersons(Person* persons, int m) {
    for (int i = 0; i < m; i++) {
        cout << persons[i].id << " " << persons[i].height << " " << persons[i].age << " " << endl;
    }
}

/**
 * memset是将较大数据结构(比如对象、数组等)内存清零比较快的方法
 */
void memsetReset() {
    Person p = {1, 180, 30};
    cout << p.id << " " << p.height << " " << p.age << " " << endl;
    memset(&p, 0, sizeof(p));
    cout << p.id << " " << p.height << " " << p.age << " " << endl;

    Person persons[] = {{1, 190, 50},
                        {2, 170, 40},
                        {3, 175, 50}};
    coutPersons(persons, 3);
    memset(persons, 0, sizeof(persons));
    coutPersons(persons, 3);
}

/**
 * 使用new创建对象
 */
void objectNew() {
    cout << "--------------------------------对象变量---------------------------------" << endl;
    Car* c1 = new Car();
    c1->display();
    delete c1;

    Car* c2 = new Car("Ferrari", 2, 800, 718);
    c2->display();
    delete c2;

    cout << "--------------------------------一维对象数组---------------------------------" << endl;
    Car* pCarArr1 = new Car[5]{{"Ferrari",     2, 800,  718},
                               {"Lamborghini", 2, 770,  720},
                               {"Bugatti",     2, 1500, 1600},
                               {"Pagani",      2, 750,  1000},
                               {"McLaren",     2, 765,  800}};
    Car::coutCarArray(pCarArr1, 5);
    delete[] pCarArr1;

    cout << "--------------------------------基于二级指针的二维对象数组---------------------------------" << endl;
    Car** pCarMatrix1 = new Car* [3];
    pCarMatrix1[0] = new Car[5]{{"Ferrari",     2, 800,  718},
                                {"Lamborghini", 2, 770,  720},
                                {"Bugatti",     2, 1500, 1600},
                                {"Pagani",      2, 750,  1000},
                                {"McLaren",     2, 765,  800}};
    pCarMatrix1[1] = new Car[5]{{"BMW",         2, 800,  718},
                                {"Lamborghini", 2, 770,  720},
                                {"Bugatti",     2, 1500, 1600},
                                {"Pagani",      2, 750,  1000},
                                {"McLaren",     2, 765,  800}};
    pCarMatrix1[2] = new Car[5]{{"Audi",        2, 800,  718},
                                {"Lamborghini", 2, 770,  720},
                                {"Bugatti",     2, 1500, 1600},
                                {"Pagani",      2, 750,  1000},
                                {"McLaren",     2, 765,  800}};
    Car::coutCarMatrix(pCarMatrix1, 3, 5);
    for (int i = 0; i < 3; i++) {
        delete[] pCarMatrix1[i];
    }
    delete[] pCarMatrix1;

    cout << "--------------------------------基于指针数组的二维对象数组---------------------------------" << endl;
    Car* pCarMatrix2[3];
    for (int i = 0; i < 3; i++) {
        pCarMatrix2[i] = new Car[5];
    }
    Car::coutCarMatrix(pCarMatrix2, 3, 5);
    for (int i = 0; i < 3; i++) {
        delete[] pCarMatrix2[i];
    }
}

/**
 * 使用malloc创建对象
 */
void objectMalloc() {
    cout << "--------------------------------对象变量---------------------------------" << endl;
    Car* c1 = (Car*) malloc(sizeof(Car));
    memset(c1, 0, sizeof(Car));
    c1->display();
    free(c1);

    Car* c2 = (Car*) malloc(sizeof(Car));
    c2->setBrand("Ferrari");
    c2->setHorsePower(800);
    c2->setSeatNum(2);
    c2->setTorque(718);
    c2->display();
    free(c2);

    cout << "--------------------------------一维对象数组---------------------------------" << endl;
    Car* carArr1 = (Car*) malloc(sizeof(Car) * 5);
    memset(carArr1, 0, sizeof(Car) * 5);
    Car::coutCarArray(carArr1, 5);
    free(carArr1);

    cout << "--------------------------------基于二级指针的二维对象数组---------------------------------" << endl;
    Car** carMatrix1 = (Car**) malloc(sizeof(Car*) * 3);
    for (int i = 0; i < 3; i++) {
        carMatrix1[i] = (Car*) malloc(sizeof(Car) * 5);
        memset(carMatrix1[i], 0, sizeof(Car) * 5);
    }
    Car::coutCarMatrix(carMatrix1, 3, 5);
    for (int i = 0; i < 3; i++) {
        free(carMatrix1[i]);
    }
    free(carMatrix1);

    cout << "--------------------------------基于指针数组的二维对象数组---------------------------------" << endl;
    Car* carMatrix2[3];
    for (int i = 0; i < 3; i++) {
        carMatrix2[i] = (Car*) malloc(sizeof(Car) * 5);
        memset(carMatrix2[i], 0, sizeof(Car) * 5);
    }
    Car::coutCarMatrix(carMatrix2, 3, 5);
    for (int i = 0; i < 3; i++) {
        free(carMatrix2[i]);
    }
}

int main() {
//    mallocAndFree();
//    newAndDelete();
//    mallocInit();
    newInit();
//    memsetReset();
//    objectNew();
//    objectMalloc();
    return 0;
}
