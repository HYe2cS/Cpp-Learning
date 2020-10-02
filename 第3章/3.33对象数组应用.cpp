#include<iostream>
using namespace std;
class book {
public:
	book(int q = 0, int p = 0);
	void show();
private:
	int qu;
	int price;
};
book::book(int q, int p)
{
	qu = q;
	price = p;
}
void book::show()
{
	cout << qu * price << endl;
}

int main()
{
	//对象数组
	book b1[5] = { book(1,10),book(2,20),book(3,30),book(4,40),book(5,50) };
	for (int i = 0; i < 5; i++)
	{
		b1[i].show();
	}
	//对象指针
	book* p = &b1[4];
	for (i = 0; i < 5; i++)
	{
		p->show();
		p--;
	}

	return 0;
}