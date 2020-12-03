//
// Created by WebbDong on 2020/4/10.
//

#ifndef INC_3_EXTERN_C_MATH_H
#define INC_3_EXTERN_C_MATH_H

// 如果是C++环境，就将方法定义通过extern "C"包起来
#ifdef __cplusplus
extern "C" {
#endif

int sum(int a, int b);
int subtraction(int a, int b);

#ifdef __cplusplus
}
#endif
#endif //INC_3_EXTERN_C_MATH_H
