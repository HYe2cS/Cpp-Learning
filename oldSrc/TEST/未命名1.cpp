#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	Student(string sn, string na, char s, int a);
	void setstudent(string sn, string na, char s, int a);
	void show();
private:
	string sno;
	string name;
	char sex;
	int age;
};
Student::Student(string sn, string na, char s, int a)
{
	sno = sn;
	name = na;
	sex = s;
	age = a;
}
void Student::setstudent(string sn, string na, char s, int a)
{
	sno = sn;
	name = na;
	sex = s;
	age = a;
}
void Student::show()
{
	cout << "学号:" << sno << endl;
	cout << "姓名:" << name << endl;
	cout << "性别:" << sex << endl;
	cout << "年龄:" << age << endl;
}
int main()
{
	Student s[3] = { Student("2018342","开心超人",'f',7),Student("2013842","甜心超人",'m',9),Student("2018342","开心超人",'f',7) };
	for (int i = 0; i < 3; i++)
	{
		s[i].show();
	}
	Student* p = &s[2];
	for (int i = 0; i < 3; i++)
	{
		p->show();
		p--;
	}
	/*Student s1("2019321","小心超人",'f',8);
	s1.show();
	s1.setstudent("2019321","小心超人",'f',8);
	s1.show();
	Student s2("2019321","小心超人",'f',8);
	s2.show();*/
	return 0;
}