/**
 * @file AbstractFactory.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 抽象工厂
 */
#include <iostream>
using namespace std;

class ProductA
{
    public:
        // 函数前 ~ 表示析构函数
        // virtual 虚函数，多态
        virtual ~ProductA() {}

        virtual const char* getName() = 0;
};

class ProductB
{
    public:
        virtual ~ProductB() {}

        virtual const char* getName() = 0;
};

class ConcreteProductAX: public ProductA
{
    public: ~ConcreteProductAX() {}

    const char* getName()
    {
        return "A-X";
    }
};

class ConcreteProductAY: public ProductA
{
    public: ~ConcreteProductAY() {}

    const char* getName()
    {
        return "A-Y";
    }
};

class ConcreteProductBX: public ProductB
{
    public: ~ConcreteProductBX() {}

    const char* getName()
    {
        return "B-X";
    }
};

class ConcreteProductBY: public ProductB
{
    public: ~ConcreteProductBY() {}

    const char* getName()
    {
        return "B-Y";
    }
};

class AbstractFactory
{
    public:
        virtual ~AbstractFactory() {}

        virtual ProductA *createProductA() = 0;
        virtual ProductB *createProductB() = 0;
};

class FactoryX: public AbstractFactory
{
    public:
        ~FactoryX(){}

        ProductA *createProductA() 
        {
            return new ConcreteProductAX();
        }

        ProductB *createProductB() 
        {
            return new ConcreteProductBX();
        }
};


class FactoryY: public AbstractFactory
{
    public:
        ~FactoryY(){}

        ProductA *createProductA() 
        {
            return new ConcreteProductAY();
        }

        ProductB *createProductB() 
        {
            return new ConcreteProductBY();
        }
};


int main()
{
    FactoryX *factoryX = new FactoryX();
    FactoryY *factoryY = new FactoryY();

    ProductA *ax = factoryX->createProductA();
    cout << "Product1: " << ax->getName() << endl;

    ProductA *ay = factoryY->createProductA();
    cout << "Product2: " << ay->getName() << endl;

    ProductB *bx = factoryX->createProductB();
    cout << "Product3: " << bx->getName() << endl;

    ProductB *by = factoryY->createProductB();
    cout << "Product4: " << by->getName() << endl;

    delete ax;
    delete ay;
    delete bx;
    delete by;

    delete factoryX; delete factoryY;

    return 0;
}