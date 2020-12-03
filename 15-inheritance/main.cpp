#include "Student.h"
#include "Teacher.h"

/**
 * 继承
 *      成员访问权限
 *          public：公共的，任何地方都可以访问（struct默认）
 *          protected：子类内部、当前类内部可以访问
 *          private：私有的，只有当前类内部可以访问（class默认）
 *
 *      继承访问权限：
 *          public：相当于先将从父类那里继承的全部成员（除了构造函数和析构函数）放到子类的public部分
 *          protected：保护继承相当于先将从父类继承的所用成员（除了构造函数和析构函数）都放在子类的protected部分
 *          private：私有继承相当于先将从父类继承的所用成员（除了构造函数和析构函数）都放在子类的private部分
 *
 *          class的默认继承方式是private，struct默认的继承方式是public
 *
 *      子类内部访问父类成员的权限，是以下2项中权限最小的那个
 *          最顶层父类中成员本身的访问权限
 *          上一级父类的继承方式
 * @return
 */
int main() {
    dwb::Teacher teacher("Adam", 40, 180, 10000);
    teacher.sayHello();
    teacher.teach();

    dwb::Student student("Conner", 20, 185, 98);
    student.sayHello();
    student.study();
    return 0;
}
