#include <iostream>
#include <string>
using namespace std;
class MyArray              //����һ������MyArray
{
public:
	MyArray(int leng);      //���캯��
	~MyArray();           //��������
	void Input();           //�������ݵĳ�Ա����
	void Display(string);    //��������ĳ�Ա����
protected:
	int* alist;             //�����д��һ������
	int length;            //�����ĸ���
};
MyArray::MyArray(int leng)
{
	if (leng <= 0)
	{
		cout << "error length";
		exit(1);
	}
	alist = new int[leng];
	length = leng;
	if (alist == NULL)
	{
		cout << "assign failure";
		exit(1);
	}
	cout << "MyArray������Ѵ�����" << endl;
}
MyArray::~MyArray()
{
	delete[] alist;
	cout << "MyArray����󱻳�����" << endl;
}

void MyArray::Input()
{
	cout << "��Ӽ�������" << length << "��������";
	int i;
	int* p = alist;
	for (i = 0; i < length; i++, p++)
		cin >> *p;
}

void MyArray::Display(string str)
{
	int i;
	int* p = alist;
	cout << str << length << "��������";
	for (i = 0; i < length; i++, p++)
		cout << *p << " ";
	cout << endl;
}
class SortArray :public MyArray {
public:
	SortArray(int leng) :MyArray(leng) {
	}
	void sort()
	{
		int i, j, t;
		for (j = 0; j < length - 1; j++)
		{
			for (i = 0; i < length - j - 1; i++)
			{
				if (alist[i] > alist[i + 1])
				{
					t = alist[i];
					alist[i] = alist[i + 1];
					alist[i + 1] = t;
				}
			}
		}
		cout << "�����Ϊ:";
		for (i = 0; i < length; i++)
		{
			cout << alist[i] << endl;
		}
	}
};

int main()
{
	SortArray b(5);
	b.Input();
	b.Display("��ʾ�������");
	b.sort();
	return 0;
}