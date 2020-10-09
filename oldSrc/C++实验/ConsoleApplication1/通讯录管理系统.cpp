#include<iostream>
#include<string>
#define MAX 1000//通讯录的最大容量；
//test;
using namespace std;
//定义联系人类；
class Lxr
{
private:
	int tag;//tag表示当前存储单元状态，1表示被占用，0表示空闲；
	string name;
	int sex;
	int age;
	string tel;//手机号码
	string address;
public:
	//2、查找联系人，若找到返回其所在位置，找不到则返回-1；
	static int Find(Lxr* p, string s);
	//3、添加联系人，上限MAX名；
	static void Add(Lxr* p);
	//4、显示通讯录中的所有联系人；
	static void Showcontects(Lxr* p);
	//5、删除联系人；
	static void Delete(Lxr* p);
	//6、显示单个联系人;
	static void Showone(Lxr* p, int pl);
	//8、修改联系人信息；
	static void Modify(Lxr* p);
	//9、清空所有联系人(不需要清空数组，只需要将tag置零，做逻辑上的清空即可)；
	static void Clearall(Lxr* p);
	static int sort(Lxr p[]);
	static int sortByName(Lxr p[]);
	static int sortBytel(Lxr p[]);
};

int Total = 0;//通讯录中总人数；

//1、显示功能选择菜单；
void Showmenu()
{
	cout << "********************" << endl;
	cout << "***1、添加联系人****" << endl;
	cout << "***2、显示联系人****" << endl;
	cout << "***3、删除联系人****" << endl;
	cout << "***4、查找联系人****" << endl;
	cout << "***5、修改联系人****" << endl;
	cout << "***6、清空联系人****" << endl;
	cout << "***7、排序联系人****" << endl;
	cout << "***0、退出通讯录****" << endl;
	cout << "********************" << endl;
}

//2、查找联系人，若找到返回其所在位置，找不到则返回-1；
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

//3、添加联系人，上限MAX名；
void Lxr::Add(Lxr* p)
{
	if (Total == MAX)
	{
		cout << "Your contacts have been full! Cannot append to the list!" << endl;
	}
	else
	{
		int flag = 0, k = 0;//flag记录数组中最小的空闲位置，k表示当前数组单元占用状态；
		for (int i = 0; i < MAX; i++)
		{
			if (p[i].tag == 0)
			{
				flag = i;
				k = 1;//k为1表示占用当前数组单元；
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
				p[flag].tag = 1;//tag为1表示占用当前数组单元；
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
	//按任意键清屏；
	system("pause");
	system("cls");
}

//4、显示通讯录中的所有联系人；
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
	//按任意键清屏；
	system("pause");
	system("cls");
}

//5、删除联系人；
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
	//按任意键清屏；
	system("pause");
	system("cls");
}

//6、显示单个联系人；
void Lxr::Showone(Lxr* p, int pl)
{
	cout << "Name\t" << "Sex:\t" << "Age:\t" << "Tel:\t\t" << "Address:" << endl;
	cout << p[pl].name << "\t" << (p[pl].sex == 1 ? "Male" : "Female") << "\t"
		<< p[pl].age << "\t" << p[pl].tel << "\t\t" << p[pl].address << endl;
	//按任意键清屏；
	system("pause");
	system("cls");
}

//7、返回功能选择菜单
int confirmOperation()
{
	cout << "确认执行你所选的操作吗？y-yes,n-no" << endl;
	string b;
	cin >> b;
	if (b == "n")
	{
		//清屏
		system("cls");
		return 1;
	}
	else if (b == "y")
	{
		return 0;
	}
	return -1;
}

//8、修改联系人信息；
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
	//按任意键清屏；
	system("pause");
	system("cls");
}

//9、清空所有联系人(不需要清空数组，只需要将tag置零，做逻辑上的清空即可)；
void Lxr::Clearall(Lxr* p)
{
	for (int i = 0; i < MAX; i++)
	{
		p[i].tag = 0;
	}
	Total = 0;
	cout << "Succeed to clear the contects!" << endl;
	//按任意键清屏
	system("pause");
	system("cls");
}
//实现一个 冒泡排序(目录)
int Lxr::sort(Lxr* p)
{
	int key;//键盘输入操作号
	while (getchar() != '\n');                     //清空键盘缓冲区

	while (1)
	{
		system("cls");
		cout << "------------------" << endl;
		cout << "-----1.按手机号排序-----" << endl;
		cout << "-----2.按姓名排序-----" << endl;
		cout << "-----3.退出本菜单-----" << endl;
		cout << "------------------" << endl;
		cout << "请选择子菜单手机号:" << endl;
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
//实现一个 冒泡排序,按照手机号顺序排序
int Lxr::sortBytel(Lxr* p)
{
	Lxr temp;
	for (int i = 0; i < Total - 1; i++)//冒泡排序，按照拼音顺序排序
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
	cout << "排序后结果：" << endl;
	Showcontects(p);
	//	saveInformation(p, N);
	return 1;//排序成功返回
}
//实现一个 冒泡排序,按照拼音顺序排序
int Lxr::sortByName(Lxr p[])
{
	Lxr temp;
	for (int i = 0; i < Total - 1; i++)//冒泡排序，按照拼音顺序排序
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
	cout << "排序后结果：" << endl;

	Showcontects(p);
	//	Save(p, N);
	return 1;//排序成功返回
}

int main()
{
	int n;
	Lxr Info[MAX];//创建通讯录；
	while (1)
	{
		system("cls");
		Showmenu();
		cout << "Please input the service you need:" << endl;
		cin >> n;
		switch (n) {
		case 1://1、添加联系人
		{
			if (confirmOperation() == 1)break;
			Lxr::Add(Info);
			break;
		}

		case 2: //2、显示联系人
		{
			if (confirmOperation() == 1)break;
			Lxr::Showcontects(Info);
			break;
		}

		case 3://3、删除联系人
		{
			if (confirmOperation() == 1)break;
			Lxr::Delete(Info);
			break;
		}

		case 4://4、查找联系人
		{
			if (confirmOperation() == 1)break;
			cout << "please input the name:" << endl;
			string s;
			cin >> s;
			int f = Lxr::Find(Info, s);
			if (f == -1)
			{
				cout << "Cannot find the target! Please check again!" << endl;
				//按任意键清屏；
				system("pause");
				system("cls");
				break;
			}
			Lxr::Showone(Info, f);
			break;
		}
		case 5://5、修改联系人
		{
			if (confirmOperation() == 1)break;
			Lxr::Modify(Info);
			break;
		}
		case 6://6、清空联系人
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
//		Showmenu();//若不退出，则用户可以一直在功能选择界面进行选择；
//		cin >> n;
	}
	//	if (n == 0)cout << "Thanks! Welcome to your use next time!" << endl;
	system("pause");
	return 0;
}