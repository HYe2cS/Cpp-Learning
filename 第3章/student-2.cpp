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
int main()
{
	//��������
	Student stud1[4] = { Student("��Ԫ��","20181251215",'m',19),Student("��Ԫ��","20181251215",'m',19),Student("��Ԫ��","20181251215",'m',19) };
	for (int i = 0; i < 4; i++)
	{
		stud1[i].show();
	}
	//����ָ��
	Student* p = stud1;
	for (int i = 0; i < 4; i++)
	{
		p->show();
		p++;
	}
	/* 	Student stud1;
		stud1.show();
		Student stud2("��Ԫ��","20181251215",'m',19);
		stud2.show();

		stud1.set("��Ԫ��","20181251215",'m',19);//��ͨ��ʽ
		stud1.show();
		Student *p=&stud1;
		(*p).set("��Ԫ��","20181251215",'m',19);//(*p).��ʽ
		(*p).show();
		p->set("��Ԫ��","20181251215",'m',19);//p->��ʽ
		p->show();
	*/
	return 0;
}