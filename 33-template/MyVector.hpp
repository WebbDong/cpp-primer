//
// Created by WebbDong on 9/2/2020.
//

#ifndef INC_33_TEMPLATE_MYVECTOR_HPP
#define INC_33_TEMPLATE_MYVECTOR_HPP

#include <iostream>
#include <string.h>

namespace dwb {

    template<typename T> class MyVector;

    // 需要在类前面首先声明类模板友元函数
    template<typename T> std::ostream& operator<<(std::ostream& cout, const MyVector<T>& vector);

    /**
     * 动态数组
     * @tparam T
     */
    template<typename T>
    class MyVector {
    public:
        /**
         * 构造函数
         * @param capacity 数组初始大小
         */
        MyVector(int capacity = DEFAULT_CAPACITY);

        ~MyVector();

        /**
         * 添加元素到最后
         * @param item
         * @return
         */
        void add(T item);

        /**
         * 插入到指定位置
         * @param index
         * @param item
         */
        void insert(int index, T item);

        /**
         * 设置指定位置的元素
         * @param index
         * @param item
         */
        T set(int index, T item);

        /**
         * 清空数组
         */
        void clear();

        /**
         * 获取元素
         * @param index
         * @return
         */
        T get(int index) const;

        /**
         * 删除元素
         * @param index
         */
        void remove(int index);

        /**
         * 获取元素数量
         * @return
         */
        int getSize() const;

        /**
         * 数组[]方式获取元素
         * @param index
         * @return
         */
        T operator[](int index) const;

        // 类中的声明需要在方法名后加上<>
        friend std::ostream& operator<<<>(std::ostream& cout, const MyVector<T>& vector);

    private:
        /**
         * 调整数组大小
         */
        void resize();

        /**
         * 检查数组角标
         * @return
         */
        bool checkIndex(int index) const;

        /**
         * 数据数组
         */
        T* datas;

        /**
         * 当前元素大小
         */
        int size = 0;

        /**
         * 数组大小
         */
        int capacity;

        /**
         * 默认数组大小
         */
        static const int DEFAULT_CAPACITY = 10;
    };

    // ------------------constructor----------------------

    template<typename T>
    MyVector<T>::MyVector(int capacity) {
        this->capacity = capacity > 0 ? capacity : DEFAULT_CAPACITY;
        this->datas = new T[this->capacity];
    }

    template<typename T>
    MyVector<T>::~MyVector() {
        if (datas != nullptr) {
            delete[] datas;
        }
    }

    // ------------------public method----------------------

    template<typename T>
    void MyVector<T>::add(T item) {
        if (size >= capacity) {
            resize();
        }
        datas[size++] = item;
    }

    template<typename T>
    void MyVector<T>::insert(int index, T item) {
        if (!checkIndex(index)) {
            throw "数组越界";
        }
        if ((size + 1) >= capacity) {
            resize();
        }
        // 数据后移
        memcpy(datas + index + 1, datas + index, (size - index) * sizeof(T));
        datas[index] = item;
        size++;
    }

    template<typename T>
    T MyVector<T>::set(int index, T item) {
        if (!checkIndex(index)) {
            throw "数组越界";
        }
        T oldItem = datas[index];
        datas[index] = item;
        return oldItem;
    }

    template<typename T>
    void MyVector<T>::clear() {
        memset(datas, 0, size * sizeof(int));
    }

    template<typename T>
    T MyVector<T>::get(int index) const {
        if (!checkIndex(index)) {
            throw "数组越界";
        }
        return datas[index];
    }

    template<typename T>
    void MyVector<T>::remove(int index) {
        if (!checkIndex(index)) {
            throw "数组越界";
        }
        memcpy(datas + index, datas + index + 1, (size - index - 1) * sizeof(T));
        size--;
    }

    template<typename T>
    int MyVector<T>::getSize() const {
        return size;
    }

    // ------------------public operator----------------------

    template<typename T>
    T MyVector<T>::operator[](int index) const {
        return get(index);
    }

    // 实现方法名后不需要加<>
    template<typename T>
    std::ostream& operator<<(std::ostream& cout, const MyVector<T>& vector) {
        cout << "[";
        for (int i = 0; i < vector.size; i++) {
            if (i != 0) {
                cout << ", ";
            }
            cout << vector.datas[i];
        }
        return cout << "]";
    }

    // ------------------private method----------------------

    template<typename T>
    void MyVector<T>::resize() {
        int oldCapacity = capacity;
        // 数组大小扩充2倍
        capacity *= 2;
        // 分配新数组
        T* newDatas = new T[capacity];
        memcpy(newDatas, datas, oldCapacity * sizeof(T));
        delete[] datas;
        datas = newDatas;
    }

    template<typename T>
    bool MyVector<T>::checkIndex(int index) const {
        return index >= 0 && index < size;
    }

}

#endif //INC_33_TEMPLATE_MYVECTOR_HPP
