#include<iostream>
#define pi 3.14
using namespace std;
//Բ����
class circle {
public:
	circle(double r = 0);
	void area();
private:
	double re;
};
circle::circle(double r)
{
	re = r;
}
void circle::area()
{
	cout << "�����:" << pi * re * re << endl;
}
//��������
class chang {
public:
	chang(double a = 0, double b = 0);
	void area();
private:
	double ah;
	double bh;
};
chang::chang(double a, double b)
{
	ah = a;
	bh = b;
}
void chang::area()
{
	cout << "�����:" << ah * bh << endl;
}
//��������
class zheng {
public:
	zheng(double a = 0);
	void area();
private:
	double ah;
};
zheng::zheng(double a)
{
	ah = a;
}
void zheng::area()
{
	cout << "�����:" << ah * ah << endl;
}

void Yuan()
{
	double r;
	cout << "������뾶:";
	cin >> r;
	circle c1(r);
	c1.area();
}
void Chang()
{
	double a, b;
	cout << "�����볤�Ϳ��ֵa b:";
	cin >> a >> b;
	chang c2(a, b);
	c2.area();
}
void Zheng()
{
	double a;
	cout << "������߳�:";
	cin >> a;
	zheng z1(a);
	z1.area();
}
int main()
{
	/*
	int i=1,sum=0;
	do{
		sum+=i;
		i++;
	}while(i<=100);
	cout<<sum<<endl;
	*/

	/*
	int sum=0;
	for(int i=1;i<=100;i++)
	{
		sum+=i;
	}
	cout<<sum<<endl;
	*/

	int key = -1;

	cout << "��ѡ����Ҫ���������ͼ��" << endl;
	cout << "1 Բ��    2 ������    3 ������" << endl;
	cin >> key;
	switch (key)
	{
	case 1:Yuan(); break;//Բ��
	case 2:Chang(); break;//������
	case 3:Zheng(); break;//������
	default:return 0;
	}

	return 0;
}