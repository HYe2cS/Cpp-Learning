#include<iostream>
#include<string>
using namespace std;
class Score {
public:
	Score(float c = 0, float e = 0, float m = 0);
	void show();
private:
	float computer;
	float english;
	float mathematics;
};
Score::Score(float c, float e, float m)
{
	computer = c;
	english = e;
	mathematics = m;
}
void Score::show()
{
	cout << "\n������ɼ���" << computer;
	cout << "\nӢ��ɼ���" << english;
	cout << "\n��ѧ�ɼ���" << mathematics;
}
class Student {
private:
	string name;
	string stu_no;
	Score score1;
public:
	Student(string name1, string stu_no1, float s1, float s2, float s3);
	void show();
};
Student::Student(string name1, string stu_no1, float s1, float s2, float s3) :score1(s1, s2, s3)
{
	name = name1;
	stu_no = stu_no1;
}
void Student::show()
{
	cout << "\n������" << name;
	cout << "\nѧ�ţ�" << stu_no;
	score1.show();
}
int main()
{
	Student stu1("��С��", "990201", 90, 80, 70);
	stu1.show();

	cout << endl;
	Student stu2("������", "990202", 95, 85, 75);
	stu2.show();

	return 0;
}