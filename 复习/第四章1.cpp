#include<iostream>
using namespace std;
class base {
public:
	base(int x) { a = x; cout << "����base�Ĺ��캯��" << endl; }
	~base() {
		cout << "����base������shu" << endl;
	}
	void show() { cout << "a=" << a << endl; }
private:
	int a;
};

class base1 {
public:
	base1(int xx) { aa = xx; cout << "����base1�Ĺ��캯��" << endl; }
	void show()
	{
		cout << "aa=" << aa << endl;
	}
	~base1() {
		cout << "����base1������shu" << endl;
	}
protected:
	int aa;
};

class derived :private base1, public base {
public:
	derived(int x, int x1, int xx1, int xx2, int y) :base(x), base1(xx1), s1(x1), s2(xx2)
	{
		b = y;
		cout << "������derived�Ĺ��캯��" << endl;
	}
	void show()
	{
		base::show();
		base1::show();
		s1.show();
		s2.show();
		cout << "b=" << b << endl;
	}
	~derived() {
		cout << "����derived������shu" << endl;
	}
	base1::show;

private:
	int b;
	base1 s2;
	base s1;
};

int main()
{
	derived ob(4, 5, 6, 7, 8);
	//	ob.showa();
	ob.show();
	return 0;
}