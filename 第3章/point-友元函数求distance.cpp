#include<iostream>
#include<cmath>
using namespace std;
class Point {
public:
	Point(int a = 0, int b = 0);
	Point(const Point& p);
	void print();
	friend void Distance(Point& p1, Point& p2);
private:
	int x, y;
};
Point::Point(int a, int b)
{
	x = a; y = b;
	cout << "使用了普通的构造函数" << endl;
}
Point::Point(const Point& p)//拷贝构造函数
{
	x = 2 * p.x;
	y = 2 * p.y;
	cout << "使用了拷贝构造函数" << endl;
}
void Point::print()
{
	cout << "横坐标x是:" << x << endl;
	cout << "纵坐标y是:" << y << endl;
}
void fun1(Point p)
{
	p.print();
}
Point fun2()
{
	Point p(10, 30);
	return p;
}
void Distance(Point& p1, Point& p2)
{
	cout << "距离为:" << sqrt(((p1.x - p2.x) * (p1.x - p2.x)) +
		((p1.y - p2.y) * (p1.y - p2.y))) << endl;
}

int main()
{
	Point p1(30, 40);
	Point p2(50, 60);
	//	p1.print();
	//	p2.print();
	Distance(p1, p2);
	//	cout<<"调用构造拷贝构造函数的第一种情况,用类的一个对象去初始化另一个对象"<<endl;
	//	Point p2(p1);//代入法

	/*	Point p3=p1;//赋值法
		p3.print();
		cout<<"----------------------------------"<<endl;

		cout<<"调用构造拷贝构造函数的第二种情况,对象作为函数的形参，调用函数时，实参传递到形参调用拷贝构造函数"<<endl;
		fun1(p1);
		p1.print();
		cout<<"----------------------------------"<<endl;

		cout<<"调用构造拷贝构造函数的第三种情况,函数返回值是类的对象"<<endl;
		p2=fun2();
		p2.print();
		*/
	return 0;
}