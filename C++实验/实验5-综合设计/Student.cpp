#include<iostream>
#include<string>
#include<fstream>
#include<io.h>
//��Ԫ�ڣ����򣬲��� preTop���� printInfor���� ,Student���Ա������������д�淶�ƶ�
using namespace std;
class Date {
public:
	Date(int y, int m, int d);
	void set(int y, int m, int d);
	void show();
	int getyear() { return year; }
	int getmonth() { return month; }
	int getday() { return day; }
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
	cout << year << "��" << month << "��" << day << "��";
}
class Student {
public:
	Student(int y = 2000, int m = 00, int d = 00,
		string name = "����",
		string id = "340321200000000000",
		string number = "20000000000",
		string sex = "��",
		float chinese = 0,
		float math = 0,
		float english = 0);
	void set(int y = 2000, int m = 00, int d = 00,
		string name = "����",
		string id = "340321200000000000",
		string number = "20000000000",
		string sex = "��",
		float chinese = 0,
		float math = 0,
		float english = 0);
	void show();

	//ʵ��һ����ȡ�ļ����溯��,
	static void readInformation(Student stu[], int& N);
	static void saveInformation(Student stu[], int& N);
	static void preMenu();
	static void preTop();//���ʱ�Ľ���ͷ��

	//ʵ��һ������������(add)���(printInfor)����
	static void addInfor(Student stu[], int& N);
	static void printInfor(Student stu[], int N);

	//ʵ��һ�� ð������,�ֱ���ѧ�š������͸���ƽ����˳������
	static int sort(Student stu[], int& N);
	static int sortByNumber(Student stu[], int& N);
	static int sortByName(Student stu[], int& N);

	//ʵ��һ��������Ĳ��Һ���
	static int search(Student stu[], int N);
	static int searchByNumber(Student stu[], int N);
	static int searchByName(Student stu[], int N);

	static int edit(Student stu[], int& N);
	static int del(Student stu[], int& N);

private:
	Date birthday;//����
	string name;//����
	string id;//���֤��
	string number; //ѧ��
	string sex;//�Ա�
	float chinese;//���ĳɼ�
	float math;//��ѧ�ɼ�
	float english;//Ӣ��ɼ�
};
Student::Student(int y, int m, int d,
	string name,
	string id,
	string number,
	string sex,
	float chinese,
	float math,
	float english) :birthday(y, m, d)
{
	this->name = name;
	this->id = id;
	this->number = number;
	this->sex = sex;
	this->chinese = chinese;
	this->math = math;
	this->english = english;
}
void Student::set(int y, int m, int d,
	string name,
	string id,
	string number,
	string sex,
	float chinese,
	float math,
	float english)
{
	birthday.set(y, m, d);
	this->name = name;
	this->id = id;
	this->number = number;
	this->sex = sex;
	this->chinese = chinese;
	this->math = math;
	this->english = english;
}
void Student::show()
{
	cout << name
		<< "\t" << id
		<< "\t" << number
		<< "\t";
	birthday.show();
	cout << "\t" << sex
		<< "\t" << chinese
		<< "\t" << math
		<< "\t" << english << endl;
}
inline void Student::preTop()
{
	cout << "����\t"
		<< "���֤��\t\t"
		<< "ѧ��\t\t"
		<< "����������\t"
		<< "�Ա�\t"
		<< "����\t"
		<< "��ѧ\t"
		<< "Ӣ��" << endl;
}

inline void Student::preMenu()
{
	cout << "                   ��ӭʹ��ѧ����Ϣ����ϵͳ" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "                       1.��ʾѧ����Ϣ" << endl;
	cout << "                       2.���ѧ����Ϣ" << endl;
	cout << "                       3.ɾ��ѧ����Ϣ" << endl;
	cout << "                       4.��ѯѧ����Ϣ" << endl;
	cout << "                       5.�޸�ѧ����Ϣ" << endl;
	cout << "                       6.����ѧ����Ϣ" << endl;
	cout << "                       7.�˳�ϵͳ" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "��ѡ��:" << endl;
}

void Student::readInformation(Student stu[], int& N)//û���
{
	char dir[] = { "TEST.txt" };
	if (_access(dir, 0) == -1) {//���û���ļ�,�����ļ�
		fstream iofile(dir, ios::out);
		if (!iofile)
		{
			cout << "�����ļ�ʧ�ܣ�" << "TEST.txt" << endl;
			exit(1);//ʧ���˻ز���ϵͳ
		}
		iofile << 0;
		N = 0;
		iofile.close();
	}
	else {//���ļ�
		fstream iofile(dir, ios::in);
		if (!iofile)//������ܴ�
		{
			cout << "���ܴ�" << endl;
			exit(1);//ʧ���˻ز���ϵͳ
		}
		iofile >> N; //��ͼȥ��һ���ַ�
		while (!iofile.eof()) //��ʾ�ļ���Ϊ��
		{
			if (!N) {
				N = 0; break;
			}
			for (int i = 0; i < N; i++)
			{
				int year, month, day;
				iofile >> stu[i].name
					>> stu[i].id
					>> stu[i].number
					>> year
					>> month
					>> day
					>> stu[i].sex
					>> stu[i].chinese
					>> stu[i].math
					>> stu[i].english;
				stu[i].birthday.set(year, month, day);
			}
		}
		iofile.close();
	}
}

void Student::saveInformation(Student stu[], int& N)//û���
{
	fstream iofile("TEST.txt", ios::out);
	if (!iofile)
	{
		cout << "���ļ�ʧ�ܣ�" << "TEST.txt" << endl;
		exit(1);//ʧ���˻ز���ϵͳ
	}
	iofile << N;
	for (int i = 0; i < N; i++)
	{
		iofile << stu[i].name
			<< " " << stu[i].id
			<< " " << stu[i].number
			<< " " << stu[i].birthday.getyear()
			<< " " << stu[i].birthday.getmonth()
			<< " " << stu[i].birthday.getday()
			<< " " << stu[i].sex
			<< " " << stu[i].chinese
			<< " " << stu[i].math
			<< " " << stu[i].english << endl;
	}
	iofile.close();
}

//ʵ��һ������������(add)����
void Student::addInfor(Student stu[], int& N)
{
	int k;
	int j = 1;//����ڶ���λ��Ϣ

	int year;
	int month;
	int day;
	string name;//����
	string id;//���֤��
	string number; //ѧ��
	string sex;//�Ա�
	float chinese;//���ĳɼ�
	float math;//��ѧ�ɼ�
	float english;//Ӣ��ɼ�

	cout << "Ҫ��ӵ�����(����)��";
	while (getchar() != '\n');                     //��ռ��̻�����
	cin >> k;//��������
	for (int i = N; i < N + k; i++)
	{
		cout << "�������" << j << "λ��Ա��Ϣ��" << endl;
		j++;
		cout << "������";
		cin >> name;
		cout << "���֤�ţ�";
		cin >> id;
		cout << "ѧ�ţ�";
		cin >> number;
		cout << "���������գ�";
		cin >> year >> month >> day;
		cout << "�Ա�";
		cin >> sex;
		cout << "���ģ�";
		cin >> chinese;
		cout << "��ѧ��";
		cin >> math;
		cout << "Ӣ�";
		cin >> english;
		stu[i].set(year, month, day, name, id, number, sex, chinese, math, english);
		cout << "��" << j << "λ��Ա��Ϣ:" << endl;
		preTop();
		stu[i].show();
	}
	N = N + k;
	saveInformation(stu, N);
}
//ʵ��һ������������(printInfor)����
void Student::printInfor(Student stu[], int N)
{
	if (N)preTop();
	for (int i = 0; i < N; i++)
	{
		stu[i].show();
	}

	cout << "ȫ��������!" << endl;
	system("pause");
}
//ʵ��һ�� ð������(Ŀ¼)
int Student::sort(Student stu[], int& N)
{
	int key;//�������������
	while (getchar() != '\n');                     //��ռ��̻�����

	while (1)
	{
		system("cls");
		cout << "------------------" << endl;
		cout << "-----1.��ѧ������-----" << endl;
		cout << "-----2.����������-----" << endl;
		cout << "-----3.�˳����˵�-----" << endl;
		cout << "------------------" << endl;
		cout << "��ѡ���Ӳ˵�ѧ��:" << endl;
		cin >> key;
		switch (key)
		{
		case 1:sortByNumber(stu, N); break;
		case 2:sortByName(stu, N); break;
		case 3:return 0;
		default:break;
		}
	}
}
//ʵ��һ�� ð������,����ѧ��˳������
int Student::sortByNumber(Student stu[], int& N)
{
	Student temp;
	for (int i = 0; i < N - 1; i++)//ð�����򣬰���ƴ��˳������
	{
		int mint = i;
		for (int j = i + 1; j < N; j++)
		{
			if (stu[j].number < stu[mint].number)mint = j;
		}
		if (mint != i)
		{
			temp = stu[i]; stu[i] = stu[mint]; stu[mint] = temp;
		}
	}
	cout << "���������" << endl;
	//	preTop();
	printInfor(stu, N);
	saveInformation(stu, N);
	return 1;//����ɹ�����
}
//ʵ��һ�� ð������,����ƴ��˳������
int Student::sortByName(Student stu[], int& N)
{
	Student temp;
	for (int i = 0; i < N - 1; i++)//ð�����򣬰���ƴ��˳������
	{
		int mint = i;
		for (int j = i + 1; j < N; j++)
		{
			if (stu[j].name < stu[mint].name)mint = j;
		}
		if (mint != i)
		{
			temp = stu[i]; stu[i] = stu[mint]; stu[mint] = temp;
		}
	}
	cout << "���������" << endl;
	//	preTop();
	printInfor(stu, N);
	saveInformation(stu, N);
	return 1;//����ɹ�����
}

//ʵ��һ��������Ĳ��Һ���(Ŀ¼)
int Student::search(Student stu[], int N)
{
	int key;//�������������
	while (getchar() != '\n');                     //��ռ��̻�����

	while (1)
	{
		system("cls");
		cout << "------------------" << endl;
		cout << "-----1.��ѧ�Ų�ѯ-----" << endl;
		cout << "-----2.��������ѯ-----" << endl;
		cout << "-----3.�˳����˵�-----" << endl;
		cout << "------------------" << endl;
		cout << "��ѡ���Ӳ˵�ѧ��:" << endl;
		cin >> key;
		switch (key)
		{
		case 1:cout << "������Ҫ����ѧ����ѧ��:" << endl; searchByNumber(stu, N); break;
		case 2:cout << "������Ҫ����ѧ����������" << endl; searchByName(stu, N); break;
		case 3:return 0;
		default:break;
		}
	}
}

//ʵ��һ��������Ĳ��Һ���(ͨ��ѧ��)
int Student::searchByNumber(Student stu[], int N)
{
	string number;//������������
	int result;//�����������
	while (getchar() != '\n');                     //��ռ��̻�����
	cin >> number;
	result = -1;
	for (int i = 0; i < N; i++)
	{
		if (number == stu[i].number)
		{
			result = i;
			break;
		}
	}

	if (result == -1)
	{//û�ҵ�������Ϣ
		cout << "û���ҵ��ø�����Ϣ��" << endl;
		system("pause");
		return -1;
	}
	else //�ҵ��˸�����Ϣ��show����
	{
		preTop();//���溯��
		stu[result].show();
		system("pause");
		return result;
	}
}

//ʵ��һ��������Ĳ��Һ���(ͨ������)
int Student::searchByName(Student stu[], int N)
{
	string name;//������������
	int result;//�����������

	while (getchar() != '\n');                     //��ռ��̻�����
	cin >> name;
	result = -1;
	for (int i = 0; i < N; i++)
	{
		if (name == stu[i].name)
		{
			result = i;
			break;
		}
	}

	if (result == -1)
	{//û�ҵ�������Ϣ
		cout << "û���ҵ��ø�����Ϣ��" << endl;
		system("pause");
		return -1;
	}
	else //�ҵ��˸�����Ϣ��show����
	{
		preTop();//���溯��
		stu[result].show();
		system("pause");
		return result;
	}
}

//ʵ��һ��������ı༭����
int Student::edit(Student stu[], int& N)
{
	int result;//�������
	char key; //key����������������
	int year;
	int month;
	int day;
	string name;//����
	string id;//���֤��
	string number; //ѧ��
	string sex;//�Ա�
	float chinese;//���ĳɼ�
	float math;//��ѧ�ɼ�
	float english;//Ӣ��ɼ�
	cout << "��������Ҫ�༭ѧ����������" << endl;
	result = searchByName(stu, N);
	if (result >= 0)
	{
		system("cls");
		printf("��ȷ��Ҫ�޸���?y-yes,n-no\n");
		while (getchar() != '\n');                     //��ռ��̻�����
		cin >> key;
		if (key == 'y')
		{
			cout << "����������ø�����Ϣ��" << endl;
			cout << "������";
			cin >> name;
			cout << "���֤�ţ�";
			cin >> id;
			cout << "ѧ�ţ�";
			cin >> number;
			cout << "���������գ�";
			cin >> year >> month >> day;
			cout << "�Ա�";
			cin >> sex;
			cout << "���ģ�";
			cin >> chinese;
			cout << "��ѧ��";
			cin >> math;
			cout << "Ӣ�";
			cin >> english;
			stu[result].set(year, month, day, name, id, number, sex, chinese, math, english);
			cout << "�޸���ɣ��������:" << endl;
			preTop();
			stu[result].show();
			saveInformation(stu, N);
			return 1;
		}
	}
	return 0;
}
//ʵ��һ���������ɾ������
int Student::del(Student stu[], int& N)
{
	int j;
	int  flag = 0;//�Ƿ�ɾ���ɹ��ı�־
	string s1;
	cout << "������Ҫɾ��ѧ��������:";
	cin >> s1;
	for (int i = 0; i < N; i++)
		if (stu[i].name == s1)
		{
			flag = 1;
			for (j = i; j < N - 1; j++)
				stu[j] = stu[j + 1];
		}
	if (flag == 0)
		cout << "��ѧ�������ڣ�" << endl;
	if (flag == 1)
	{
		cout << "ɾ���ɹ�,��ʾ�����ѡ��˵�\n" << endl;
		N--;
		saveInformation(stu, N);
	}
	system("pause");
	return 1;//ɾ���ɹ�����1
}
//int Student::count =0;
int main()
{
	Student stu[100];
	int N = 0;
	while (1)
	{
		system("cls");
		Student::readInformation(stu, N);
		Student::preMenu();
		int key;//key�洢��������Ĳ�����
		cin >> key;
		switch (key)
		{
		case 1:Student::printInfor(stu, N); break;
		case 2:Student::addInfor(stu, N); break;
		case 3:Student::del(stu, N); break;
		case 4:Student::search(stu, N); break;
		case 5:Student::edit(stu, N); break;
		case 6:Student::sort(stu, N); break;
		case 7:return 0;
		default:break;
		}
	}

	return 0;
}