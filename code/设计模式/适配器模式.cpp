#include "适配器模式.h"

void DuckAdapterTest::main()
{
    cout << "使用适配器之前----------------" << endl;

    MallardDuck* duck = new MallardDuck();
    duck->fly();
    duck->quack();

    WildTurkey* turkey = new WildTurkey();
    turkey->fly();
    turkey->gobble();

    cout << "对turkey使用适配器之后----------------" << endl;

    duck = new TurkeyAdapter(turkey);
    duck->fly();
    duck->quack();
}