//
// Created by WebbDong on 9/1/2020.
//

#ifndef INC_32_OPERATOR_OVERLOAD_POINT_H
#define INC_32_OPERATOR_OVERLOAD_POINT_H

namespace dwb {

    class Point {
    public:
        Point(float x = 0.0f, float y = 0.0f);

        void display();

        friend const Point operator+(const Point& p1, const Point& p2);

        // 写法二、 减法运算符重载成员函数声明
//        const Point operator-(const Point& p) const;

        // 写法三、减法运算符重载友元函数
        friend const Point operator-(const Point& p1, const Point& p2);

        // <<运算符重载，如果定义为成员函数，那只能由对象来调用，参数不自由。
        friend std::ostream& operator<<(std::ostream& cout, const Point& p);

        friend std::istream& operator>>(std::istream& cin, Point& p);

        const Point operator*(const Point& p) const;

        const Point operator/(const Point& p) const;

        bool operator==(const Point& p) const;

        bool operator!=(const Point& p) const;

        const Point operator-() const;

        Point& operator+=(const Point& p);

        Point& operator-=(const Point& p);

        // 前置++
        Point& operator++();

        // 后置++，固定写法
        Point operator++(int);

        // 前置--
        Point& operator--();

        // 后置--，固定写法
        Point operator--(int);

        float operator[](int index) const;

        // 赋值运算符重载，可重新定义赋值行为
//        Point& operator=(const Point& p);

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

    private:
        // 私有化赋值运算符重载，可以禁止在外部使用赋值运算符
//        void operator=(const Point& p) = delete;

    private:
        float x;
        float y;
    };

    // 写法一、 全局+运算符重载函数声明
    const Point operator+(const Point& p1, const Point& p2);

}

#endif //INC_32_OPERATOR_OVERLOAD_POINT_H
