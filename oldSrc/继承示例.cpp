#include<iostream>
using namespace std;
//基类
class A {
public:
    A(int x1, float y1);
    void showa();

protected:
    int x;
    float y;
};

A::A(int x1, float y1)
{
    x = x1;
    y = y1;
}

void A::showa()
{
    cout << "x=" << x << "," << "y=" << y << endl;
}

//派生类
class B :private A {
public:
    B(int x1, float y1, int z1, int x2, float y2) :A(x1, y1), a(x2, y2)
    {
        z = z1;
    }
    void showb()
    {
        showa();
        cout << "z=" << z << endl;
        a.showa();
    }
private:
    int z;
    A a;
};

int main()
{
    B b(4, 2.5, 3, 2, 3.2);
    b.showb();
    return 0;
}