#include "global.h"

// 子系统角色1：实现系统的部分功能，客户可以通过外观访问它
class Subsystem1{
public:
    Subsystem1(){}
    ~Subsystem1(){}

public:
    void method1(){
        cout << "子系统1的方法method1被调用" << endl;
    }
};

// 子系统角色2
class Subsystem2{
public:
    Subsystem2(){}
    ~Subsystem2(){}

public:
    void method2(){
        cout << "子系统2的方法method2被调用" << endl;
    }
};

// 外观角色：为多个子系统提供一个共同的接口
class Facade{
public:
    Facade(){
        obj1 = new Subsystem1();
        obj2 = new Subsystem2();
    }
    ~Facade(){}

public:
    void method(){
        obj1->method1();
        obj2->method2();
    }

private:
    Subsystem1* obj1;
    Subsystem2* obj2;
};

// 客户角色：通过一个外观角色访问各个子系统的功能
class FacadePattern{
public:
    FacadePattern(){}
    ~FacadePattern(){}

public:
    void main();
};