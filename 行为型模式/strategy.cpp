/**
 * @file strategy.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class Strategy
{
    public:
        virtual ~Strategy(){}
        virtual void travelInterface() = 0;
};

class Train: public Strategy
{
    public:
        ~Train() {}

        void travelInterface()
        {
            cout << "travel by train" << endl;
        }
};

class Bus: public Strategy
{
    public:
        ~Bus() {}

        void travelInterface()
        {
            cout << "travel by bus" << endl;
        }
};

class Plane: public Strategy
{
    public:
        ~Plane() {}

        void travelInterface()
        {
            cout << "travel by plane" << endl;
        }
};

class Travel
{
    private:
        Strategy *s;

    public:
        /*
        构造函数后面加冒号表示初始化，与下面代码等价
        Travel(Strategy* const st) {
            s = st;
        }
        */
        Travel(Strategy* const st) : s(st) {}

        ~Travel()
        {
            delete s;
        }

        void goTravel()
        {
            s->travelInterface();
        }
};

int main()
{
    Travel travel1(new Bus());
    travel1.goTravel();

    Travel travel2(new Plane());
    travel2.goTravel();

    Travel travel3(new Train());
    travel3.goTravel();

    return 0;
}