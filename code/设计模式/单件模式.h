#include "global.h"

class Singleton{
private:
    static Singleton* m_instance;
    Singleton(){
        cout << "运行构造函数" << endl;
        cout << "产生一个美国总统" << endl;
    }

    ~Singleton(){
        cout << "运行析构函数" << endl;
    }

public:
//    static Singleton* getInstance();
    static Singleton& getInstance();        // 静态公有函数：用于获取静态私有实例static Singleton* m_instance
};

class SingletonTest{
public:
    SingletonTest(){};
    ~SingletonTest(){};
public:
    void main();
};

