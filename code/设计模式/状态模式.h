#include "global.h"

class Context;

// 抽象状态：定义一个接口，用以封装环境对象中特定状态所对应的行为
class State{
public:
    State(){}
    ~State(){}

public:
    virtual void Handle(Context* context) = 0;
};

// 具体状态：实现抽象状态所定义的行为
class ConcreteStateA : public State{
public:
    ConcreteStateA(){}
    ~ConcreteStateA(){}

public:
    void Handle(Context* context){
        cout << "当前状态是A" << endl;
    }
};

class ConcreteStateB :  public State{
public:
    ConcreteStateB(){}
    ~ConcreteStateB(){}

public:
    void Handle(Context* context){
        cout << "当前状态是B" << endl;
    }
};

// 环境类：定义了客户感兴趣的接口，维护一个当前状态，并将与状态相关的操作委托给当前状态对象处理
class Context{
public:
    Context(){
        this->state = new ConcreteStateA();
    }
    ~Context(){}

public:
    void setState(State* state){
        this->state = state;
    }

    State* getState(){
        return state;
    }

    void handle(){
        state->Handle(this);
    }

private:
    State* state;
};

// 客户代码
class StatePatternTest{
public:
    StatePatternTest(){}
    ~StatePatternTest(){}

public:
    void main();
};
