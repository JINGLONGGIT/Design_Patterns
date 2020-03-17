#include "global.h"

/******************************************************************************************* 
 * 抽象类：给出一个算法的具体轮廓和骨架，它由一个模板方法和若干个基本方法构成。这些方法定义如下：
 * ①模板方法：定义了算法的骨架，按某种顺序调用其包含的基本方法
 * ②基本方法：整个算法中的步骤，包含以下几种类型
 *  1）抽象方法：在抽象类中声明，由具体子类实现
 *  2）具体方法：在抽象类中已经实现，在具体子类中可以继承或者重写
 *  3）钩子方法：在抽象类中已经实现，包括用于判断的逻辑方法和需要子类重写的空方法两种
 *******************************************************************************************/ 
class CaffeineBeverage{
public:
    CaffeineBeverage(){};
    ~CaffeineBeverage(){};

public:
    // 模板方法
    void prepareRecipe(){
        boilWater();
        brew();
        addCondiments();
        pourInCup();
    }
    
    // 具体方法
    void boilWater(){
        cout << "Boiling water" << endl;
    }
    void pourInCup(){
        cout << "Pouring into cup" << endl;
    }
    
    // 抽象方法
    virtual void brew(){}
    virtual void addCondiments(){}
};

// 具体子类：实现抽象类中所定义的抽象方法和钩子方法
class Coffee : public CaffeineBeverage{
public:
    Coffee(){};
    ~Coffee(){};

public:
    void brew(){
        cout << "Dripping Coffee through filter" << endl;
    }
    
    void addCondiments(){
        cout << "Adding Suger and Milk" << endl;
    }
};

class Tea : public CaffeineBeverage{
public:
    Tea(){};
    ~Tea(){};

public:
    void brew(){
        cout << "Steeping the tea" << endl;
    }

    void addCondiments(){
        cout << "Add Lemon" << endl;
    }
};

// 客户代码
class BeverageTestDrive{
public:
    BeverageTestDrive(){};
    ~BeverageTestDrive(){};

public:
    void main();
};