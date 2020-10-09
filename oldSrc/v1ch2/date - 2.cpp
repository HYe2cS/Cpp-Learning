//日期类的编写、输入输出类
//函数默认值、构造函数
//(*p).方式 、p->方式 实现
//对象数组、对象指针
#include<iostream>
using namespace std;
class Date {
public:
	Date(int y = 2000, int m = 1, int d = 1);
	void set(int y, int m, int d);
	void show();
	//		int getyear();
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
	cout << "日期是：" << year << " 年 " << month << " 月 " << day << " 日 " << endl;
}
int main()
{
	//对象数组
	Date date3[4] = { Date(2019,9,17),Date(2019,9,12),Date(2019,9,11) };
	for (int i = 0; i < 4; i++)
	{
		date3[i].show();
	}
	//对象指针
	Date* p = date3;//date3表示数组首地址
	for (i = 0; i < 4; i++)
	{
		p->show();
		p++;
	}
	/*
		Date date1;
		date1.show();
		Date date2(2019,9,12);
		date2.show();
		//
		date1.set(2019,9,11);//普通方式
		date1.show();
		Date *p=&date1;
		(*p).set(2019,9,11);//(*p).方式
		(*p).show();
		p->set(2019,9,11);//p->方式
		p->show();
	*/
	return 0;
}