//
// Created by WebbDong on 11/15/2020.
//

#ifndef INC_41_SMART_POINTER_MYAUTOPTR_HPP
#define INC_41_SMART_POINTER_MYAUTOPTR_HPP

namespace dwb {

    template <typename T>
    class MyAutoPtr {
    public:
        MyAutoPtr(T* instance) : instance(instance) {}

        ~MyAutoPtr() {
            if (instance != nullptr) {
                delete instance;
            }
        }

        T* operator->() {
            return instance;
        }

    private:
        T* instance;
    };

}

#endif //INC_41_SMART_POINTER_MYAUTOPTR_HPP
