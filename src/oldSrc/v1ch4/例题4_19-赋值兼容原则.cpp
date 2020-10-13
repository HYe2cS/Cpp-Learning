# include <iostream>
using namespace std;
class Base {
public:    int i;
      Base(int x)
      {
          i = x;
      }
      void show()
      {
          cout << "Base  " << i << endl;
      }
};
class Derived : public Base {
public:
    Derived(int x) :Base(x)
    { }
};
void fun(Base& bb)
{
    cout << bb.i << endl;
}
int main() {
    Base b1(100); b1.show();
    //派生类对象可以向基类对象赋值
    Derived d1(11); b1 = d1;
    b1.show();

    //派生类对象可以初始化基类的引用
    Derived d2(22); Base& b2 = d2;
    b2.show();

    //派生类对象的地址可以赋值给指向基类对象的指针，反过来不行
    Derived d3(33);
    Base* b3 = &d3;
    b3->show();
    //下面两句会报错
    //Derived *d3=&b3;
    //d3->show();

    //如果函数的形参是基类对象或基类对象的引用，
    //在调用函数时可以用派生类对象作为实参
    //d4是派生类对象，函数形参是基类
    Derived d4(44); fun(d4);

    return 0;
}