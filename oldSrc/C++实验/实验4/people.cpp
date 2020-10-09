/*（2）声明一个People（人员）类，具有属性如下：number（编号）、name（姓名）、sex（性别）、birthday（出生日期）、id（身份证号）。
其中"出生日期"是一个子对象（请自行设计日期类）。用成员函数实现对人员信息的录入和显示。
在测试程序中声明People类的对象数组，录入数据并显示。
同时为People重载运算符"=="，运算符"=="为判断两个People对应的id属性是否相同。*/
#include<iostream>
#include<string>
#define N 2
using namespace std;
class Date {
public:
	Date(int y, int m, int d);
	void set(int y, int m, int d);
	void show();

private:
	int year;
	int month;
	int day;
};
Date::Date(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::set(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::show()
{
	cout << "生日：" << year << "年" << month << "月" << day << "日" << endl;
}
class People {
public:
	People(int y = 2000, int m = 00, int d = 00, string i = "340321200000000000", string name = "张三", string nu = "20000000000", char se = 'm');
	void set(int y = 2000, int m = 00, int d = 00, string i = "340321200000000000", string name = "张三", string nu = "20000000000", char se = 'm');
	void show();
	//成员函数重载运算符
	int operator==(People a);
private:
	Date birthday;
	string id;//身份证号
	string name;
	string number;
	char sex;
};
People::People(int y, int m, int d, string i, string name, string nu, char se) :birthday(y, m, d)
{
	id = i;
	this->name = name;
	number = nu;
	sex = se;
}
void People::set(int y, int m, int d, string i, string name, string nu, char se)
{
	id = i;
	this->name = name;
	number = nu;
	sex = se;
	birthday.set(y, m, d);
}
void People::show()
{
	cout << "身份证号：" << id << endl << "姓名：" << name << endl << "编号：" << number << endl << "性别：" << sex << endl;
	birthday.show();
}
int People::operator==(People a) {
	if ((*this).id == a.id)return 1;
	return 0;
}
int main()
{
	People p[N];
	int y; int m; int d; string i1; string na; string nu; char se;//定义年龄名称等参数，用于传入set函数
	for (int i = 0; i < N; i++)
	{
		cout << "请输入第" << i + 1 << "位人员信息：" << endl;
		cout << "出生年月日：";
		cin >> y >> m >> d;
		cout << "身份证号：";
		cin >> i1;
		cout << "姓名：";
		cin >> na;
		cout << "编号：";
		cin >> nu;
		cout << "性别：";
		cin >> se;
		//		cin>>y>>m>>d>>i1>>na>>nu>>se;
		p[i].set(y, m, d, i1, na, nu, se);
		cout << "第" << i + 1 << "位人员信息:" << endl;
		p[i].show();
	}
	if (p[0] == p[1])cout << "二者身份证号相同" << endl;
	else cout << "二者身份证号不同" << endl;

	return 0;
}