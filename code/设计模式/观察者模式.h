#include "global.h"

// 抽象观察者：包含一个抽象的更新自己的方法，当接收到主题的更改通知时被调用
class Observer{
public:
    Observer(){};
    ~Observer(){};

public:
    virtual void update(){};
};

// 具体观察者：实现抽象观察者定义的抽象方法，以便在得到目标的更改通知时更新自身的状态
class ConcreteObserver1 : public Observer{
public:
    ConcreteObserver1(){};
    ~ConcreteObserver1(){};

public:
    void update(){
        cout << "具体观察者1做出更新" << endl;
    }
};

// 具体观察者
class ConcreteObserver2 : public Observer{
public:
    ConcreteObserver2(){};
    ~ConcreteObserver2(){};

public:
    void update(){
        cout << "具体观察者2做出更新" << endl;
    }
};

// 抽象主题（也叫做抽象目标）：提供增加和删除观察者对象的方法，以及通知观察者对象的抽象方法
class Subject{
public:
    Subject(){};
    ~Subject(){};

protected:
    list<Observer*> obsList;

public:
    void addObserver(Observer* observer){
        obsList.push_back(observer);
    }
    void removeObserver(Observer* observer){
        obsList.remove(observer);
    }
    virtual void notifyObserver() = 0;
};

// 具体主题类：实现抽象主题中的通知方法。当抽象主题中的状态发生变化时，通知所有注册过的观察者对象
class ConcreteSubject : public Subject{
public:
    ConcreteSubject(){};
    ~ConcreteSubject(){};

public:
    void notifyObserver(){
        cout << "具体目标发生变化..." << endl;

        for (list<Observer*>::iterator it = obsList.begin(); it != obsList.end(); it++)
        {
            (*it)->update();
        }
    };
};

// 测试代码
class ObserverPattern{
public:
    ObserverPattern(){};
    ~ObserverPattern(){};

public:
    void main();
};