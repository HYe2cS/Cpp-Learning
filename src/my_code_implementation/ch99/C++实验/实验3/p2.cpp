#include <iostream>
#include <string>
using namespace std;
class MyArray              //声明一个基类MyArray
{
public:
    MyArray(int leng);      //构造函数
    ~MyArray();           //析构函数
    void Input();           //输入数据的成员函数
    void Display(string);    //输出函数的成员函数
protected:
    int* alist;             //基类中存放一组整数
    int length;            //整数的个数
};
MyArray::MyArray(int leng)
{
    if (leng <= 0)
    {
        cout << "error length";
        exit(1);
    }
    alist = new int[leng];
    length = leng;
    if (alist == NULL)
    {
        cout << "assign failure";
        exit(1);
    }
    cout << "MyArray类对象已创建。" << endl;
}
MyArray::~MyArray()
{
    delete[] alist;
    cout << "MyArray类对象被撤销。" << endl;
}

void MyArray::Input()
{
    cout << "请从键盘输入" << length << "个整数：";
    int i;
    int* p = alist;
    for (i = 0; i < length; i++, p++)
        cin >> *p;
}

void MyArray::Display(string str)
{
    int i;
    int* p = alist;
    cout << str << length << "个整数：";
    for (i = 0; i < length; i++, p++)
        cout << *p << " ";
    cout << endl;
}

class AverArray :public MyArray {
public:
    AverArray(int leng);
    void Aver();//求平均值
};
AverArray::AverArray(int leng) :MyArray(leng)
{
}
void AverArray::Aver()
{
    int* p = alist;
    float sum = 0;
    for (int i = 0; i < length; i++, p++)
        sum += *p;
    cout << "平均值是:" << sum / length << endl;
}

int main()
{
    AverArray a(5);
    a.Input();
    a.Display("显示已输入的");
    a.Aver();
    return 0;
}