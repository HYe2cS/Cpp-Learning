//student��ı�д�������
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
	cout << "������" << name << "\tѧ�ţ�" << sno << "\t�Ա�" << sex << "\t���䣺" << age << endl;
}
int main()
{
	Student stud1;

	stud1.set("��Ԫ��", "20181251215", 'm', 19);//��ͨ��ʽ
	stud1.show();
	Student* p = &stud1;
	(*p).set("��Ԫ��", "20181251215", 'm', 19);//(*p).��ʽ
	(*p).show();
	p->set("��Ԫ��", "20181251215", 'm', 19);//p->��ʽ
	p->show();
	return 0;
}