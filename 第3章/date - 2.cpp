//������ı�д�����������
//����Ĭ��ֵ�����캯��
//(*p).��ʽ ��p->��ʽ ʵ��
//�������顢����ָ��
#include<iostream>
using namespace std;
class Date {
public:
	Date(int y = 2000, int m = 1, int d = 1);
	void set(int y, int m, int d);
	void show();
	//		int getyear();
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
	cout << "�����ǣ�" << year << " �� " << month << " �� " << day << " �� " << endl;
}
int main()
{
	//��������
	Date date3[4] = { Date(2019,9,17),Date(2019,9,12),Date(2019,9,11) };
	for (int i = 0; i < 4; i++)
	{
		date3[i].show();
	}
	//����ָ��
	Date* p = date3;//date3��ʾ�����׵�ַ
	for (i = 0; i < 4; i++)
	{
		p->show();
		p++;
	}
	/*
		Date date1;
		date1.show();
		Date date2(2019,9,12);
		date2.show();
		//
		date1.set(2019,9,11);//��ͨ��ʽ
		date1.show();
		Date *p=&date1;
		(*p).set(2019,9,11);//(*p).��ʽ
		(*p).show();
		p->set(2019,9,11);//p->��ʽ
		p->show();
	*/
	return 0;
}