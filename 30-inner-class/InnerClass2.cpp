//
// Created by WebbDong on 8/31/2020.
//

#include "InnerClass2.h"

namespace dwb {

    SuperClass2::InnerClass2::InnerClass2(const std::string& name) : name(name) {}

    const std::string& SuperClass2::InnerClass2::getName() const {
        return name;
    }

    void SuperClass2::InnerClass2::setName(const std::string& name) {
        InnerClass2::name = name;
    }

}