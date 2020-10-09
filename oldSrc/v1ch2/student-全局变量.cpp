//student类的编写输入输出
#include<iostream>
#include<string>
using namespace std;
int count = 0;
float sum = 0;
float avg = 0.0;
class Student {
public:
	Student(string na = "张三", string sn = "20190000000", char s = 'm', int ag = 20, int sco = 0);//构造函数
	void set(string na, string sn, char s, int ag, int sco);
	void show();
private:
	string name;
	string sno;
	char sex;
	int age;
	int score;
	//	int count;
	//	float sum;
	//	float avg;
};
Student::Student(string na, string sn, char s, int ag, int sco)//构造函数
{
	name = na; sno = sn; sex = s; age = ag; score = sco;
	++count;
	sum += score;
	avg = sum / count;
}
void Student::set(string na, string sn, char s, int ag, int sco)
{
	name = na; sno = sn; sex = s; age = ag; score = sco;
}
void Student::show()
{
	cout << "姓名：" << name << "\t学号：" << sno << "\t性别：" << sex << "\t年龄：" << age << "\t成绩" << score;
	cout << "\t总分" << sum << "\t平均分" << avg << endl;
}

int main()
{
	Student s1("张元节", "20181251215", 'm', 19, 98);
	s1.show();

	Student s2("张元节", "20181251215", 'm', 19, 87);
	s2.show();

	Student s3("张元节", "20181251215", 'm', 19, 66);
	s3.show();

	return 0;
}