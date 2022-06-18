/**
 * @file observer.cpp
 * @author 13sai (sai0556@qq.com)
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer
{
    public:
        virtual ~Observer() {}

        virtual int getState() = 0;
        virtual void update(Subject *s) = 0;
};


class ConcreteObserver: public Observer
{
    private:
        int observer_state;

    public:
        ~ConcreteObserver() {}
        ConcreteObserver(const int state):
            observer_state(state){}


        void update(Subject *s);

        int getState()
        {
            return observer_state;
        }
};

class Subject
{
    private:
        vector<Observer*> obs;

    public:
        virtual ~Subject() {}

        void attach(Observer *ob)
        {
            obs.push_back(ob);
        }

        void detach(const int index)
        {
            obs.erase(obs.begin() + index);
        }

        void notify()
        {
            for (unsigned int i = 0; i < obs.size(); i++) {
                obs.at(i)->update(this);
            }
        }

        virtual int getState() = 0;
        virtual void setState(const int s) = 0;
};

class ConcreteSubject: public Subject
{
    private:
        int subject_state;

    public:
        ~ConcreteSubject() {}

        int getState()
        {
            return subject_state;
        }

        void setState(const int s)
        {
            subject_state = s;
        }
};

void ConcreteObserver::update(Subject *s)
{
    observer_state = s->getState();
    cout << "observer_state updated" << endl;
};

int main() 
{
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    cout << "observer1 state: " << observer1.getState() << endl;
    cout << "observer2 state: " << observer2.getState() << endl;

    Subject *s = new ConcreteSubject();
    s->attach(&observer1);
    s->attach(&observer2);

    s->setState(13);
    s->notify();

    cout << "observer1 state: " << observer1.getState() << endl;
    cout << "observer2 state: " << observer2.getState() << endl;

    delete s;

    return 0;
}
