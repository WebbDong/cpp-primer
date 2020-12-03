//
// Created by WebbDong on 9/18/2020.
//
#include <iostream>
#include <climits>

#include "LongLongTest.h"

namespace dwb {

    /**
     * long long超长整形
     *      C++11 标准规定，每种整数类型必须同时具备有符号（signed）和无符号（unsigned）两种类型，
     *      且每种具体的有符号整形和无符号整形所占用的存储空间（也就是位数）必须相同。
     *      注意，C++11 标准中只限定了每种类型最少占用多少存储空间，不同的平台可以占用不同的存储空间。
     *
     *      如同 long 类型整数需明确标注 "L" 或者 "l" 后缀一样，要使用 long long 类型的整数，也必须标注对应的后缀：
     *          对于有符号 long long 整形，后缀用 "LL" 或者 "ll" 标识。例如，"10LL" 就表示有符号超长整数 10；
     *          对于无符号 long long 整形，后缀用 "ULL"、"ull"、"Ull" 或者 "uLL" 标识。例如，"10ULL" 就表示无符号超长整数 10；
     *
     *      如果不添加任何标识，则所有的整数都会默认为 int 类型。
     *
     *      对于 long long 类型来说，如果想了解当前平台上 long long 整形的取值范围，可以使用<climits>头文件中
     *      与 long long 整形相关的 3 个宏，分别为 LLONG_MIN、LLONG_MAX 和 ULLONG_MIN：
     *          LLONG_MIN：代表当前平台上最小的 long long 类型整数；
     *          LLONG_MAX：代表当前平台上最大的 long long 类型整数；
     *          ULLONG_MIN：代表当前平台上最大的 unsigned long long 类型整数（无符号超长整型的最小值为 0）；
     */
    void LongLongTest::test() {
        // std::dec 输出十进制
        // std::oct 输出八进制
        // std::hex 输出十六进制
        std::cout <<"long long最小值：" << LLONG_MIN <<" "<< std::hex << LLONG_MIN <<"\n";
        std::cout << std::dec <<"long long最大值：" << LLONG_MAX << " " << std::hex << LLONG_MAX << "\n";
        std::cout << std::dec << "unsigned long long最大值：" << ULLONG_MAX << " " << std::hex << ULLONG_MAX << std::endl;

        long long num1 = 9000LL;
        unsigned long long num2 = 50000ULL;
        int num3 = 800;
        std::cout << std::dec << "num1 = " << num1 << ", num2 = " << num2 << ", num3 = " << num3 << std::endl;
    }

}