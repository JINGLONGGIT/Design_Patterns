#include "策略模式.h"

void MiniDuckSimulator::main()
{
    Duck* mallard;
    mallard = new MallarDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    mallard = new RedHeadDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();
}