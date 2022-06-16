/**
 * @file decorator.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 装饰器
 */
#include <iostream>
using namespace std;

class Interface
{
    public:
        virtual ~Interface() {}

        virtual void doWhat() = 0;
};

class Concrete: public Interface
{
    public:
        ~Concrete() {}

        void doWhat()
        {
            cout << "Concrete doWhat" << endl;
        }
};

class Decorator: public Concrete
{
    private:
        Concrete *con;

    public:
        ~Decorator() {}

        Decorator(Concrete *c) : con(c) {}

        virtual void doWhat()
        {
            con->doWhat();
        }
};

class ConcreteDecoratorA: public Decorator
{
    public:
        ConcreteDecoratorA(Concrete *c): Decorator(c) {}

        void doWhat()
        {
            Decorator::doWhat();
            cout << "ConcreteDecoratorA dowhat" << endl;
        }
};

class ConcreteDecoratorB: public Decorator
{
    public:
        ConcreteDecoratorB(Concrete *c): Decorator(c) {}

        void doWhat()
        {
            Decorator::doWhat();
            cout << "ConcreteDecoratorB dowhat" << endl;
        }
};

int main()
{
    Concrete *c = new Concrete();
    ConcreteDecoratorA *a = new ConcreteDecoratorA(c);
    ConcreteDecoratorB *b = new ConcreteDecoratorB(a);

    Interface *in = b;
    in->doWhat();
    delete c;
    delete a;
    delete b;
    delete in;

    return 0;
}