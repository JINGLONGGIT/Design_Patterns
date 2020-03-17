#include "global.h"

#define MAX_ITEMS 6

class MenuItem{
public:
    MenuItem(string name, string decription, bool vegetarian, double price){
        this->name = name;
        this->decription = decription;
        this->vegetarian = vegetarian;
        this->price = price;
    }
    ~MenuItem(){}

public:
    string name;
    string decription;
    bool vegetarian;
    double price;

public:
    string getName(){
        return name;
    }
    string getDecription(){
        return decription;
    }
    double getPrice(){
        return price;
    }
    bool isVegetarian(){
        return vegetarian;
    }
};

// 抽象迭代器：定义访问和遍历聚合对象的接口，通常包含hasNext()、next()、first()等方法
class Iterator{
public:
    Iterator(){}
    ~Iterator(){}

public:
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

// 具体迭代器：实现抽象迭代器接口中所定义的方法，完成对聚合对象的遍历，记录遍历的当前位置
class DinerMenuIterator : public Iterator{
public:
    DinerMenuIterator(MenuItem** items){
        this->items = items;
    }
    ~DinerMenuIterator(){};

public:
    MenuItem** items;
    static int position;

public:
    bool hasNext(){
        if (position >= MAX_ITEMS)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    
    MenuItem* next(){
        MenuItem* menuItem = items[position];
        position += 1;
        return menuItem;
    }
};

// 具体迭代器
class PancakeHouseMenuIterator : public Iterator{
public:
    PancakeHouseMenuIterator(vector<MenuItem*> items){
        this->items = items;
    }
    ~PancakeHouseMenuIterator(){}

public:
    vector<MenuItem*> items;

public:
    bool hasNext()
    {
        if (items.size() == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    MenuItem* next()
    {
        MenuItem* menuItem = items[items.size() - 1];
        items.pop_back();
        return menuItem;
    }
};

// 具体聚合角色: 定义存储、添加、删除聚合对象以及创建迭代器对象的接口
class DinerMenu{
public:
    DinerMenu(){
        addItem("Vegetarian BLT", "(Fakin) Bacon With lettuce & tomato on whole wheat", true, 2.99);
        addItem("BLT", "(Bacon) With lettuce & tomato on whole wheat", false, 2.99);
        addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    }
    ~DinerMenu(){}

public:
    static int numberOfItems;
    MenuItem* menuItems[MAX_ITEMS];      // 对象数组

public:
    void addItem(string name, string decription, bool vegetarian, double price)
    {
        MenuItem* menuItem = new MenuItem(name, decription, vegetarian, price);
        if (numberOfItems >= MAX_ITEMS)
        {
            cout << "Sorry, Menu is full" << endl;
        }
        else 
        {
            menuItems[numberOfItems] = menuItem;
            numberOfItems++;
        }
    }

    Iterator* createDinerIterator(){
        return new DinerMenuIterator(menuItems);
    }
};

// 具体聚合角色
class PancakeHouseMenu{
public:
    PancakeHouseMenu(){
        addItem("K&B`s Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99);
        addItem("Regular Pancake Breakfast", "Pancakes with fried eggs, and sausage", false, 2.99);
        addItem("Blueberry Pancakes", "Pancakes made with fresh Blueberries", true, 3.49);
    }
    ~PancakeHouseMenu(){};

public:
    vector<MenuItem*> VecMenuItems;

public:
    void addItem(string name, string description, bool vegetation, double price){
        MenuItem* menuItem = new MenuItem(name, description, vegetation, price);
        VecMenuItems.push_back(menuItem);
    }
    
    Iterator* createPancakeIterator(){
        return new PancakeHouseMenuIterator(VecMenuItems);
    }
};

// 客户访问类
class Waitress{
public:
    Waitress(PancakeHouseMenu* pancakeMenu, DinerMenu* dinerMenu){
        this->pancakeMenu = pancakeMenu;
        this->dinerMenu = dinerMenu;
    }
    ~Waitress(){}

public:
    PancakeHouseMenu* pancakeMenu;
    DinerMenu* dinerMenu;

public:
    void ReportMenu(){
        Iterator* pancakeIterator = pancakeMenu->createPancakeIterator();
        Iterator* dinerIterator = dinerMenu->createDinerIterator();
        printMenu(pancakeIterator);
        cout << "---------------------" << endl;
//        printMenu(dinerIterator);
    }

private:
    void printMenu(Iterator* iterator)
    {
        while (iterator->hasNext())
        {
            MenuItem* menuItem = iterator->next();
            cout << menuItem->getName() << ",";
            cout << menuItem->getPrice() << "--";
            cout << menuItem->getDecription() << endl;
        }
    }
};

// 测试代码
class MenuTestDrive{
public:
    MenuTestDrive(){}
    ~MenuTestDrive(){}

public:
    void main();
};