#include<iostream>
using namespace std;

class date {
public:
	date();
	date(int y, int m, int d);
	void show();
	~date();

private:
	int year, month, day;
};

date::date() { cout << "不带参数的构造函数" << endl; }

date::date(int y, int m, int d) :day(d)
{
	year = y;
	month = m;
}

void date::show()
{
	cout << "出生日期" << year << "-" << month << "-" << day << endl;
}

date::~date()
{
	cout << "destructing" << endl;
}

int main()
{
	date d1;
	date d2(2019, 12, 13);
	date* p = &d2;
	p->show();

	date* p1 = new date(2015, 10, 5);
	p1->show();
	delete p1;

	date s[2] = { date(2010,3,14),date(23010,3,15) };
	for (int i = 0; i < 2; i++)
		s[i].show();

	date* p2 = s;
	for (int i = 0; i < 2; i++)
	{
		p2->show();
		p2++;
	}

	return 0;
}