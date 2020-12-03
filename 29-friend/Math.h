//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_29_FRIEND_MATH_H
#define INC_29_FRIEND_MATH_H

#include "Point.h"

namespace dwb {

    class Math {
    public:
        static Point add(Point p1, Point p2);

        static Point subtraction(Point p1, Point p2);

        static Point multiplication(Point p1, Point p2);

        static Point division(Point p1, Point p2);

    };

}

#endif //INC_29_FRIEND_MATH_H
