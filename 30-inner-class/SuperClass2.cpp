//
// Created by WebbDong on 8/31/2020.
//

#include "SuperClass2.h"

namespace dwb {

    SuperClass2::SuperClass2(int num) : num(num) {}

    int SuperClass2::getNum() const {
        return num;
    }

    void SuperClass2::setNum(int num) {
        SuperClass2::num = num;
    }

}