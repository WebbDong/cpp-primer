//
// Created by WebbDong on 8/31/2020.
//

#include "SuperClass1.h"

namespace dwb {

    SuperClass1::SuperClass1(int num) : num(num) {}

    int SuperClass1::getNum() const {
        return num;
    }

    void SuperClass1::setNum(int num) {
        SuperClass1::num = num;
    }

    SuperClass1::InnerClass1::InnerClass1(const std::string& name) : name(name) {}

    const std::string& SuperClass1::InnerClass1::getName() const {
        return name;
    }

    void SuperClass1::InnerClass1::setName(const std::string& name) {
        InnerClass1::name = name;
    }

}