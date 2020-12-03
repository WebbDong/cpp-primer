//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_30_INNER_CLASS_INNERCLASS2_H
#define INC_30_INNER_CLASS_INNERCLASS2_H

#include <string>

#include "SuperClass2.h"

namespace dwb {

    // 定义内部类
    class SuperClass2::InnerClass2 {
    public:
        InnerClass2(const std::string& name);

        const std::string& getName() const;

        void setName(const std::string& name);

    private:
        std::string name;
    };

}

#endif //INC_30_INNER_CLASS_INNERCLASS2_H
