//student类的编写输入输出
#include<iostream>
#include<string.h>
using namespace std;
class Student {
public:
	void set(string na, string sn, char s, int ag);
	void show();
private:
	string name;
	string sno;
	char sex;
	int age;
};
void Student::set(string na, string sn, char s, int ag)
{
	name = na; sno = sn; sex = s; age = ag;
}
void Student::show()
{
	cout << "姓名：" << name << "\t学号：" << sno << "\t性别：" << sex << "\t年龄：" << age << endl;
}
int main()
{
	Student stud1;

	stud1.set("张元节", "20181251215", 'm', 19);//普通方式
	stud1.show();
	Student* p = &stud1;
	(*p).set("张元节", "20181251215", 'm', 19);//(*p).方式
	(*p).show();
	p->set("张元节", "20181251215", 'm', 19);//p->方式
	p->show();
	return 0;
}