#include "状态模式.h"

void StatePatternTest::main()
{
    State* pStateA = new ConcreteStateA();
    State* pStateB = new ConcreteStateB();
    Context* context = new Context();
    context->handle();
    
    context->setState(pStateB);
    context->handle();
}