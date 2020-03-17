#include "抽象工厂模式.h"

void AbstractFactoryPattern::main()
{
    // 鲁菜红烧鱼
    CookFactory* cookfactory = new LuCookFactory();
    BraisingFish* braisingFish = cookfactory->CookBraisingFish();
    braisingFish->delicious();

    // 川菜清蒸鱼
    cookfactory = new ChuanCookFactory();
    SteameFish* steamFish = cookfactory->CookSteameFish();
    steamFish->delicious();
}