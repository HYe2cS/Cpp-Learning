#include<iostream>
#include<string>
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
	People(int y = 2000, int m = 00, int d = 00, string i = "20000000000", string na = "张三", char se = 'm');
	void set(int y, int m, int d, string i, string na, char se);
	void show();
private:
	Date birthday;
	string id;
	string name;
	char sex;
};
People::People(int y, int m, int d, string i, string na, char se) :birthday(y, m, d)
{
	id = i;
	name = na;
	sex = se;
}
void People::set(int y, int m, int d, string i, string na, char se)
{
	id = i;
	name = na;
	sex = se;
	birthday.set(y, m, d);
}
void People::show()
{
	cout << "编号：" << id << endl << "姓名：" << name << endl << "性别：" << sex << endl;
	birthday.show();
}
int main()
{
	People p;
	p.set(2001, 01, 01, "20181251215", "张元节", 'm');
	p.show();
	return 0;
}