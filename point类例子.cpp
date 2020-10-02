#include<iostream>
using namespace std;
#include<math.h>
//类point
class point {
public:
	point(double x1 = 0.0, double y1 = 0.0);
	//point(){}
	//point(double x1,double y1);
	//带默认值的和构造函数的重载等价但不能同时使用
	void show();
	~point() { cout << "Dstructing" << endl; }
	int getx() { return x; }
	int gety() { return y; }
	//拷贝构造函数
	point(point& opx) { x = 2 * opx.x; y = 2 * opx.y; ++count; }
	//静态成员函数管理静态数据成员
	static void shoucount() { cout << "总点数:" << count << endl; }
private:
	double x, y;
	static int count;
};

//类外定义成员函数
//对于常量类型和引用类型必须使用成员初始化列表方式
point::point(double x1, double y1) :x(x1)
{
	y = y1;
	++count;
}
//带默认值的声明的时候加默认值，定义的时候就不需要
//普通成员函数
void point::show()
{
	cout << "x的坐标为:" << x << "," << "y的坐标为:" << y << endl;
}
//对象作为参数进行传递
void distance1(point& p1, point& p2)
{
	cout << "距离为:" << sqrt(((p1.getx() - p2.getx()) * (p1.getx() - p2.getx())) +
		((p1.gety() - p2.gety()) * (p1.gety() - p2.gety()))) << endl;
}

int point::count = 0;

int main()
{
	//类的对象和指针
	cout << "类的对象和指针****************************" << endl;
	point p1(2.1, 3.2);
	p1.show();

	point p2;
	p2.show();

	point* p = &p1;
	p->show();
	(*p).show();

	point* px = new point(3.4, 5.2);
	px->show();
	(*px).show();
	delete px;
	//用new运算符创建的对象用delete进行释放的时候会调用析构函数
	//对象数组和对象指针
	cout << "对象数组****************************" << endl;
	point ob[3];
	//包含对象ob[0]、ob[1]、ob[2]
	for (int i = 0; i < 3; i++)
		ob[i].show();
	point* pp = ob;
	for (i = 0; i < 3; i++)
	{
		pp->show();
		pp++;
	}
	point os[3] = { point(4.1,2.3),point(5.3,6.1),point(7.2,4.3) };
	for (int j = 0; j < 3; j++)
		os[j].show();
	point* pps = os;
	for (j = 0; j < 3; j++)
	{
		pps->show();
		pps++;
	}
	cout << "距离******************************" << endl;
	//定义两个求距离的点
	point ss1(5.3, 4.2), ss2(2.1, 3.2);

	distance1(ss1, ss2);
	//拷贝构造函数
	cout << "拷贝构造函数*********************" << endl;
	p2 = p1;//用默认赋值运算符
	point p3 = p1;
	point p4;
	p4 = p1;
	p3.show();
	p4.show();
	cout << "总点数:********************************" << endl;
	point::shoucount();

	return 0;
}