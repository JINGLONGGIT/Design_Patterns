#include "模板方法模式.h"

void BeverageTestDrive::main()
{
    //Tea* myTea = new Tea();
    //myTea->prepareRecipe();

    //Coffee* myCoffee = new Coffee();
    //myCoffee->prepareRecipe();

    CaffeineBeverage* myTea = new Tea();
    myTea->prepareRecipe();
}