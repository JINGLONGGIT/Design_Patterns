#include "外观模式.h"

void FacadePattern::main()
{
    Facade* facade = new Facade();
    facade->method();
}