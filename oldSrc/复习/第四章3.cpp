#include<iostream>
using namespace std;

class base {
public:
	base() { a = 5; cout << "����base�Ĺ��캯��" << a << endl; }
	void show() { cout << "a=" << a << endl; }
protected:
	int a;
};

class base1 :virtual protected base {
public:
	base1() { a = a + 10;; cout << "����base1�Ĺ��캯��" << a << endl; }

protected:
	int aa;
};

class base2 :virtual protected base {
public:
	base2() { a = a + 20; cout << "����base2�Ĺ��캯��" << a << endl; }

protected:
	int bb;
};

class derived :private base1, public base2 {
public:
	derived()
	{
		cout << "������derived�Ĺ��캯��" << endl;
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