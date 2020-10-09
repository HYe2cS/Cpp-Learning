// 复数类的减法重载.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
3、(25分)声明一个复数类complex, 使用成员运算符重载函数重载
“_”实现两个复数的减法。
4、(25分)定义一一个shape抽象类，由它派生出Rectangle类和Circle类，
用虚函数分别计算矩形和圆的面积Area。
*/

#include <iostream>
using namespace std;
class complex {
    int real;
    int image;//虚数
public:
    complex(int r = 0, int i = 0);
    //成员运算符重载
    complex operator-(complex x);
    //友元运算符重载
    friend complex operator+(complex x, complex y);
    void show();
};
complex::complex(int r, int i) {
    real = r;
    image = i;
}
complex complex::operator-(complex x) {
    complex temp;
    temp.real = this->real - x.real;
    temp.image = this->image - x.image;
    return temp;
}
complex operator+(complex x, complex y) {
    complex temp;
    temp.real = x.real + y.real;
    temp.image = x.image + y.image;
    return temp;
}
void complex::show() {
    cout << "real=" << real << ",image=" << image << endl;
}
int main()
{
    complex com1(3, 4);
    complex com2(4, 5);
    complex com3;
    com3 = com1 - com2;
    com3.show();
    complex com4;
    com4 = com1 + com2;
    com4.show();
    return 0;
}