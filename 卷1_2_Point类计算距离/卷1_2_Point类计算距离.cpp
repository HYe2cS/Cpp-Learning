// 卷1_2_Point类计算距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>//包含数学库
using namespace std;
class Point {
private:
	float x;
	float y;
public:
	Point(float x1, float y1) {
		x = x1;
		y = y1;
	}
	void distance();
};
void Point::distance() {
	cout << "到原点的距离：" << sqrt(x * x + y * y) << endl;
}
int main()
{
	Point p1(3, 4);
	p1.distance();

	return 0;
}