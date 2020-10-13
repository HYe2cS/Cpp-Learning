// 卷1_P204_eg5_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Complex {
public:
    Complex(double r = 0.0, double i = 0.0);
    void print();
    //友元运算符重载
    friend Complex operator+(Complex& a, Complex& b);
    //成员运算符重载
    Complex operator-(Complex c);
private:
    double real;//实部
    double imag;//虚部
};
Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}
Complex operator+(Complex& a, Complex& b) {
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}
Complex Complex::operator-(Complex c) {
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.real;
    return temp;
}
void Complex::print() {
    cout << real;
    if (imag > 0)cout << "+";
    if (imag != 0)cout << imag << "i" << endl;
}
int main()
{
    Complex com1(3, 4);
    Complex com2(4, 5);
    Complex com3;

    com3 = com2 - com1;
    com3.print();
    com3 = com2 + com1;
    com3.print();
    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件