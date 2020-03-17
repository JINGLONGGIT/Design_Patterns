#include "工厂方法模式.h"

void PizzaTestDrive::main()
{
    PizzaStore* nyStore = new NYPizzaStore();
    Pizza* pizza = nyStore->orderPizza("cheese");
    cout << "Ethan ordered a " << pizza->getName() << endl;

    PizzaStore* chicagoStore = new ChicagoPizzaStore();
    pizza = chicagoStore->orderPizza("cheese");
    cout << "Joel ordered a " << pizza->getName() << endl;
}