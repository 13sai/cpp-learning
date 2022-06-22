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
// #include <> 直接从编译器自带的函数库中寻找文件
// #include "" 是先从自定义的文件中找 ，如果找不到在从函数库中寻找文件
#include <iostream>
using namespace std;

class ProductA
{
    public:
        // 函数前 ~ 表示析构函数
        virtual ~ProductA() {}

        // virtual 虚函数，多态
        virtual const char* getName() = 0;
};

class ProductB
{
    public:
        virtual ~ProductB() {}

        virtual const char* getName() = 0;
};

// : 类的继承
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
    // new FactoryX 调用构建函数
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

    // delete 运算符:用以释放动态分配的内存空间
    // 如果是用 new 分配的内存空间，比如动态分配了一个数组，那么释放时，应使用 delete[] p;
    // 另外还要注意，释放一个指针，并不会使该指针的值变为 NULL
    delete ax;
    delete ay;
    delete bx;
    delete by;

    delete factoryX; delete factoryY;

    return 0;
}