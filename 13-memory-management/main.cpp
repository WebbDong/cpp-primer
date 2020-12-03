#include <iostream>
#include "Person.h"

/**
 * 对象内部申请的堆空间，由对象内部回收
 * @return
 */
int main() {
    Person person("Adam", 40);
    person.display();
    return 0;
}
