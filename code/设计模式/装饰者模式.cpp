#include "装饰者模式.h"

void DecoratorPatternTest::main()
{
    Componet* p = new ConcreteComponet();
    p->operation();
    cout << "---------------------------------" << endl;
    Decorator* d1 = new ConcreteDecorator();
    d1->SetComponet(p);
    d1->operation();
}