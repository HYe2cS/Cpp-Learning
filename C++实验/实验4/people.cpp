/*��2������һ��People����Ա���࣬�����������£�number����ţ���name����������sex���Ա𣩡�birthday���������ڣ���id�����֤�ţ���
����"��������"��һ���Ӷ�����������������ࣩ���ó�Ա����ʵ�ֶ���Ա��Ϣ��¼�����ʾ��
�ڲ��Գ���������People��Ķ������飬¼�����ݲ���ʾ��
ͬʱΪPeople���������"=="�������"=="Ϊ�ж�����People��Ӧ��id�����Ƿ���ͬ��*/
#include<iostream>
#include<string>
#define N 2
using namespace std;
class Date {
public:
	Date(int y, int m, int d);
	void set(int y, int m, int d);
	void show();

private:
	int year;
	int month;
	int day;
};
Date::Date(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::set(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::show()
{
	cout << "���գ�" << year << "��" << month << "��" << day << "��" << endl;
}
class People {
public:
	People(int y = 2000, int m = 00, int d = 00, string i = "340321200000000000", string name = "����", string nu = "20000000000", char se = 'm');
	void set(int y = 2000, int m = 00, int d = 00, string i = "340321200000000000", string name = "����", string nu = "20000000000", char se = 'm');
	void show();
	//��Ա�������������
	int operator==(People a);
private:
	Date birthday;
	string id;//���֤��
	string name;
	string number;
	char sex;
};
People::People(int y, int m, int d, string i, string name, string nu, char se) :birthday(y, m, d)
{
	id = i;
	this->name = name;
	number = nu;
	sex = se;
}
void People::set(int y, int m, int d, string i, string name, string nu, char se)
{
	id = i;
	this->name = name;
	number = nu;
	sex = se;
	birthday.set(y, m, d);
}
void People::show()
{
	cout << "���֤�ţ�" << id << endl << "������" << name << endl << "��ţ�" << number << endl << "�Ա�" << sex << endl;
	birthday.show();
}
int People::operator==(People a) {
	if ((*this).id == a.id)return 1;
	return 0;
}
int main()
{
	People p[N];
	int y; int m; int d; string i1; string na; string nu; char se;//�����������ƵȲ��������ڴ���set����
	for (int i = 0; i < N; i++)
	{
		cout << "�������" << i + 1 << "λ��Ա��Ϣ��" << endl;
		cout << "���������գ�";
		cin >> y >> m >> d;
		cout << "���֤�ţ�";
		cin >> i1;
		cout << "������";
		cin >> na;
		cout << "��ţ�";
		cin >> nu;
		cout << "�Ա�";
		cin >> se;
		//		cin>>y>>m>>d>>i1>>na>>nu>>se;
		p[i].set(y, m, d, i1, na, nu, se);
		cout << "��" << i + 1 << "λ��Ա��Ϣ:" << endl;
		p[i].show();
	}
	if (p[0] == p[1])cout << "�������֤����ͬ" << endl;
	else cout << "�������֤�Ų�ͬ" << endl;

	return 0;
}