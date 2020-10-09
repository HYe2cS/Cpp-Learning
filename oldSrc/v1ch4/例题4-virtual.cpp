#include<iostream>
using namespace std;
//base
class Base {
public:
	Base(int a1)
	{
		cout << "Constructing Base." << endl;
		a = a1;
	}
	void seta(int a1)
	{
		a = a1;
	}
	void showa()
	{
		cout << "a=" << a << endl;
	}
	~Base()
	{
		cout << "Destructing Base." << endl;
	}
protected:
	int a;
};
//base1
class Base1 :virtual public Base {
public:
	Base1(int a1, int b1) :Base(a1)//必须缀上对类Base构造函数的调用
	{
		cout << "Constructing Base1." << endl;
		b = b1;
	}
	void setb(int b1)
	{
		b = b1;
	}
	void showb()
	{
		cout << "b=" << b << endl;
	}
	~Base1()
	{
		cout << "Destructing Base1." << endl;
	}
protected:
	int b;
};
//base2
class Base2 :virtual public Base {
public:
	Base2(int a1, int c1) :Base(a1)//必须缀上对类Base构造函数的调用
	{
		cout << "Constructing Base1." << endl;
		c = c1;
	}
	void setc(int c1)
	{
		c = c1;
	}
	void showc()
	{
		cout << "c=" << c << endl;
	}
	~Base2()
	{
		cout << "Destructing Base2." << endl;
	}
protected:
	int c;
};
//派生类
class Derived :public Base1, public Base2 {
public:
	Derived(int a1, int b1, int c1, int d1) :Base(a1), Base1(a1, b1), Base2(a1, c1)//必须缀上对类Base构造函数的调用
	{
		cout << "Constructing Derived." << endl;
		d = d1;
	}
	void setd(int d1)
	{
		d = d1;
	}
	void showabcd()
	{
		showa();
		showb();
		showc();
		cout << "d=" << d << endl;
	}
	~Derived()
	{
		cout << "Destructing Derived." << endl;
	}
private:
	int d;
};
int main()
{
	Derived obj(2, 4, 6, 8);
	obj.showabcd();
	return 0;
}