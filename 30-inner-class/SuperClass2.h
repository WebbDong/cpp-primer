//
// Created by WebbDong on 8/31/2020.
//

#ifndef INC_30_INNER_CLASS_SUPERCLASS2_H
#define INC_30_INNER_CLASS_SUPERCLASS2_H

namespace dwb {

    class SuperClass2 {
    public:
        // 声明内部类
        class InnerClass2;

        SuperClass2(int num);

        int getNum() const;

        void setNum(int num);

    private:
        int num;
    };

}

#endif //INC_30_INNER_CLASS_SUPERCLASS2_H
