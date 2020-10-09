#include<iostream>
using namespace std;

class base {
public:
	base() { a = 5; cout << "调用base的构造函数" << a << endl; }
	void show() { cout << "a=" << a << endl; }
protected:
	int a;
};

class base1 :virtual protected base {
public:
	base1() { a = a + 10;; cout << "调用base1的构造函数" << a << endl; }

protected:
	int aa;
};

class base2 :virtual protected base {
public:
	base2() { a = a + 20; cout << "调用base2的构造函数" << a << endl; }

protected:
	int bb;
};

class derived :private base1, public base2 {
public:
	derived()
	{
		cout << "派生类derived的构造函数" << endl;
		cout << base1::a << endl;
		cout << base2::a << endl;
		//		cout<<derived::a<<endl;
	}
};

int main()
{
	derived ob;
	return 0;
}