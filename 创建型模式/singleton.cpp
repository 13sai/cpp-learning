/**
 * @file singleton.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * 单例模式
 */
#include <iostream>
using namespace std;

class Singleton
{
    public:
        // = delete,用于定义删除函数，阻止拷贝
        Singleton( Singleton const& ) =delete;
        Singleton& operator = (Singleton const&) =delete;

        static Singleton* get()
        {
            if (!instance) {
                instance = new Singleton();
            }

            return instance;
        }

        static void restart()
        {
            if ( instance ) {
                delete instance;
            }
        }

        void tell()
        {
            cout << "this is singleton" << endl;
        }

    private:
        Singleton() {}
        static Singleton *instance;
};

Singleton* Singleton::instance = nullptr;


int main()
{
    Singleton::get()->tell();
    Singleton::restart();

    return 0;
}