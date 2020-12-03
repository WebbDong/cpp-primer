//
// Created by WebbDong on 8/28/2020.
//

#ifndef INC_20_STATIC_MEMBER_EARLYSINGLETON_H
#define INC_20_STATIC_MEMBER_EARLYSINGLETON_H

namespace dwb {

    /**
     * 单例饿汉式
     */
    class EarlySingleton {
    public:
        static EarlySingleton* getInstance();

        void func();

    private:
        // 私有化构造函数
        EarlySingleton();

        EarlySingleton(const EarlySingleton& instance);

        ~EarlySingleton();

        // 私有化赋值运算符重载
        void operator=(const EarlySingleton& instance) = delete;

        static EarlySingleton instance;
    };

}

#endif //INC_20_STATIC_MEMBER_EARLYSINGLETON_H
