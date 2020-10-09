//student类的编写输入输出
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	Student(string na = "张三", string sn = "20190000000", char s = 'm', int ag = 20, int sco = 0);//构造函数
	~Student();//析构函数
	void set(string na, string sn, char s, int ag, int sco);
	void show();
	static void show_count_sum_avg();//静态成员函数
private:
	string name;
	string sno;
	char sex;
	int age;
	int score;
	static int count;//静态数据成员
	static float sum;//静态数据成员
	static float avg;//静态数据成员
};
Student::Student(string na, string sn, char s, int ag, int sco)//构造函数
{
	name = na; sno = sn; sex = s; age = ag; score = sco;
	++count;
	sum += score;
	avg = sum / count;
}
Student::~Student()
{
	--count;
	sum = sum - score;
}
void Student::set(string na, string sn, char s, int ag, int sco)
{
	name = na; sno = sn; sex = s; age = ag; score = sco;
}
void Student::show()
{
	cout << "姓名：" << name << "\t学号：" << sno << "\t性别：" << sex << "\t年龄：" << age << "\t成绩" << score << endl;
}
void Student::show_count_sum_avg()
{
	cout << "总分" << sum << "\t平均分" << avg << endl;
}
int Student::count = 0;//静态数据成员 初始化
float Student::sum = 0;//静态数据成员 初始化
float Student::avg = 0.0;//静态数据成员 初始化
int main()
{
	Student::show_count_sum_avg();
	Student s1("张元节", "20181251215", 'm', 19, 98);
	s1.show();
	s1.show_count_sum_avg();
	Student s2("张元节", "20181251215", 'm', 19, 87);
	s2.show();
	s1.show_count_sum_avg();//此成员函数是类内公有的
	s2.show_count_sum_avg();
	Student s3("张元节", "20181251215", 'm', 19, 66);
	s3.show();
	s3.show_count_sum_avg();
	return 0;
}