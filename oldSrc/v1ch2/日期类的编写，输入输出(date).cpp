﻿//日期类的编写，输入输出
#include<iostream>
using namespace std;
class Date {
public:
	void set(int y, int m, int d);
	void show();
private:
	int year;
	int month;
	int day;
};
void Date::set(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::show()
{
	cout << "日期是：" << year << " 年 " << month << " 月 " << day << " 日 " << endl;
}
int main()
{
	Date date1;

	date1.set(2019, 9, 11);//普通方式
	date1.show();
	Date* p = &date1;
	(*p).set(2019, 9, 11);//(*p).方式
	(*p).show();
	p->set(2019, 9, 11);//p->方式
	p->show();
	return 0;
}