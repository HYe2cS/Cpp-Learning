#include<iostream>
using namespace std;
class Base {//虚基类
public:
    Base()
    {
        a = 5;//初始值a=5
        cout << "Base a=" << a << endl;
    }
protected:
    int a;
};
class  Base1 : virtual public Base {//非虚基类
public:
    int b1;
    Base1()
    {
        a = a + 10; //a=5+10=15
        cout << "Base1 a=" << a << endl;
    }
};
class Base2 : virtual public Base {//非虚基类
public:
    int b2;
    Base2()
    {
        a = a + 20; //a=15+20=35
        cout << "Base2 a=" << a << endl;
    }
};

class Derived :public Base1, public Base2 {
    //调用且只调用一遍base构造函数，
    //由最远派生类(Derived)的构造函数通过调用虚基类的构造函数进行初始化的
    //base--base1--derived
    //之后其他基类对base构造函数的调用被忽略
    //base1构造函数--base2构造函数--derived构造函数
public:
    int d;
    Derived()
    {
        cout << "Derived a=" << a << endl;//a=35
    }
};
int main()
{
    Derived  obj; return  0;
}