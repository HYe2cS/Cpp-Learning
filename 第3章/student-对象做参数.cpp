//student��ı�д�������
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	Student(string na = "����", string sn = "20190000000", char s = 'm', int ag = 20);//���캯��
	void set(string na, string sn, char s, int ag);
	void show();
private:
	string name;
	string sno;
	char sex;
	int age;
};
Student::Student(string na, string sn, char s, int ag)//���캯��
{
	name = na; sno = sn; sex = s; age = ag;
}
void Student::set(string na, string sn, char s, int ag)
{
	name = na; sno = sn; sex = s; age = ag;
}
void Student::show()
{
	cout << "������" << name << "\tѧ�ţ�" << sno << "\t�Ա�" << sex << "\t���䣺" << age << endl;
}
void Change(Student p)	//������Ϊ��������:
{
	p.set("�����", "20181251162", 'm', 20);
	cout << "�ں���Change�ڣ��βζ���p�����ݳ�ԱֵΪ:" << endl;
	p.show();
}
int main()
{
	Student s1("��Ԫ��", "20181251215", 'm', 19);
	//������Ϊ��������:
	cout << "������Ϊ��������:" << endl;
	cout << "�ڵ��ú���Changeǰ��ʵ�ζ���s1�����ݳ�ԱֵΪ:" << endl;
	s1.show();
	Change(s1);
	cout << "�ڵ��ú���Change��ʵ�ζ���s1�����ݳ�ԱֵΪ:" << endl;
	s1.show();

	return 0;
}