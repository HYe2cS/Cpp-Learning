//student��ı�д�������
#include<iostream>
#include<string>
using namespace std;
int count = 0;
float sum = 0;
float avg = 0.0;
class Student {
public:
	Student(string na = "����", string sn = "20190000000", char s = 'm', int ag = 20, int sco = 0);//���캯��
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
Student::Student(string na, string sn, char s, int ag, int sco)//���캯��
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
	cout << "������" << name << "\tѧ�ţ�" << sno << "\t�Ա�" << sex << "\t���䣺" << age << "\t�ɼ�" << score;
	cout << "\t�ܷ�" << sum << "\tƽ����" << avg << endl;
}

int main()
{
	Student s1("��Ԫ��", "20181251215", 'm', 19, 98);
	s1.show();

	Student s2("��Ԫ��", "20181251215", 'm', 19, 87);
	s2.show();

	Student s3("��Ԫ��", "20181251215", 'm', 19, 66);
	s3.show();

	return 0;
}