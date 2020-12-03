//
// Created by WebbDong on 9/2/2020.
//

#ifndef INC_33_TEMPLATE_TEMPLATETEST_H
#define INC_33_TEMPLATE_TEMPLATETEST_H

namespace dwb {

    template<class T>
    class TemplateTest {
    public:
        TemplateTest(T data);

        T division(T a, T b);

        T data;
    };

    // 显示的指定类的泛型类型，让编译器实例化这些类型的模板，不实用
    template class TemplateTest<int>;
    template class TemplateTest<double>;
    template class TemplateTest<long>;

}

#endif //INC_33_TEMPLATE_TEMPLATETEST_H
