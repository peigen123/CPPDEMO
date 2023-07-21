#ifndef __ENCLOSED_H__
#define __ENCLOSED_H__

#include <iostream>
using namespace std;
namespace EnclosedClass
{
    class EnclosedInter1
    {
        private:
            int ei_;
        public:
            EnclosedInter1 (int ei) : ei_(ei){ cout << "EnclosedInter1 cons "<< endl; }
            ~EnclosedInter1 (){ cout << "EnclosedInter1 decons" << endl; }
            void show()
            {
                cout << "ei1 = " << ei_ << endl;
            }
    };

    class EnclosedInter2
    {
        private:
            int ei_;
        public:
            EnclosedInter2(){ ei_ = 100; }
            EnclosedInter2 (int ei) : ei_(ei){ cout << "EnclosedInter2 cons" << endl; }
            ~EnclosedInter2 (){ cout << "EnclosedInter2 decons" << endl; }
            void show()
            {
                cout << "ei2 = " << ei_ << endl;
            }
    };

    class EnclosedOut
    {
        private:
            int eo_;
            EnclosedInter1 ei1_;
            EnclosedInter2 ei2_;
        public:
           // EnclosedOut() { eo_ = 1; }        // 这样也是不行的因为EnclosedInter1没有默认构造函数，如果允许这一条那么假设外面定义用的是构造函数那么无论如何EnclosedInter1都没办法构造
            EnclosedOut(int i1, int i2) : ei1_(i1), ei2_(i2){ cout << "EnclosedOut cons" << endl; }  // ei1_(i1_)实际上就是构造ei1_
            ~EnclosedOut (){ cout << "EnclosedOut decons" << endl; }
            void show()
            {
                ei1_.show();
                ei2_.show();
            }
    };
    
}


#endif
