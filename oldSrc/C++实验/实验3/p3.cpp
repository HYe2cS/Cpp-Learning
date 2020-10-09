﻿#include <iostream>
#include <string>
using namespace std;
class MyArray              //声明一个基类MyArray
{
public:
	MyArray(int leng);      //构造函数
	~MyArray();           //析构函数
	void Input();           //输入数据的成员函数
	void Display(string);    //输出函数的成员函数
protected:
	int* alist;             //基类中存放一组整数
	int length;            //整数的个数
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
	cout << "MyArray类对象已创建。" << endl;
}
MyArray::~MyArray()
{
	delete[] alist;
	cout << "MyArray类对象被撤销。" << endl;
}

void MyArray::Input()
{
	cout << "请从键盘输入" << length << "个整数：";
	int i;
	int* p = alist;
	for (i = 0; i < length; i++, p++)
		cin >> *p;
}

void MyArray::Display(string str)
{
	int i;
	int* p = alist;
	cout << str << length << "个整数：";
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
		cout << "排序后为:";
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
	b.Display("显示已输入的");
	b.sort();
	return 0;
}