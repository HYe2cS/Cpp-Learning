//��дһ��ѧ���ͽ�ʦ�������������ʾ����ѧ�������б�š��������Ա����䡢ϵ��ͳɼ���
//��ʦ�����б�š��������Ա����䡢ְ�ƺͲ��š�Ҫ�󽫱�š��������Ա�������������ʾ��Ƴ�һ����Person������Ϊѧ����Student�ͽ�ʦ��Teacher�Ļ��ࡣ
#include<iostream>
#include<string>
using namespace std;
class Person {
public:

protected:
	string sno;
	string name;
	char sex;
	int age;
};
class Student :public Person {
public:
	void input()
	{
		cout << "������ѧ����Ϣ:" << endl;
		cout << "���:";
		cin >> sno;
		cout << "����:";
		cin >> name;
		cout << "�Ա�:";
		cin >> sex;
		cout << "����:";
		cin >> age;
		cout << "ϵ��:";
		cin >> xibie;
		cout << "�ɼ�:";
		cin >> score;
	}
	void output()
	{
		cout << "���:" << sno << endl << "����:" << name << endl
			<< "�Ա�:" << sex << endl << "����:" << age << endl << "ϵ��:" << xibie << endl << "�ɼ�:" << score << endl;
	}
private:
	string xibie;//ϵ��
	float score;//�ɼ�
};
class Teacher :public Person {
private:
	string major;//ְ��
	string bumeng;//����
public:
	void input()
	{
		cout << "�������ʦ��Ϣ:" << endl;
		cout << "���:";
		cin >> sno;
		cout << "����:";
		cin >> name;
		cout << "�Ա�:";
		cin >> sex;
		cout << "����:";
		cin >> age;
		cout << "ְ��:";
		cin >> major;
		cout << "����:";
		cin >> bumeng;
	}
	void output()
	{
		cout << "���:" << sno << endl << "����:" << name << endl
			<< "�Ա�:" << sex << endl << "����:" << age << endl << "ְ��:" << major << endl << "����:" << bumeng << endl;
	}
};
int main()
{
	int num;
	cout << "������ѧ������:";
	cin >> num;
	Student s1[num];
	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "λѧ����Ϣ:" << endl;
		s1[i].input();
	}

	for (int i = 0; i < num; i++)
	{
		cout << "��" << i + 1 << "λѧ����Ϣ:" << endl;
		s1[i].output();
	}

	cout << "�������ʦ����:";
	cin >> num;
	Teacher t2[num];
	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "λ��ʦ��Ϣ:" << endl;
		t2[i].input();
	}

	for (int i = 0; i < num; i++)
	{
		cout << "��" << i + 1 << "λ��ʦ��Ϣ:" << endl;
		t2[i].output();
	}

	return 0;
}