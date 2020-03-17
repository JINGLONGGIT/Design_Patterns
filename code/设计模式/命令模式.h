#include "global.h"

// 接收者：执行命令功能的相关操作，是具体命令对象业务的真正实现者
class Light{
public:
    Light(){};
    ~Light(){};

public:
    void on(){
        cout << "Light on" << endl;
    };
    void off(){
        cout << "Light off" << endl;
    };
};

// 抽象命令类：声明执行命令的接口，拥有执行命令的抽象方法execute()
class Command{
public:
    Command(){};
    ~Command(){};

public:
    virtual void execute(){};
};

// 具体命令：拥有接收者对象，并通过调用接收者的功能来完成命令要执行的操作
class LightOnCommand : public Command{
public:
    LightOnCommand(Light* light){
        this->light = light;
    };
    ~LightOnCommand(){};

public:
    void execute(){
        light->on();
    }

private:
    Light* light;
};

// 具体命令：拥有接受者的对象，并通过调用接受者的功能来完成命令要执行的操作
class LightOFFCommand : public Command{
public:
    LightOFFCommand(Light* light){
        this->light = light;
    }
    ~LightOFFCommand(){};

public:
    void execute(){
        light->off();
    }

private:
    Light* light;
};

// 调用者：请求的发送者，拥有很多的命令对象，通过访问命令对象来执行相关请求，并不直接访问接收者
class SimpleRemoteControl{
public:
    SimpleRemoteControl(){};
    ~SimpleRemoteControl(){};

public:
    void setCommand(Command* command){
        slot = command;
    }
    void buttonWasPressed(){
        slot->execute();
    }

private:
    Command* slot;
};

// 客户代码
class RemoteControlTest{
public:
    RemoteControlTest(){};
    ~RemoteControlTest(){};

public:
    void main();
};