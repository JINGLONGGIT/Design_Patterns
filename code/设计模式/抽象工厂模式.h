#include "global.h"

class FoodProduct{
public:
    FoodProduct(){}
    ~FoodProduct(){}

public:
    virtual void delicious() = 0;
};

// 抽象产品：红烧鱼（描述产品的主要特性和功能）
class BraisingFish : public FoodProduct{
public:
    BraisingFish(){}
    ~BraisingFish(){}

public:
    virtual void delicious(){};
};

// 具体产品：川菜红烧鱼（实现抽象产品定义的接口，由具体工厂来创建）
class ChuanBraisingFish : public BraisingFish{
public:
    ChuanBraisingFish(){}
    ~ChuanBraisingFish(){}

public:
    void delicious(){
        cout << "川菜红烧鱼" << endl;
    }
};

// 具体产品：鲁菜红烧鱼
class LuBraisingFish : public BraisingFish{
public:
    LuBraisingFish(){}
    ~LuBraisingFish(){}

public:
    void delicious(){
        cout << "鲁菜红烧鱼" << endl;
    }
};

// 抽象产品：清蒸鱼
class SteameFish : public FoodProduct{
public:
    SteameFish(){}
    ~SteameFish(){}

public:
    virtual void delicious(){};
};

// 川菜清蒸鱼
class ChuanSteamFish : public SteameFish{
public:
    ChuanSteamFish(){}
    ~ChuanSteamFish(){}

public:
    void delicious(){
        cout << "川菜清蒸鱼" << endl;
    }
};

// 鲁菜清蒸鱼
class LuSteameFish : public SteameFish{
public:
    LuSteameFish(){}
    ~LuSteameFish(){}

public:
    void delicious(){
        cout << "鲁菜清蒸鱼" << endl;
    }
};

// 抽象工厂：提供创建抽象产品的接口，包含多个创建产品的方法，可以创建多个不同等级的产品
class CookFactory{
public:
    CookFactory(){}
    ~CookFactory(){}

public:
    virtual BraisingFish* CookBraisingFish() = 0;
    virtual SteameFish* CookSteameFish() = 0;
};

// 具体工厂：鲁菜工厂（实现抽象工厂中的抽象方法，完成具体产品的创建）
class LuCookFactory : public CookFactory{
public:
    LuCookFactory(){}
    ~LuCookFactory(){}

public:
    BraisingFish* CookBraisingFish(){
        cout << "红烧鱼" << endl;
        return new LuBraisingFish();
    }

    SteameFish* CookSteameFish(){
        cout << "清蒸鱼" << endl;
        return new LuSteameFish();
    }
};

// 具体工厂：川菜工厂
class ChuanCookFactory : public CookFactory{
public:
    ChuanCookFactory(){}
    ~ChuanCookFactory(){}

public:
    BraisingFish* CookBraisingFish(){
        cout << "红烧鱼" << endl;
        return new ChuanBraisingFish();
    }

    SteameFish* CookSteameFish(){
        cout << "清蒸鱼" << endl;
        return new ChuanSteamFish();
    }
};

// 客户代码
class AbstractFactoryPattern{
public:
    AbstractFactoryPattern(){}
    ~AbstractFactoryPattern(){}

public:
    void main();
};