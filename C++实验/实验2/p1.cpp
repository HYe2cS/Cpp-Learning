#include<iostream>
#include<string>
using namespace std;
class CPU {
public:
	CPU();
	~CPU();
	string GetRank();
	int GetFrequency();
	float GetVoltage();
	void SetRank(string r = "P0");
	void SetFrequency(int f = 0);
	void SetVoltage(float v = 0);
	void Run();
	void Stop();
private:
	string rank;//�ȼ�
	int frequency;//Ƶ��
	float voltage;//��ѹ
};
CPU::CPU()
{
	cout << "����һ��CPU" << endl;
}
CPU::~CPU()
{
	cout << "����һ��CPU" << endl;
}
string CPU::GetRank()
{
	return rank;
}
int CPU::GetFrequency()
{
	return frequency;
}
float CPU::GetVoltage()
{
	return voltage;
}
void CPU::SetRank(string r)
{
	rank = r;
}
void CPU::SetFrequency(int f)
{
	frequency = f;
}
void CPU::SetVoltage(float v)
{
	voltage = v;
}
void CPU::Run()
{
	cout << "CPU��ʼ���У�" << endl;
}
void CPU::Stop()
{
	cout << "CPUֹͣ���У�" << endl;
}

class Student {
public:
	void account(float s);
	static float sum();
	static float average();
private:
	float score;
	static float total_score;
	static int count;
};
void Student::account(float s)
{
	score = s;
	count++;
	total_score += s;
}
float Student::sum()
{
	return total_score;
}
float Student::average()
{
	return total_score / count;
}
float Student::total_score = 0;
int Student::count = 0;

class Car {
public:
	void Input();
	friend void Output(Car& x);
private:
	float speed;
	string color;
};
void Car::Input()
{
	cout << "�����복����ɫ:";
	cin >> color;
	cout << "�����복���ٶ�:";
	cin >> speed;
}
void  Output(Car& x)
{
	cout << "������ɫ��" << x.color << ",�����ٶ���" << x.speed << endl;
}

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
class Person {
public:
	Person(int y = 2000, int m = 00, int d = 00, string i = "20000000000", string na = "����", char se = 'm');
	void set(int y, int m, int d, string i, string na, char se);
	void show();
private:
	Date birthday;
	string id;
	string name;
	char sex;
};
Person::Person(int y, int m, int d, string i, string na, char se) :birthday(y, m, d)
{
	id = i;
	name = na;
	sex = se;
}
void Person::set(int y, int m, int d, string i, string na, char se)
{
	id = i;
	name = na;
	sex = se;
	birthday.set(y, m, d);
}
void Person::show()
{
	cout << "��ţ�" << id << endl << "������" << name << endl << "�Ա�" << sex << endl;
	birthday.show();
}
int main()
{
	/*
	CPU cpu1;
	cpu1.SetRank("P1");
	cpu1.SetFrequency(3000);
	cpu1.SetVoltage(220);
	cpu1.Run();
	cout<<"cpu1�ĵȼ��ǣ�"<<cpu1.GetRank()<<endl;
	cout<<"cpu1��Ƶ���ǣ�"<<cpu1.GetFrequency()<<endl;
	cout<<"cpu1�ĵ�ѹ�ǣ�"<<cpu1.GetVoltage()<<endl;
	cpu1.Stop();
	*/
	/*
	Student s[100];
	cout<<"�����뱾��ѧ������:";
	int n;
	cin>>n;
	float sc;
	for(int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��ѧ���ķ���:";
		cin>>sc;
		s[i].account(sc);
	}
	cout<<"ȫ����ܳɼ���:"<<Student::sum()<<endl;
	cout<<"ȫ���ƽ���ɼ���:"<<Student::average()<<endl;
	*/
	/*
	Car c1;
	c1.Input();
	Output(c1);
	*/
	Person p[100];
	cout << "��������Ա����:";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "����Ա��Ϣ:" << endl;
		int y; int m; int d; string id; string na; char se;
		cout << "��ţ�"; cin >> id;
		cout << "������"; cin >> na;
		cout << "�Ա�"; cin >> se;
		cout << "���գ�"; cin >> y >> m >> d;
		p[i].set(y, m, d, id, na, se);
	}
	for (int i = 0; i < n; i++)
	{
		if ((i / 5) == 0)cout << "=============================" << endl;
		p[i].show();
	}
	return 0;
}