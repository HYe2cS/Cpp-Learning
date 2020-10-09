#include<iostream>
#define pi 3.14
using namespace std;
//圆形类
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
	cout << "面积是:" << pi * re * re << endl;
}
//长方形类
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
	cout << "面积是:" << ah * bh << endl;
}
//正方形类
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
	cout << "面积是:" << ah * ah << endl;
}

void Yuan()
{
	double r;
	cout << "请输入半径:";
	cin >> r;
	circle c1(r);
	c1.area();
}
void Chang()
{
	double a, b;
	cout << "请输入长和宽的值a b:";
	cin >> a >> b;
	chang c2(a, b);
	c2.area();
}
void Zheng()
{
	double a;
	cout << "请输入边长:";
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

	cout << "请选择你要计算面积的图形" << endl;
	cout << "1 圆形    2 长方形    3 正方形" << endl;
	cin >> key;
	switch (key)
	{
	case 1:Yuan(); break;//圆形
	case 2:Chang(); break;//长方形
	case 3:Zheng(); break;//正方形
	default:return 0;
	}

	return 0;
}