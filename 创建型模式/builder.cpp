/**
 * @file builder.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 建造者模式
 */

#include <iostream>
#include <string>
using namespace std;

class Product
{
    private:
        string partA;
        string partB;
        string partC;

    public:
        void makeA( const string &part)
        {
            partA = part;
        }

        void makeB( const string &part)
        {
            partB = part;
        }

        void makeC( const string &part)
        {
            partC = part;
        }

        string get()
        {
            return (partA + " | " + partB + " | " + partC);
        }
};

class Builder
{
    protected:
        Product product;

    public:
        virtual ~Builder() {}

        Product get()
        {
            return product;
        }

        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
        virtual void buildPartC() = 0;
};


class ConcreteBuildX: public Builder
{
    public:
        void buildPartA()
        {
            product.makeA("A-X");
        }

        void buildPartB()
        {
            product.makeB("B-X");
        }

        void buildPartC()
        {
            product.makeC("C-X");
        }
};

class ConcreteBuildY: public Builder
{
    public:
        void buildPartA()
        {
            product.makeA("A-Y");
        }

        void buildPartB()
        {
            product.makeB("B-Y");
        }

        void buildPartC()
        {
            product.makeC("C-Y");
        }
};


class Director
{
    private:
        Builder *builder;

    public:
        Director(): builder() {}

        ~Director()
        {
            if ( builder ) {
                delete builder;
            }
        }

        void set(Builder *b)
        {
            if ( builder ) {
                delete builder;
            }

            builder = b;
        }

        Product get() 
        {
            return builder->get();
        }

        void construct()
        {
            builder->buildPartA();
            builder->buildPartB();
            builder->buildPartC();
        }
};


int main()
{
    Director director;
    director.set( new ConcreteBuildX );
    director.construct();

    Product product1 = director.get();
    cout << "product1: " << product1.get() << endl;

    director.set( new ConcreteBuildY );
    director.construct();

    Product product2 = director.get();
    cout << "product2: " << product2.get() << endl;
}