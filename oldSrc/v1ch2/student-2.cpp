//student类的编写输入输出
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	Student(string na = "张三", string sn = "20190000000", char s = 'm', int ag = 20);//构造函数
	void set(string na, string sn, char s, int ag);
	void show();
private:
	string name;
	string sno;
	char sex;
	int age;
};
Student::Student(string na, string sn, char s, int ag)//构造函数
{
	name = na; sno = sn; sex = s; age = ag;
}
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
	//对象数组
	Student stud1[4] = { Student("张元节","20181251215",'m',19),Student("张元节","20181251215",'m',19),Student("张元节","20181251215",'m',19) };
	for (int i = 0; i < 4; i++)
	{
		stud1[i].show();
	}
	//对象指针
	Student* p = stud1;
	for (int i = 0; i < 4; i++)
	{
		p->show();
		p++;
	}
	/* 	Student stud1;
		stud1.show();
		Student stud2("张元节","20181251215",'m',19);
		stud2.show();

		stud1.set("张元节","20181251215",'m',19);//普通方式
		stud1.show();
		Student *p=&stud1;
		(*p).set("张元节","20181251215",'m',19);//(*p).方式
		(*p).show();
		p->set("张元节","20181251215",'m',19);//p->方式
		p->show();
	*/
	return 0;
}