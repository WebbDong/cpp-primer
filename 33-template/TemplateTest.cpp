//
// Created by WebbDong on 9/2/2020.
//

#include "TemplateTest.h"

namespace dwb {

    template<class T>
    TemplateTest<T>::TemplateTest(T data) : data(data) {}

    template<class T>
    T TemplateTest<T>::division(T a, T b) {
        return a / b;
    }

}
