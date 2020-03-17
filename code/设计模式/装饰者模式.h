#include "global.h"

// 抽象构件角色：定义抽象接口以规范准备接收附加责任的对象
class Componet{
public:
    Componet(){};
    ~Componet(){};

public:
    virtual void operation(){};
};

// 具体构件角色：实现抽象构件，通过装饰角色为其增加一些职责
class ConcreteComponet : public Componet{
public:
    ConcreteComponet(){
        cout << "构建具体构件角色" << endl;
    };
    ~ConcreteComponet(){};

public:
    void operation(){
        cout << "调用具体构件角色的方法operation()" << endl;
    }
};

// 抽象装饰角色：继承抽象构件，并包含具体构件的实例，可以通过子类拓展具体构件的功能
class Decorator : public Componet{
public:
    Decorator(){};
    ~Decorator(){};

protected:
    Componet* componet;

public:
    void operation(){
        componet->operation();
    }
    void SetComponet(Componet* componet){
        this->componet = componet;
    }
};

// 具体装饰角色：实现抽象装饰的具体方法，并给具体构件对象添加附加的责任
class ConcreteDecorator : public Decorator{
public:
    ConcreteDecorator(){};
    ~ConcreteDecorator(){};

public:
    void operation(){
        Decorator::operation();
        addFunction();
    }
    void addFunction(){
        cout << "为具体构件角色增加额外的功能addFunction()" << endl;
    }
};

// 测试代码
class DecoratorPatternTest{
public:
    DecoratorPatternTest(){};
    ~DecoratorPatternTest(){};

public:
    void main();
};