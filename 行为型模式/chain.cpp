/**
 * @file chain.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class Handler
{
    private:
        Handler *request;

    public:
        virtual ~Handler() {}

        virtual void setHandle(Handler *s)
        {
            request = s;
        }

        virtual void handlerReq()
        {
            if (request!=0) {
                request->handlerReq();
            }
        }
};

class AddHandlerA: public Handler
{
    public:
        ~AddHandlerA() {}

        bool canHandle()
        {
            return false;
        }

        virtual void handlerReq()
        {
            if (canHandle()) {
                cout << "request canHandled in AddHandlerA" <<endl;
            } else {
                cout << "request did not canHandle in AddHandlerA" <<endl;
                Handler::handlerReq();
            }
        }
};

class AddHandlerB: public Handler
{
    public:
        ~AddHandlerB() {}

        bool canHandle()
        {
            return true;
        }

        virtual void handlerReq()
        {
            if (canHandle()) {
                cout << "request canHandled in AddHandlerB" <<endl;
            } else {
                cout << "request did not canHandle in AddHandlerB" <<endl;
                Handler::handlerReq();
            }
        }
};

int main()
{
    AddHandlerA handlerA;
    AddHandlerB handlerB;

    handlerA.setHandle(&handlerB);
    handlerA.handlerReq();

    return 0;
}