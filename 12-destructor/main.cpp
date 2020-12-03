#include "Person.h"

using namespace std;

Person globalPerson("Webb", 30);

/**
 * 通过malloc分配的创建的对象，调用free时不会调用析构函数
 * @return
 */
int main() {
    Person person1("Adam", 40);

    Person* pPerson1 = new Person("Conner", 36);
    delete pPerson1;

    Person* pPerson2 = (Person*) malloc(sizeof(Person));
    pPerson2->setName("Lisa");
    pPerson2->setAge(30);
    // 不会调用析构函数
    free(pPerson2);
    return 0;
}
