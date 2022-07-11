/**
 * @file template.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class AbstractClass
{
    public:
        virtual ~AbstractClass() {}

        void templateMethod()
        {
            primitiveOperationA();

            primitiveOperationB();
        }

        virtual void primitiveOperationA() = 0;
        virtual void primitiveOperationB() = 0;
};

class ConcreteClass : public AbstractClass
{
    public:
        ~ConcreteClass() {}

        void primitiveOperationA()
        {
            std::cout << "primitive operationA" << std::endl;
        }

        void primitiveOperationB()
        {
            std::cout << "primitive operationB" << std::endl;
        }
};

int main()
{
    AbstractClass *tm = new ConcreteClass;
    tm->templateMethod();

    delete tm;
    return 0;
}