#include<iostream>
using namespace std;
class Base {//�����
public:
	Base()
	{
		a = 5;//��ʼֵa=5
		cout << "Base a=" << a << endl;
	}
protected:
	int a;
};
class  Base1 : virtual public Base {//�������
public:
	int b1;
	Base1()
	{
		a = a + 10; //a=5+10=15
		cout << "Base1 a=" << a << endl;
	}
};
class Base2 : virtual public Base {//�������
public:
	int b2;
	Base2()
	{
		a = a + 20; //a=15+20=35
		cout << "Base2 a=" << a << endl;
	}
};

class Derived :public Base1, public Base2 {
	//������ֻ����һ��base���캯����
	//����Զ������(Derived)�Ĺ��캯��ͨ�����������Ĺ��캯�����г�ʼ����
	//base--base1--derived
	//֮�����������base���캯���ĵ��ñ�����
	//base1���캯��--base2���캯��--derived���캯��
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