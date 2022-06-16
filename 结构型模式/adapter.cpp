/**
 * @file adapter.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class Target
{
    public:
        virtual ~Target() {}

        virtual void request() = 0;

};
class Adaptee
{
    public:
        ~Adaptee() {}

        void oneRequest()
        {
            cout << "one request" <<endl;
        }
};

/**
    继承：（父类的构造函数，析构函数 ，赋值函数不会被子类所继承）
    1. 公有继承(public):父类中的 protected 和 public 类型的成员变量和函数类型不变地转移到子类中。
    2. 私有继承(private):父类的 protected 和 public 类型的成员变量和函数在子类中都变为了 private 类型。
    3. 保护继承(protected):父类的protected和public类型的成员变量和函数在子类中都变为了 protected 类型。
 */
class Adapter: public Target, private Adaptee
{
    public:
        virtual void request()
        {
            oneRequest();
        }
};

int main()
{
    Target *t = new Adapter();
    t->request();
    delete t;

    return 0;
}