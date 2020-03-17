#include "观察者模式.h"

void ObserverPattern::main()
{
    Subject* sub = new ConcreteSubject();
    ConcreteObserver1* obs1 = new ConcreteObserver1();
    ConcreteObserver2* obs2 = new ConcreteObserver2();
    sub->addObserver(obs1);
    sub->addObserver(obs2);
    sub->notifyObserver();
}