#include<iostream>
using namespace std;
class Point {
public:
	Point(int a = 0, int b = 0);
	Point(const Point& p);
	void print();
private:
	int x, y;
};
Point::Point(int a, int b)
{
	x = a; y = b;
	cout << "ʹ������ͨ�Ĺ��캯��" << endl;
}
Point::Point(const Point& p)//�������캯��
{
	x = 2 * p.x;
	y = 2 * p.y;
	cout << "ʹ���˿������캯��" << endl;
}
void Point::print()
{
	cout << "������x��:" << x << endl;
	cout << "������y��:" << y << endl;
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
int main()
{
	Point p1(30, 40);
	p1.print();
	cout << "���ù��쿽�����캯���ĵ�һ�����,�����һ������ȥ��ʼ����һ������" << endl;
	Point p2(p1);//���뷨
	p2.print();
	Point p3 = p1;//��ֵ��
	p3.print();
	cout << "----------------------------------" << endl;

	cout << "���ù��쿽�����캯���ĵڶ������,������Ϊ�������βΣ����ú���ʱ��ʵ�δ��ݵ��βε��ÿ������캯��" << endl;
	fun1(p1);
	p1.print();
	cout << "----------------------------------" << endl;

	cout << "���ù��쿽�����캯���ĵ��������,��������ֵ����Ķ���" << endl;
	p2 = fun2();
	p2.print();

	return 0;
}