#include "global.h"

// 抽象产品：定义了产品的规范，描述了产品的主要特性和功能
class Pizza{
public:
    Pizza(){};
    ~Pizza(){};

public:
    string name;
    string dough;
    string sauce;
    void prepare(){
        cout << "Prepare " + name;
    }
    void bake(){
        cout << "Bake for 25 minutes at 350" << endl;
    }
    void cut(){
        cout << "Cutting the pizza into diagonal slices" << endl;
    }
    void box(){
        cout << "Place pizza in official PizzaStore box" << endl;
    }
    string getName(){
        return name;
    }
};

// 具体产品: 实现了抽象产品角色所定义的接口，由具体工厂来创建。同具体工厂一一对应
class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        name = "MY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
    }
    ~NYStyleCheesePizza(){};

public:
};

// 具体产品
class ChicagoStylePizza : public Pizza{
public:
    ChicagoStylePizza(){
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
    }
    ~ChicagoStylePizza(){};

public:
};

// 抽象工厂：提供了创建产品的接口，调用者通过它访问具体工厂的工厂方法来创建产品
class PizzaStore{
public:
    PizzaStore(){};
    ~PizzaStore(){};

public:
    Pizza* orderPizza(string type){
        Pizza* pizza;
        pizza = creatPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual Pizza* creatPizza(string type) = 0;
};

// 具体工厂：实现抽象工厂的方法，完成产品的创建
class NYPizzaStore : public PizzaStore{
public:
    NYPizzaStore(){};
    ~NYPizzaStore(){};

public:
    Pizza* creatPizza(string item){
        if (item == "cheese")
            return new NYStyleCheesePizza();
        else
            return NULL;
    }
};

// 具体工厂
class ChicagoPizzaStore : public PizzaStore{
public:
    ChicagoPizzaStore(){};
    ~ChicagoPizzaStore(){};

public:
    Pizza* creatPizza(string item){
        if (item == "cheese")
            return new ChicagoStylePizza();
        else 
            return NULL;
    }
};

// 客户代码
class PizzaTestDrive{
public:
    PizzaTestDrive(){};
    ~PizzaTestDrive(){};

public:
    void main();
};