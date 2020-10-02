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

class AverArray :public MyArray {
public:
	AverArray(int leng);
	void Aver();//��ƽ��ֵ
};
AverArray::AverArray(int leng) :MyArray(leng)
{
}
void AverArray::Aver()
{
	int* p = alist;
	float sum = 0;
	for (int i = 0; i < length; i++, p++)
		sum += *p;
	cout << "ƽ��ֵ��:" << sum / length << endl;
}

int main()
{
	AverArray a(5);
	a.Input();
	a.Display("��ʾ�������");
	a.Aver();
	return 0;
}