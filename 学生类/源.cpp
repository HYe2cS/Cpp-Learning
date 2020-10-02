// test1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
/*
1��(20��)��дһ��C++���򣬽���һ��square() �ĺ�����������
������ƽ��������square() 3�Σ�����������������������˫����
����ƽ������
2��(30��)�ֱ��幫������person(��Ա)�࣬����������Teacher(��
	ʦ)���Cadre(�� ��)�࣬���ö�̳з�ʽ������������������
	Teacher_Cadre.�࣬ Ҫ�� :
	(1)�ڹ��������а������������䡢�Ա𡢵绰�����ݳ�Ա����
	��������Ϣ����ĳ�Ա����show��
	(2) Teacher ������ݳ�Ա�л���ְ�ơ����ʡ�Cadre ������ݳ�
	Ա����ְ�����������඼������Լ���Ϣ�ĳ�Ա����show��.
	3)������������Ա���������ⶨ�塣
	(4)Ϊ�˱�������ԣ�Ӧ�ѹ���������Ϊ����ࡣ
	3��(25��)����һ��������complex, ʹ�ó�Ա��������غ�������
	��_��ʵ�����������ļ�����
	4��(25��)����һһ��shape�����࣬����������Rectangle���Circle�࣬
	���麯���ֱ������κ�Բ�����Area��
	*/

#include <iostream>
#include <string>
using namespace std;
class person {
private:
	string name;
	int age;
	string sex;
	int number;
public:
	person(string na, int ag, string se, int num);
	void show();
};
person::person(string na, int ag, string se, int num) {
	name = na;
	age = ag;
	sex = se;
	number = num;
}
void person::show() {
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "�Ա�" << sex << endl;
	cout << "�绰��" << number << endl;
}
class Teacher :virtual public person {
private:
	string title;//ְ��
	float money;//����
public:
	Teacher(string na, int ag, string se, int num, string tit, float mon);
	void show();
};
Teacher::Teacher(string na, int ag, string se, int num, string tit, float mon) :person(na, ag, se, num) {
	title = tit;
	money = mon;
}
void Teacher::show() {
	cout << "ְ�ƣ�" << title << endl;
	cout << "���ʣ�" << money << endl;
};

class Cadre :virtual public person {
private:
	string position;//ְ��
public:
	Cadre(string na, int ag, string se, int num, string pos);
	void show();
};
Cadre::Cadre(string na, int ag, string se, int num, string pos) :person(na, ag, se, num) {
	position = pos;
}
void Cadre::show() {
	cout << "ְ��" << position << endl;
}
class Teacher_Cadre :public Teacher, public Cadre {
public:
	Teacher_Cadre(string na, int ag, string se, int num, string tit, float mon, string pos);
	void show();
};

Teacher_Cadre::Teacher_Cadre(string na, int ag, string se, int num, string tit, float mon, string pos) :person(na, ag, se, num), Teacher(na, ag, se, num, tit, mon), Cadre(na, ag, se, num, pos)
{
}
void Teacher_Cadre::show() {
	person::show();
	Teacher::show();
	Cadre::show();
}
int main()
{
	Teacher_Cadre t1("��Ԫ��", 20, "��", 13155299590, "�ؼ���ʦ", 3000, "��ѧ��ʦ");
	t1.show();
	return 0;
}