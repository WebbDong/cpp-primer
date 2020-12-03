//
// Created by WebbDong on 9/3/2020.
//

#include "ArithmeticException.h"

namespace error {

    const char* ArithmeticException::what() const noexcept {
        return "ArithmeticException / by zero";
    }

}