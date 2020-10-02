//student��ı�д�������
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	Student(string na = "����", string sn = "20190000000", char s = 'm', int ag = 20, int sco = 0);//���캯��
	~Student();//��������
	void set(string na, string sn, char s, int ag, int sco);
	void show();
	void show_count_sum_avg();
private:
	string name;
	string sno;
	char sex;
	int age;
	int score;
	static int count;//��̬���ݳ�Ա
	static float sum;//��̬���ݳ�Ա
	static float avg;//��̬���ݳ�Ա
};
Student::Student(string na, string sn, char s, int ag, int sco)//���캯��
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
	cout << "������" << name << "\tѧ�ţ�" << sno << "\t�Ա�" << sex << "\t���䣺" << age << "\t�ɼ�" << score << endl;
}
void Student::show_count_sum_avg()
{
	cout << "�ܷ�" << sum << "\tƽ����" << avg << endl;
}
int Student::count = 0;//��̬���ݳ�Ա ��ʼ��
float Student::sum = 0;//��̬���ݳ�Ա ��ʼ��
float Student::avg = 0.0;//��̬���ݳ�Ա ��ʼ��
int main()
{
	Student s1("��Ԫ��", "20181251215", 'm', 19, 98);
	s1.show();
	s1.show_count_sum_avg();
	Student s2("��Ԫ��", "20181251215", 'm', 19, 87);
	s2.show();
	s2.show_count_sum_avg();
	Student s3("��Ԫ��", "20181251215", 'm', 19, 66);
	s3.show();
	s3.show_count_sum_avg();
	return 0;
}