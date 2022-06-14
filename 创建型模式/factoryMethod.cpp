/**
 * @file factoryMethod.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 工厂方法
 */
#include <iostream>
#include <string>
using namespace std;

class Product 
{
    public:
        virtual ~Product() {}

        // 定义纯虚函数，同时表明该类不可实例化，同时继承该类的派生类必须实现该函数。
        virtual string getName() = 0;
};

class ConcreteProductA: public Product
{
    public:
        ~ConcreteProductA() {}

        string getName()
        {
            return "ProductA";
        }
};

class ConcreteProductB: public Product
{
    public:
        ~ConcreteProductB() {}

        string getName()
        {
            return "ProductB";
        }
};

class Creator
{
    public:
        virtual ~Creator() {}

        virtual Product* createProductA() = 0;
        virtual Product* createProductB() = 0;

        virtual void removeProduct(Product *product) = 0;
};

class ConcreteCreator: public Creator
{
    public:
        ~ConcreteCreator() {}

        Product* createProductA() 
        {
            return new ConcreteProductA();
        }

        Product* createProductB()
        {
            return new ConcreteProductB();
        }

        void removeProduct(Product *product)
        {
            delete product;
        }
};

int main() {
    Creator *creator = new ConcreteCreator();

    Product *p1 = creator->createProductA();
    cout << "p1 -- " << p1->getName() << endl;

    Product *p2 = creator->createProductB();
    cout << "p2 -- " << p2->getName() << endl;

    creator->removeProduct(p1);
    creator->removeProduct(p2);

    delete creator;
    return 0;
}
