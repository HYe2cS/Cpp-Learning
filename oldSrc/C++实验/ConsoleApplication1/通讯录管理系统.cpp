#include<iostream>
#include<string>
#define MAX 1000//ͨѶ¼�����������
//test;
using namespace std;
//������ϵ���ࣻ
class Lxr
{
private:
	int tag;//tag��ʾ��ǰ�洢��Ԫ״̬��1��ʾ��ռ�ã�0��ʾ���У�
	string name;
	int sex;
	int age;
	string tel;//�ֻ�����
	string address;
public:
	//2��������ϵ�ˣ����ҵ�����������λ�ã��Ҳ����򷵻�-1��
	static int Find(Lxr* p, string s);
	//3�������ϵ�ˣ�����MAX����
	static void Add(Lxr* p);
	//4����ʾͨѶ¼�е�������ϵ�ˣ�
	static void Showcontects(Lxr* p);
	//5��ɾ����ϵ�ˣ�
	static void Delete(Lxr* p);
	//6����ʾ������ϵ��;
	static void Showone(Lxr* p, int pl);
	//8���޸���ϵ����Ϣ��
	static void Modify(Lxr* p);
	//9�����������ϵ��(����Ҫ������飬ֻ��Ҫ��tag���㣬���߼��ϵ���ռ���)��
	static void Clearall(Lxr* p);
	static int sort(Lxr p[]);
	static int sortByName(Lxr p[]);
	static int sortBytel(Lxr p[]);
};

int Total = 0;//ͨѶ¼����������

//1����ʾ����ѡ��˵���
void Showmenu()
{
	cout << "********************" << endl;
	cout << "***1�������ϵ��****" << endl;
	cout << "***2����ʾ��ϵ��****" << endl;
	cout << "***3��ɾ����ϵ��****" << endl;
	cout << "***4��������ϵ��****" << endl;
	cout << "***5���޸���ϵ��****" << endl;
	cout << "***6�������ϵ��****" << endl;
	cout << "***7��������ϵ��****" << endl;
	cout << "***0���˳�ͨѶ¼****" << endl;
	cout << "********************" << endl;
}

//2��������ϵ�ˣ����ҵ�����������λ�ã��Ҳ����򷵻�-1��
int Lxr::Find(Lxr* p, string s)
{
	int i, flag = 0;
	for (i = 0; i < MAX; i++)
	{
		if (p[i].name == s)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return i;
	else
		return -1;
}

//3�������ϵ�ˣ�����MAX����
void Lxr::Add(Lxr* p)
{
	if (Total == MAX)
	{
		cout << "Your contacts have been full! Cannot append to the list!" << endl;
	}
	else
	{
		int flag = 0, k = 0;//flag��¼��������С�Ŀ���λ�ã�k��ʾ��ǰ���鵥Ԫռ��״̬��
		for (int i = 0; i < MAX; i++)
		{
			if (p[i].tag == 0)
			{
				flag = i;
				k = 1;//kΪ1��ʾռ�õ�ǰ���鵥Ԫ��
				break;
			}
		}
		if (k == 1)
		{
			cout << "Please input the name:";
			cin >> p[flag].name;
			int f = Find(p, p[flag].name);
			if (f != -1 && p[f].tag == 1)
			{
				cout << "Find repeated record! Cannot input!" << endl;
			}
			else
			{
				p[flag].tag = 1;//tagΪ1��ʾռ�õ�ǰ���鵥Ԫ��
				cout << "sex(male is 1 and female is 2):";
				cin >> p[flag].sex;
				while (1)
				{
					if (p[flag].sex == 1 || p[flag].sex == 2)
						break;
					else
					{
						cout << "Wrong form! Please input again!" << endl;
						cin >> p[flag].sex;
					}
				}
				cout << "age:";
				cin >> p[flag].age;
				cout << "tel nember:";
				cin >> p[flag].tel;
				cout << "address:";
				cin >> p[flag].address;
				cout << "Succeed!" << endl;
				Total++;
			}
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//4����ʾͨѶ¼�е�������ϵ�ˣ�
void Lxr::Showcontects(Lxr* p)
{
	if (Total == 0)
	{
		cout << "The contects is empty!" << endl;
	}
	else
	{
		cout << "Name\t" << "Sex:\t" << "Age:\t" << "Tel:\t\t" << "Address:" << endl;
		for (int i = 0; i < MAX; i++)
		{
			if (p[i].tag == 1)
			{
				cout << p[i].name << "\t" << (p[i].sex == 1 ? "Male" : "Female")
					<< "\t" << p[i].age << "\t" << p[i].tel << "\t\t"
					<< p[i].address << endl;
			}
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//5��ɾ����ϵ�ˣ�
void Lxr::Delete(Lxr* p)
{
	cout << "Please input the name:" << endl;
	string k;
	cin >> k;
	int f = Find(p, k);
	if (f == -1)
	{
		cout << "Cannot find the target! Please check again!" << endl;
	}
	else
	{
		p[f].tag = 0;
		Total--;
		cout << "Succeed in deleting the record!" << endl;
	}
	//�������������
	system("pause");
	system("cls");
}

//6����ʾ������ϵ�ˣ�
void Lxr::Showone(Lxr* p, int pl)
{
	cout << "Name\t" << "Sex:\t" << "Age:\t" << "Tel:\t\t" << "Address:" << endl;
	cout << p[pl].name << "\t" << (p[pl].sex == 1 ? "Male" : "Female") << "\t"
		<< p[pl].age << "\t" << p[pl].tel << "\t\t" << p[pl].address << endl;
	//�������������
	system("pause");
	system("cls");
}

//7�����ع���ѡ��˵�
int confirmOperation()
{
	cout << "ȷ��ִ������ѡ�Ĳ�����y-yes,n-no" << endl;
	string b;
	cin >> b;
	if (b == "n")
	{
		//����
		system("cls");
		return 1;
	}
	else if (b == "y")
	{
		return 0;
	}
	return -1;
}

//8���޸���ϵ����Ϣ��
void Lxr::Modify(Lxr* p)
{
	cout << "Please input the name of the target:" << endl;
	string n;
	cin >> n;
	int f = Find(p, n);
	while (f == -1)
	{
		cout << "Cannot find the target! Please input the name of the target again:" << endl;
		cin >> n;
		f = Find(p, n);
	}
	if (f != -1)
	{
		cout << "input the new name:";
		cin >> p[f].name;
		cout << "input the sex(male is 1 and female is 2):";
		cin >> p[f].sex;
		cout << "input the age:";
		cin >> p[f].age;
		cout << "input the tel tel:";
		cin >> p[f].tel;
		cout << "input the address:";
		cin >> p[f].address;
	}
	//�������������
	system("pause");
	system("cls");
}

//9�����������ϵ��(����Ҫ������飬ֻ��Ҫ��tag���㣬���߼��ϵ���ռ���)��
void Lxr::Clearall(Lxr* p)
{
	for (int i = 0; i < MAX; i++)
	{
		p[i].tag = 0;
	}
	Total = 0;
	cout << "Succeed to clear the contects!" << endl;
	//�����������
	system("pause");
	system("cls");
}
//ʵ��һ�� ð������(Ŀ¼)
int Lxr::sort(Lxr* p)
{
	int key;//�������������
	while (getchar() != '\n');                     //��ռ��̻�����

	while (1)
	{
		system("cls");
		cout << "------------------" << endl;
		cout << "-----1.���ֻ�������-----" << endl;
		cout << "-----2.����������-----" << endl;
		cout << "-----3.�˳����˵�-----" << endl;
		cout << "------------------" << endl;
		cout << "��ѡ���Ӳ˵��ֻ���:" << endl;
		cin >> key;
		switch (key)
		{
		case 1:sortBytel(p); break;
		case 2:sortByName(p); break;
		case 3:return 0;
		default:break;
		}
	}
}
//ʵ��һ�� ð������,�����ֻ���˳������
int Lxr::sortBytel(Lxr* p)
{
	Lxr temp;
	for (int i = 0; i < Total - 1; i++)//ð�����򣬰���ƴ��˳������
	{
		int mint = i;
		for (int j = i + 1; j < Total; j++)
		{
			if (p[j].tel < p[mint].tel)mint = j;
		}
		if (mint != i)
		{
			temp = p[i]; p[i] = p[mint]; p[mint] = temp;
		}
	}
	cout << "���������" << endl;
	Showcontects(p);
	//	saveInformation(p, N);
	return 1;//����ɹ�����
}
//ʵ��һ�� ð������,����ƴ��˳������
int Lxr::sortByName(Lxr p[])
{
	Lxr temp;
	for (int i = 0; i < Total - 1; i++)//ð�����򣬰���ƴ��˳������
	{
		int mint = i;
		for (int j = i + 1; j < Total; j++)
		{
			if (p[j].name < p[mint].name)mint = j;
		}
		if (mint != i)
		{
			temp = p[i]; p[i] = p[mint]; p[mint] = temp;
		}
	}
	cout << "���������" << endl;

	Showcontects(p);
	//	Save(p, N);
	return 1;//����ɹ�����
}

int main()
{
	int n;
	Lxr Info[MAX];//����ͨѶ¼��
	while (1)
	{
		system("cls");
		Showmenu();
		cout << "Please input the service you need:" << endl;
		cin >> n;
		switch (n) {
		case 1://1�������ϵ��
		{
			if (confirmOperation() == 1)break;
			Lxr::Add(Info);
			break;
		}

		case 2: //2����ʾ��ϵ��
		{
			if (confirmOperation() == 1)break;
			Lxr::Showcontects(Info);
			break;
		}

		case 3://3��ɾ����ϵ��
		{
			if (confirmOperation() == 1)break;
			Lxr::Delete(Info);
			break;
		}

		case 4://4��������ϵ��
		{
			if (confirmOperation() == 1)break;
			cout << "please input the name:" << endl;
			string s;
			cin >> s;
			int f = Lxr::Find(Info, s);
			if (f == -1)
			{
				cout << "Cannot find the target! Please check again!" << endl;
				//�������������
				system("pause");
				system("cls");
				break;
			}
			Lxr::Showone(Info, f);
			break;
		}
		case 5://5���޸���ϵ��
		{
			if (confirmOperation() == 1)break;
			Lxr::Modify(Info);
			break;
		}
		case 6://6�������ϵ��
		{
			if (confirmOperation() == 1)break;
			Lxr::Clearall(Info);
			break;
		}
		case 7:
		{
			if (confirmOperation() == 1)break;
			Lxr::sort(Info);
			break;
		}
		case 0:
		{
			cout << "Thanks! Welcome to your use next time!" << endl;
			return 0;
		}
		}
		//		cout << "Please input the service you need:" << endl;
//		Showmenu();//�����˳������û�����һֱ�ڹ���ѡ��������ѡ��
//		cin >> n;
	}
	//	if (n == 0)cout << "Thanks! Welcome to your use next time!" << endl;
	system("pause");
	return 0;
}