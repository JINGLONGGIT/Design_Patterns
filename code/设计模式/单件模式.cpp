#include "单件模式.h"

Singleton* Singleton::m_instance = NULL;

/*
// 线程非安全版本，且程序退出后无法运行析构函数
Singleton* Singleton::getInstance()
{
    if (m_instance == NULL)
        m_instance = new Singleton();
    else
        cout << "已经产生了一个美国总统" << endl;
    
    return m_instance;
}
*/

/*
// 线程安全版本，但锁的代价很高
// 程序异常会导致死锁
Singleton* Singleton::getInstance()
{
    Lock lock;
    if (m_instance == NULL) // 如果此处程序异常，则会导致死锁
        m_instance = new Singleton();
    return m_instance;
}

// 双检查锁: 内存读写reorder不安全(由于CPU乱序执行，可能导致访问到未经初始化的对象的引用)
Singleton* Singleton::getInstance()
{
    if (m_instance == NULL)
    {
        Lock lock;
        if (m_instance == NULL)
            m_instance = new Singleton();
    }
    return m_instance;
}
*/

// 使用局部静态对象重写单例模式
Singleton& Singleton::getInstance()
{
    static Singleton m_instance;
    return m_instance;
}

void SingletonTest::main()
{
//    Singleton* president1 = Singleton::getInstance();
//    Singleton* president2 = Singleton::getInstance();
    
    Singleton* president1 = &Singleton::getInstance();
    Singleton* president2 = &Singleton::getInstance();
    
    if (president1 == president2)
        cout << "他们是同一个人" << endl;
    else 
        cout << "他们不是同一个人" << endl;
}