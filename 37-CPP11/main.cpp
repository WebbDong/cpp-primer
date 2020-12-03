
#include "AutoTest.h"
#include "DecltypeTest.h"
#include "TrailingReturnTypeTest.h"
#include "DefinitionByUsingTest.h"
#include "InitializationListTest.h"
#include "LambdaTest.h"
#include "UnrestrictedUnionTest.h"
#include "ForLoopTest.h"
#include "ConstexprTest.h"
#include "LongLongTest.h"
#include "RightValueReferenceTest.h"
#include "NullptrTest.h"

/**
 * C++11新特性
 *      1、auto类型推导
 *      2、decltype类型推导
 *      3、auto和decltype的区别
 *          a、语法格式的区别
 *              auto varname = value;
 *              decltype(exp) varname [= value];
 *          b、数据类型推导逻辑区别
 *              auto 根据=右边的初始值 value 推导出变量的类型
 *              decltype 根据 exp 表达式推导出变量的类型，跟=右边的 value 没有关系
 *          c、auto 要求变量必须初始化，而 decltype 不要求
 *          d、对 cv 限定符的处理
 *              「cv 限定符」是 const 和 volatile 关键字的统称：
 *                  * const 关键字用来表示数据是只读的，也就是不能被修改。
 *                  * volatile 目的是不让 CPU 将数据缓存到寄存器，而是从原始的内存中读取。
 *               在推导变量类型时，auto 和 decltype 对 cv 限制符的处理是不一样的。decltype 会保留 cv 限定符，而 auto 有可能会去掉 cv 限定符。
 *               auto 关键字对 cv 限定符的推导规则：
 *                  * 如果表达式的类型不是指针或者引用，auto 会把 cv 限定符直接抛弃，推导成 non-const 或者 non-volatile 类型。
 *                      如果要保留cv特性，必须显示指定
 *                  * 如果表达式的类型是指针或者引用，auto 将保留 cv 限定符。
 *          e、对引用的处理
 *              当表达式的类型为引用时，auto 和 decltype 的推导规则也不一样；decltype 会保留引用类型，而 auto 会抛弃引用类型，直接推导出它的原始类型。
 *                  如果要保留引用特性，就必须显示指定
 *      4、对模板实例化中连续右尖括号>>的改进
 *      5、使用using定义别名（替代typedef）
 *      6、支持函数模板的默认模板参数
 *      7、lambda 表达式
 *      8、非受限联合体（Unrestricted Union）
 *      9、C++11 for循环增强
 *      10、constexpr：验证是否为常量表达式
 *      11、long long超长整形
 *      12、右值引用
 *      13、nullptr：初始化空指针
 *      14、shared_ptr智能指针
 *      15、unique_ptr智能指针
 *      16、weak_ptr智能指针
 */
int main() {
//    dwb::AutoTest::test();
//    dwb::DecltypeTest::test();
//    dwb::TrailingReturnTypeTest::test();
//    dwb::DefinitionByUsingTest::test();
//    dwb::InitializationListTest::test();
//    dwb::LambdaTest::test();
//    dwb::UnrestrictedUnionTest::test();
//    dwb::ForLoopTest::test();
//    dwb::ConstexprTest::test();
//    dwb::LongLongTest::test();
//    dwb::RightValueReferenceTest::test();
    dwb::NullptrTest::test();
    return 0;
}
