#include "global.h"

/**********************************************************************/
/**********************透明方式组合模式**********************************/
/**********************************************************************/

// 在透明方式组合模式中抽象构件还声明访问和管理子类的接口；
// 在安全方式组合模式中，不声明访问和管理子类的接口，管理工作由树枝构件完成

// 抽象构件：声明树叶构件和树枝构件的公共接口，并实现它们的默认行
class Component{
public:
    Component(){}
    ~Component(){}

public:
    virtual void add(Component* c) = 0;
    virtual void remove(Component* c) = 0;
    virtual Component* getChild(unsigned int i) = 0;
    virtual void operation() = 0;
};

// 树叶构件：是组合中的叶节点对象，它没有子节点，用于实现抽象构件中声明的公共接口
class Leaf : public Component{
public:
    Leaf(string name){
        this->name = name;
    }
    ~Leaf(){}

private:
    string name;

public:
    void add(Component* c){}
    void remove(Component* c){}
    Component* getChild(unsigned int i){
        return NULL;
    }
    void operation(){
        cout << "树叶" << name << "被访问" << endl;
    }
};

// 树枝构件：组合中的分节点对象，它有子节点。实现了抽象构件中声明的接口，它的主要作用是存储和管理子部件，通常包含add(), remove(), getChild()
class Composite : public Component{
public:
    Composite(){}
    ~Composite(){}

private:
    vector<Component*> children;

public:
    void add(Component* c){
        children.push_back(c);
    }
    
    void remove(Component* c){
        vector<Component*>::iterator it = find(children.begin(), children.end(), c);
        if (it != children.end())
        {
            children.erase(it);
        }
    }

    Component* getChild(unsigned int i){
        if ((i > children.size()) || (i < 0))
            return NULL;
        return children[i];
    }

    void operation(){
        for (vector<Component*>::iterator it = children.begin(); it != children.end(); it++)
        {
            (*it)->operation();
        }
    }
};

// 客户代码
class CompositePatternTest{
public:
    CompositePatternTest(){}
    ~CompositePatternTest(){}

public:
    void main();
};