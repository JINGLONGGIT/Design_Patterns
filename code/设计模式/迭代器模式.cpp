#include "迭代器模式.h"

int DinerMenu::numberOfItems = 0;
int DinerMenuIterator::position = 0;

void MenuTestDrive::main()
{
    PancakeHouseMenu* pancakeMenu = new PancakeHouseMenu();
    DinerMenu* dinerMenu = new DinerMenu();
    Waitress* waitress = new Waitress(pancakeMenu, dinerMenu);
    waitress->ReportMenu();
}