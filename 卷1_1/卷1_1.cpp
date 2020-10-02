// 卷1_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Circle {
protected:
	float radius;//半径
public:
	Circle(float r) { radius = r; }
	void area();
};
void Circle::area() {
	cout << "圆的面积是：" << 3.14 * radius * radius << endl;
}
class Cylinder :public Circle {
private:

	float height;//高度
public:
	Cylinder(float r, float h) :Circle(r) { height = h; }
	void volume();//体积
};
void Cylinder::volume() {
	cout << "圆柱体体积：" << 3.14 * radius * radius * height << endl;
}
int main()
{
	Circle c1(3.2);
	c1.area();
	Cylinder cy(3.2, 3.3);
	cy.volume();
	//std::cout << "Hello World!\n";
}