// 卷1_3_P196_4_20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class area_c1 {
protected:
    double height;
    double width;
public:
    area_c1(double r, double s) {
        height = r;
        width = s;
    }
    virtual double area() = 0;
};
class rectangle :public area_c1 {
public:
    rectangle(double h, double w) :area_c1(h, w) {
        height = h;
        width = w;
    }
    double area() {
        return height * width;
    }
};
class isosceles :public area_c1 {
public:
    isosceles(double h, double w) :area_c1(h, w) {
        height = h;
        width = w;
    }
    double area() {
        return 0.5 * height * width;
    }
};
int main()
{
    rectangle r1(10.0, 5.0);
    cout << r1.area() << endl;
    isosceles is1(4.0, 6.0);
    cout << is1.area() << endl;
    area_c1* p;
    p = &r1;
    cout << p->area() << endl;
    p = &is1;
    cout << p->area() << endl;;

    return 0;
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