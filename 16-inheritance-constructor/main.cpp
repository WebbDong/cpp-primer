#include <iostream>

#include "Student.h"
#include "Teacher.h"
#include "EliteStudent.h"

/**
 * 继承关系下的构造函数
 *      1、子类的构造函数默认会调用父类的无参构造函数。
 *      2、如果子类显式的调用了父类的构造函数，就不会默认调用父类的无参构造函数。
 *      3、如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数。
 *      4、如果父类没有任何构造函数，子类的构造函数就不会调用父类的构造函数，更不会自动生成一个无参的构造函数。
 *      5、子类创建时，会先调用父类的构造函数层级往上调用。子类销毁时，会先调用子类的析构函数层级往下调用。
 * @return
 */
int main() {
    std::cout << "--------------------------------------" << std::endl;
    {
        dwb::Student student1;
        student1.sayHello();
        student1.study();
    }

    {
        dwb::Student student2("Adam", 35, 180, 80.5);
        student2.sayHello();
        student2.study();
    }

    {
        dwb::Teacher teacher1;
        teacher1.sayHello();
        teacher1.teach();
    }

    {
        dwb::Teacher teacher2("Conner", 50, 180, 10000);
        teacher2.sayHello();
        teacher2.teach();
    }

    {
        dwb::EliteStudent eliteStudent1("Lisa", 30, 170, 100, 3000);
        eliteStudent1.sayHello();
        eliteStudent1.study();
        eliteStudent1.dissert();
    }
    return 0;
}
