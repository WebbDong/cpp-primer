//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_21_SINGLETON_LAZILYSINGLETON_H
#define INC_21_SINGLETON_LAZILYSINGLETON_H

namespace dwb {

    /**
     * 单例饿汉式
     */
    class LazilySingleton {
    public:
        static LazilySingleton* getInstance();

        static void release();

        void func();

    private:
        // 将构造函数私有化之后，外部不能创建对象
        LazilySingleton();

        LazilySingleton(const LazilySingleton& instance);

        // 将析构函数私有化之后，外部不能调用delete释放内存
        ~LazilySingleton();

        void operator=(const LazilySingleton& instance) = delete;

        static LazilySingleton* instance;
    };

}

#endif //INC_21_SINGLETON_LAZILYSINGLETON_H
