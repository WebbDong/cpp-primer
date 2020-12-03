#include <iostream>
#include <string>

int staticNum1 = 100;
static int staticNum2 = 300;

/**
 * 局部类
 *      1、在一个函数内部定义的类，称为局部类
 *      2、局部类的特点
 *          作用域仅限于所在的函数内部
 *          其所有的成员必须定义在类内部，不允许定义static成员变量
 *          成员函数不能直接访问函数的局部变量（static变量除外）
 * @return
 */
int main() {
    class PartialClass {
    public:
        PartialClass(const std::string& str, int num) : str(str), num(num) {}

        void display() {
            std::cout << "str = " << str << ", num = " << num
                      << ", staticNum1 = " << staticNum1 << ", staticNum2 = " << staticNum2
                      << std::endl;
        }

    private:
        std::string str;
        int num;
    };

    PartialClass pc1("Conner", 45);
    pc1.display();
    return 0;
}
