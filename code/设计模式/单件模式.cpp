#include "����ģʽ.h"

Singleton* Singleton::m_instance = NULL;

// �̷߳ǰ�ȫ�汾���ҳ����˳����޷�������������
Singleton* Singleton::getInstance()
{
    if (m_instance == NULL)
        m_instance = new Singleton();
    else
        cout << "�Ѿ�������һ��������ͳ" << endl;
    
    return m_instance;
}

/*
// �̰߳�ȫ�汾�������Ĵ��ۺܸ�
Singleton* Singleton::getInstance()
{
    Lock lock;
    if (m_instance == NULL)
        m_instance = new Singleton();
    return m_instance;
}

// ˫�����: �ڴ��дreorder����ȫ(����CPU����ִ�У����ܵ��·��ʵ�δ����ʼ���Ķ��������)
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

void SingletonTest::main()
{
    Singleton* president1 = Singleton::getInstance();
    Singleton* president2 = Singleton::getInstance();

    if (president1 == president2)
        cout << "������ͬһ����" << endl;
    else 
        cout << "���ǲ���ͬһ����" << endl;
}