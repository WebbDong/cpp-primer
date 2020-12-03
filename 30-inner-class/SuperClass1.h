//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_30_INNER_CLASS_SUPERCLASS1_H
#define INC_30_INNER_CLASS_SUPERCLASS1_H

#include <string>

namespace dwb {

    class SuperClass1 {
    public:
        // 声明内部类
        class InnerClass1;

        SuperClass1(int num);

        int getNum() const;

        void setNum(int num);

    private:
        int num;
    };

    // 定义内部类
    class SuperClass1::InnerClass1 {
    public:
        InnerClass1(const std::string& name);

        const std::string& getName() const;

        void setName(const std::string& name);

    private:
        std::string name;
    };

}

#endif //INC_30_INNER_CLASS_SUPERCLASS1_H
