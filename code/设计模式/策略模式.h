#include "global.h"

// 抽象策略类：定义一个公共接口，各种不同的算法以不同的方式实现这个接口，环境角色使用这个接口调用不同的算法，一般使用接口或者抽象类实现
class FlyBehavior{
public:
    FlyBehavior(){};
    ~FlyBehavior(){};

public:
    virtual void fly(){};
};

// 具体策略类：实现抽象策略定义的接口，提供具体的算法实现
class FlyWithWings : public FlyBehavior{
public:
    FlyWithWings(){};
    ~FlyWithWings(){};

public:
    void fly(){
        cout << "I`m flying!!!" << endl;
    }
};

// 具体策略类
class FlyNoWings : public FlyBehavior{
public:
    FlyNoWings(){};
    ~FlyNoWings(){};

public:
    void fly(){
        cout << "I can`t fly" << endl;
    }
};

// 抽象策略类
class QuackBehavior{
public:
    QuackBehavior(){};
    ~QuackBehavior(){};

public:
    virtual void quack(){};
};

// 具体策略类
class Quack : public QuackBehavior{
public:
    Quack(){};
    ~Quack(){};

public:
    void quack(){
        cout << "Quack!!!" << endl;
    }
};

// 具体策略类
class MetuQuack : public QuackBehavior{
public:
    MetuQuack(){};
    ~MetuQuack(){};

public:
    void quack(){
        cout << "Silence" << endl;
    }
};

// 抽象环境类：持有策略类的引用
class Duck{
public:
    Duck(){};
    ~Duck(){};

public:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    void performFly(){
        flyBehavior->fly();
    }
    void performQuack(){
        quackBehavior->quack();
    }

    void swim(){
        cout << "All ducks float, even decoys!" << endl;
    }

    virtual void display(){};
};

// 具体环境类：供客户端调用相关的策略类
class MallarDuck : public Duck{
public:
    MallarDuck(){
        // 策略可替换
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    };
    ~MallarDuck(){};

public:
    void display(){
        cout << "I`m a real Mallard duck" << endl;
    }
};

// 具体环境类
class RedHeadDuck : public Duck{
public:
    RedHeadDuck(){
        // 策略可替换
        flyBehavior = new FlyNoWings();
        quackBehavior = new MetuQuack();
    };
    ~RedHeadDuck(){};

public:
    void display(){
        cout << "I`m a red head duck" << endl;
    }
};

// 客户代码
class MiniDuckSimulator{
public:
    MiniDuckSimulator(){};
    ~MiniDuckSimulator(){};

public:
    void main();
};