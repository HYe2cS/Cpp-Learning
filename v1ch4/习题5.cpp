#include<iostream>
#include<string>
using namespace std;
class person {
protected:
	string name;
	int age;
	char sex;
	string address;
	int phone;
public:
	person(string na, int ag, char se, string add, int ph);
	void show();
};

person::person(string na, int ag, char se, string add, int ph) {
	name = na;
	age = ag;
	sex = se;
	address = add;
	phone = ph;
}
void person::show()
{
	cout << "����:" << name << endl << "����:" << age << endl << "�Ա�:" << sex << endl
		<< "��ַ:" << address << endl << "�绰����:" << phone << endl;
}

class Teacher :virtual public person {
protected:
	string position;//ְ��
	float salary;//����
public:
	Teacher(string na, int ag, char se, string add, int ph, string po, float sa);
	void show();
};
Teacher::Teacher(string na, int ag, char se, string add, int ph, string po, float sa) :person(na, ag, se, add, ph) {
	position = po;
	salary = sa;
}
void Teacher::show() {
	person::show();
	cout << "ְ��:" << position << endl << "����:" << salary << endl;
}

class Cadre :virtual public person {
protected:
	string job;//ְ��
public:
	Cadre(string na, int ag, char se, string add, int ph, string jo);
	void show();
};
Cadre::Cadre(string na, int ag, char se, string add, int ph, string jo) :person(na, ag, se, add, ph) {
	job = jo;
}
void Cadre::show() {
	person::show();
	cout << "ְ��:" << job << endl;
}

class Teacher_Cadre :public Teacher, public Cadre {
public:
	Teacher_Cadre(string na, int ag, char se, string add, int ph, string jo, string po, float sa) :person(na, ag, se, add, ph),
		Teacher(na, ag, se, add, ph, po, sa),
		Cadre(na, ag, se, add, ph, jo) {
	};
	void show();
};

void Teacher_Cadre::show() {
	person::show();
	cout << "ְ��:" << job << endl;
	cout << "ְ��:" << position << endl << "����:" << salary << endl;
}

int main()
{
	Teacher_Cadre tc("��Ԫ��", 19, 'm', "����ʡ", 13155299590, "ѧ��", "�߼�", 1);
	tc.show();
	return 0;
}