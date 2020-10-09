// 复数类的减法重载.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
4、(25分)定义一一个shape抽象类，由它派生出Rectangle类和Circle类，
用虚函数分别计算矩形和圆的面积Area。
*/

#include <iostream>
using namespace std;
class shape {
public:
    virtual void Area() = 0;
};
class Rectangle :public shape {
private:
    float chang;
    float kuan;
public:
    Rectangle(float c, float k);
    void Area();
};
Rectangle::Rectangle(float c, float k) {
    chang = c;
    kuan = k;
}
void Rectangle::Area() {
    cout << "面积是：" << chang * kuan << endl;
}
class Circle :public shape {
private:
    float radius;
public:
    Circle(float r);
    void Area();
};
Circle::Circle(float r) {
    radius = r;
}
void Circle::Area() {
    cout << "面积是：" << 3.14 * radius * radius << endl;
}
int main() {
    Circle c1(3);
    c1.Area();
    Rectangle r1(3, 4);
    r1.Area();
    return 0;
}