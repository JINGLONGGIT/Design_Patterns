#include "global.h"

class Singleton{
private:
    static Singleton* m_instance;
    Singleton(){
        cout << "���й��캯��" << endl;
        cout << "����һ��������ͳ" << endl;
    }

    ~Singleton(){
        cout << "������������" << endl;
    }

public:
    static Singleton* getInstance();
};

class SingletonTest{
public:
    SingletonTest(){};
    ~SingletonTest(){};
public:
    void main();
};

