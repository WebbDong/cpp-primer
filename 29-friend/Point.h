//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_29_FRIEND_POINT_H
#define INC_29_FRIEND_POINT_H

namespace dwb {

    class Point {
    public:
        // 友元函数
        friend Point add2(Point p1, Point p2);

        // 友元类
        friend class Math;

        Point(float x, float y);

        void display() const;

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

    private:
        float x;
        float y;
    };

    // 友元函数声明
    Point add2(Point p1, Point p2);

}

#endif //INC_29_FRIEND_POINT_H
