/*（1）声明Point类，有坐标x、y两个成员变量；对类重载++和--运算符，实现坐标值的改变。*/
#include<iostream>
using  namespace std;
class Point {
private:
	float x;
	float y;
public:
	Point(float a = 0, float b = 0);
	void print();
	//友元运算符重载 ,前缀方式++a
	friend Point operator++(Point& a);
	friend Point operator--(Point& a);
};
Point::Point(float a, float b) {
	x = a;
	y = b;
}
void Point::print() {
	cout << "x=" << x << ",y=" << y << endl;
}
Point operator++(Point& a) {
	++a.x; ++a.y;
	return a;
}
Point operator--(Point& a) {
	--a.x; --a.y;
	return a;
}
int main() {
	Point A1(3.1, 2.5);
	A1.print();
	++A1;
	A1.print();
	return 0;
}