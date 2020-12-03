#include "EarlySingleton.h"
#include "LazilySingleton.h"

/**
 * 单例模式
 * @return
 */
int main() {
    dwb::EarlySingleton* instance1 = dwb::EarlySingleton::getInstance();
    instance1->func();

    dwb::LazilySingleton* instance2 = dwb::LazilySingleton::getInstance();
    instance2->func();

    // 将析构函数私有化之后，外部不能调用delete释放内存
//    delete instance2;
    dwb::LazilySingleton::release();
    return 0;
}
