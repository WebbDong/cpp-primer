//
// Created by WebbDong on 9/3/2020.
//

#ifndef INC_35_EXCEPTION_ARITHMETICEXCEPTION_H
#define INC_35_EXCEPTION_ARITHMETICEXCEPTION_H

#include <exception>

namespace error {

    class ArithmeticException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

}

#endif //INC_35_EXCEPTION_ARITHMETICEXCEPTION_H
