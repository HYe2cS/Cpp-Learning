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
	//��������������������ֵ
	Derived d1(11); b1 = d1;
	b1.show();

	//�����������Գ�ʼ�����������
	Derived d2(22); Base& b2 = d2;
	b2.show();

	//���������ĵ�ַ���Ը�ֵ��ָ���������ָ�룬����������
	Derived d3(33);
	Base* b3 = &d3;
	b3->show();
	//��������ᱨ��
	//Derived *d3=&b3;
	//d3->show();

	//����������β��ǻ�����������������ã�
	//�ڵ��ú���ʱ�����������������Ϊʵ��
	//d4����������󣬺����β��ǻ���
	Derived d4(44); fun(d4);

	return 0;
}