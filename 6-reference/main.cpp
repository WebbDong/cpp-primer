#include <iostream>

void swap(int& v1, int& v2) {
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int func() {
    return 100;
}

int sum(const int& a, const int& b) {
    return a + b;
}

// 重载
int sum(int& a, int& b) {
    return a + b;
}

// 数组引用参数方式一
void funcRefArrayParam(int (&refArray)[5]) {
    std::cout << "funcRefArrayParam(int (&refArray)[5]) ";
    for (auto d : refArray) {
        std::cout << d << " ";
    }
}

// 数组引用参数方式二
void funcRefArrayParam2(int* const& refArray, int size) {
    std::cout << "funcRefArrayParam2(int* const& refArray, int size) ";
    for (int i = 0; i < size; i++) {
        std::cout << refArray[i] << " ";
    }
}

int sumConstPointer(const int* a, const int* b) {
    return *a + *b;
}

int& returnRefFunc(int *arr) {
    return arr[2];
}

int* returnPointerFunc(int *arr) {
    return arr + 2;
}

int& returnRefFunc() {
//    int num = 900;
    // 不可以返回局部变量的引用
//    return num;
    static int staticNum = 666;
    // 可以返回静态变量的引用
    return staticNum;
}

int* returnPointerFunc2() {
//    int num = 5000;
    // 不可以返回局部变量的地址指针
//    return &num;
    static int staticNum = 800000;
    // 可以返回静态变量的地址指针
    return &staticNum;
}

struct Date {
    int year;
    int month;
    int day;
};

/**
    引用
        1、再C语言中，使用指针(Pointer)可以间接获取、修改某个变量的值，而在C++中，使用引用(Reference)可以起到与指针类似的功能
        2、引用相当于变量的别名(基本数据类型、枚举、结构体、类、指针、数组等，都可以使用引用)
        3、对引用做计算，就是对引用所指向的变量做计算
        4、在定义的时候就必须初始化，一旦指向了某个变量，就不能再改变。
        5、可以使用引用初始化另一个引用，相当于某个变量的多个别名
        6、不存在引用的引用、指向引用的指针、引用数组

    引用存在的价值
        1、比指针更安全、函数返回值可以被赋值

    引用的本质
        1、引用的本质就是指针，只是编译器弱化了它的功能，所以引用就是弱化了的指针
        2、一个引用占用一个指针的大小

    const引用的特点
        1、可以给const引用赋值变量、常量、表达式、函数返回值
        2、可以指向不同类型的数据
        3、作为函数参数时，第一条和第二条规则也适用
            可以接收const和非const实参（非const引用，只能接收非const实参）
            可以跟非const引用参数的函数构成重载
        4、当const引用指向了不同类型的数据时，会生成临时变量，引用指向的并不是初始化时指定的变量，而是临时变量。

    注意：
        当函数返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
        当函数返回一个指针时，要注意返回的变量的指针不能超出作用域。所以返回一个对局部变量的地址是不合法的，但是，可以返回一个对静态变量的地址。
 * @return
 */
int main() {
    int age = 20;
    int& refAge = age;
    // 等价于age = 30
    refAge = 30;
    std::cout << "age = " << age << std::endl;
    std::cout << "refAge = " << refAge << std::endl;
    age = 500;
    std::cout << "age = " << age << std::endl;
    std::cout << "refAge = " << refAge << std::endl;

    int height = 1000;
    // 等价于 age = height
    refAge = height;
    std::cout << "age = " << age << std::endl;
    std::cout << "refAge = " << refAge << std::endl;
    // &refAge相当于&age，取得是age的地址
    std::cout << "&refAge = " << &refAge << "---- &age = " << &age << std::endl;
    std::cout << "------------------------------" << std::endl;

    int x = 100;
    int y = 500;
    swap(x, y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "------------------------------" << std::endl;

    // ----------------------------------------------------------------------

    // 结构体引用
    Date d = {2020, 8, 17};
    Date& refDate = d;
    std::cout << refDate.year << "年" << refDate.month << "月" << refDate.day << "日" << std::endl;

    int* pAge = &age;
    // 指针的引用
    int*& agePointerRef = pAge;
    // 指针引用变量agePointerRef的地址
    std::cout << "&agePointerRef = " << &agePointerRef << std::endl;
    // age的地址
    std::cout << "agePointerRef = " << agePointerRef << std::endl;
    std::cout << "&age = " << &age << std::endl;
    // age的值
    std::cout << "*agePointerRef = " << *agePointerRef << std::endl;

    agePointerRef = &x;
    std::cout << "agePointerRef = " << agePointerRef << std::endl;
    std::cout << "*agePointerRef = " << *agePointerRef << std::endl;
    std::cout << "------------------------------" << std::endl;

    int arr1[] = {1, 2, 3, 4, 5};
    // 数组引用写法一，数组元素数量必须指定
    int (&arrRef1)[5] = arr1;
    // 数组引用写法二，不能指定数组元素数量
    int* const& arrRef2 = arr1;
    for (int i = 0, size = sizeof(arrRef1) / sizeof(arrRef1[0]); i < size; i++) {
        std::cout << arrRef1[i] << " ";
    }
    std::cout << std::endl;
    funcRefArrayParam(arr1);
    std::cout << std::endl;
    funcRefArrayParam2(arr1, 5);
    std::cout << std::endl;
    for (int i = 0, size = 5; i < size; i++) {
        std::cout << arrRef2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "sizeof(arrRef1) = " << sizeof(arrRef1) << "  sizeof(arrRef1[0]) = " << sizeof(arrRef1[0])
              << std::endl;
    std::cout << "sizeof(arrRef2) = " << sizeof(arrRef2) << "  sizeof(arrRef2[0]) = " << sizeof(arrRef2[0])
              << std::endl;
    std::cout << "------------------------------" << std::endl;

    // ----------------------------------------------------------------------

    // 常量引用
    const double PI = 3.1434926535;
    const double& piRef = PI;
    std::cout << piRef << std::endl;
    std::cout << "------------------------------" << std::endl;

    // 可以给常量引用赋值常量、表达式、函数返回值
    const int& constRef1 = 50;
    std::cout << constRef1 << std::endl;
    const int& constRef2 = x + y;
    std::cout << constRef2 << std::endl;
    const int& constRef3 = func();
    std::cout << constRef3 << std::endl;

    // 常量引用可以指向不同类型的数据
    const int& constRef4 = PI;
    // 输出3，自动转换成了3，将小数丢弃
    std::cout << constRef4 << std::endl;
    std::cout << "------------------------------" << std::endl;

    // ----------------------------------------------------------------------

    // 作为函数参数
    int total1 = sum(x, y);
    std::cout << total1 << std::endl;
    int total2 = sum(60, PI);
    std::cout << total2 << std::endl;
    std::cout << "------------------------------" << std::endl;

    int num = 500;
    // numRef指向的是临时变量，所以修改了num的值是，并没有影响到numRef
    const double& numRef = num;
    num = 6000;
    std::cout << "num = " << num << "  numRef = " << numRef << std::endl;
    std::cout << "------------------------------" << std::endl << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    // 函数返回的int引用，是数组第三个元素的引用，可以直接修改
    returnRefFunc(arr) = 50;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    *(returnPointerFunc(arr)) = 6000;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int& returnRef = returnRefFunc();
    std::cout << returnRef << std::endl;
    std::cout << &returnRef << std::endl;

    int* returnPointerRef = returnPointerFunc2();
    std::cout << *returnPointerRef << std::endl;
    std::cout << returnPointerRef << std::endl;

    // ----------------------------------------------------------------------

    return 0;
}
