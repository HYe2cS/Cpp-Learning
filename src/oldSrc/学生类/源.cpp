// test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
1、(20分)编写一个C++程序，建立一个square() 的函数，返回其
参数的平方，重载square() 3次，让它返回整数、长整数与双精度
数的平方。。
2、(30分)分别定义公共基类person(人员)类，由它派生出Teacher(教
    师)类和Cadre(干 部)类，采用多继承方式再由这两个类派生出
    Teacher_Cadre.类， 要求 :
    (1)在公共基类中包含姓名、年龄、性别、电话等数据成员，以
    及用于信息输出的成员函数show。
    (2) Teacher 类的数据成员中还有职称、工资、Cadre 类的数据成
    员还有职务，且这两个类都有输出自己信息的成员函数show。.
    3)在类中声明成员函数，类外定义。
    (4)为了避免二义性，应把公共基类设为虚基类。
    3、(25分)声明一个复数类complex, 使用成员运算符重载函数重载
    “_”实现两个复数的减法。
    4、(25分)定义一一个shape抽象类，由它派生出Rectangle类和Circle类，
    用虚函数分别计算矩形和圆的面积Area。
    */

#include <iostream>
#include <string>
using namespace std;
class person {
private:
    string name;
    int age;
    string sex;
    int number;
public:
    person(string na, int ag, string se, int num);
    void show();
};
person::person(string na, int ag, string se, int num) {
    name = na;
    age = ag;
    sex = se;
    number = num;
}
void person::show() {
    cout << "姓名：" << name << endl;
    cout << "年龄：" << age << endl;
    cout << "性别：" << sex << endl;
    cout << "电话：" << number << endl;
}
class Teacher :virtual public person {
private:
    string title;//职称
    float money;//工资
public:
    Teacher(string na, int ag, string se, int num, string tit, float mon);
    void show();
};
Teacher::Teacher(string na, int ag, string se, int num, string tit, float mon) :person(na, ag, se, num) {
    title = tit;
    money = mon;
}
void Teacher::show() {
    cout << "职称：" << title << endl;
    cout << "工资：" << money << endl;
};

class Cadre :virtual public person {
private:
    string position;//职务
public:
    Cadre(string na, int ag, string se, int num, string pos);
    void show();
};
Cadre::Cadre(string na, int ag, string se, int num, string pos) :person(na, ag, se, num) {
    position = pos;
}
void Cadre::show() {
    cout << "职务：" << position << endl;
}
class Teacher_Cadre :public Teacher, public Cadre {
public:
    Teacher_Cadre(string na, int ag, string se, int num, string tit, float mon, string pos);
    void show();
};

Teacher_Cadre::Teacher_Cadre(string na, int ag, string se, int num, string tit, float mon, string pos) :person(na, ag, se, num), Teacher(na, ag, se, num, tit, mon), Cadre(na, ag, se, num, pos)
{
}
void Teacher_Cadre::show() {
    person::show();
    Teacher::show();
    Cadre::show();
}
int main()
{
    Teacher_Cadre t1("张元节", 20, "男", 13155299590, "特级教师", 3000, "数学老师");
    t1.show();
    return 0;
}