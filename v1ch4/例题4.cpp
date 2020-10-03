#include<iostream>
using namespace std;
//base
class Base {
public:
	Base(int x1)
	{
		cout << "Constructing Base." << endl;
		x = x1;
	}
	void setx(int x1)
	{
		x = x1;
	}
	void showx()
	{
		cout << "x=" << x << endl;
	}
	~Base()
	{
		cout << "Destructing Base." << endl;
	}
protected:
	int x;
};
//base
class Base1 {
public:
	Base1(int y1)
	{
		cout << "Constructing Base1." << endl;
		y = y1;
	}
	void sety(int y1)
	{
		y = y1;
	}
	void showy()
	{
		cout << "y=" << y << endl;
	}
	~Base1()
	{
		cout << "Destructing Base1." << endl;
	}
protected:
	int y;
};
//派生类
class Derived :public Base, public Base1 {
public:
	Derived(int x1, int y1, float z1) :Base(x1), Base1(y1), b(x1), b1(y1)
	{
		cout << "Constructing Derived." << endl;
		z = z1;
	}
	void setxyz(int x1, int y1, float z1)//注意x=x1;y=y1;z=z1;b.setx(x1);写在函数体内
	{
		x = x1;
		y = y1;
		z = z1;
		b.setx(x1);
		b1.sety(y1);
	}
	void showxyz()
	{
		b.showx();
		b1.showy();
		showx();
		showy();
		cout << "z=" << z << endl;
	}
	~Derived()
	{
		cout << "Destructing Derived." << endl;
	}
private:
	float z;
	Base b;
	Base1 b1;
};

int main()
{
	Derived obj(5, 6, 7.8);
	obj.showxyz();
	return 0;
}