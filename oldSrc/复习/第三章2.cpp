#include<iostream>
#include<string>
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

date::date() { cout << "���������Ĺ��캯��" << endl; }

date::date(int y, int m, int d) :day(d)
{
	year = y;
	month = m;
}

void date::show()
{
	cout << "��������:" << year << "-" << month << "-" << day << endl;
}

date::~date()
{
	cout << "destructing" << endl;
}
/*
int main()
{
	date d1;
	date d2(2019,12,13);
	date *p=&d2;
	p->show();

	date *p1=new date(2015,10,5);
	p1->show();
	delete p1;

	date s[2]={date(2010,3,14),date(23010,3,15)};
	for(int i=0;i<2;i++)
		s[i].show();

	date *p2=s;
	for(i=0;i<2;i++)
	{p2->show();
	p2++;}

	return 0;
}
*/
class people {
public:
	people(string na, char se, int ag, int y, int m, int d);
	void show();
	static void showcount();
	/*	~people(){
			cout<<"dest"<<endl;
		}*/
private:
	string name;
	char sex;
	int age;
	date date1;
	static int count;
};
people::people(string na, char se, int ag, int y, int m, int d) :date1(y, m, d)
{
	name = na;
	sex = se;
	age = ag;
	count++;
}
void people::show()
{
	cout << "����:" << name << endl;
	cout << "�Ա�:" << sex << endl;
	cout << "����:" << age << endl;
	date1.show();
}
void people::showcount()
{
	cout << "������:" << count << endl;
}
int people::count = 0;
int main()
{
	people::showcount();

	//people s;
	//s.show();
	people s1("����", 'm', 19, 2011, 2, 10);
	s1.show();
	people s2("����", 'm', 19, 2011, 2, 10);
	s2.show();
	people::showcount();
	s1.showcount();

	return 0;
}