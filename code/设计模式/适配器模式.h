#include "global.h"

// 目标接口：当前系统业务所期待的接口
class MallardDuck{
public:
    MallardDuck(){};
    ~MallardDuck(){};

public:
    virtual void fly(){
        cout << "As a MallarDuck, I`m flying" << endl;
    }
    virtual void quack(){
        cout << "As a MallarDuck, Quack" << endl;
    }
};

// 适配者：被访问和被适配的现存组件库中的组件接口
class WildTurkey{
public:
    WildTurkey(){};
    ~WildTurkey(){};

public:
    void gobble(){
        cout << "As a WildTurkey, Gobble gobble" << endl;
    }
    void fly(){
        cout << "As a WildTurkey, I`m flying a short distance" << endl;
    }
};

// 适配器：它是一个转换器，通过继承或者引用适配者的对象，将适配者接口转换成目标接口，让客户按照目标接口的格式访问适配者
class TurkeyAdapter : public MallardDuck{
public:
    WildTurkey *turkeyAdaptee;
    TurkeyAdapter(WildTurkey *turkey){
        this->turkeyAdaptee = turkey;
    }
    ~TurkeyAdapter(){};

public:
    void quack(){
        turkeyAdaptee->gobble();
    }
    
    void fly(){
        turkeyAdaptee->fly();
    }
};

// 客户代码
class DuckAdapterTest{
public:
    DuckAdapterTest(){};
    ~DuckAdapterTest(){};

public:
    void main();
};