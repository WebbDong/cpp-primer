//
// Created by WebbDong on 8/23/2020.
//

#ifndef INC_14_NAMESPACE_CAR_H
#define INC_14_NAMESPACE_CAR_H

namespace dwb {
    class Car {
    public:
        Car();

        Car(int horsePower);

        void display();

    private:
        int horsePower;
    };
}

#endif //INC_14_NAMESPACE_CAR_H
